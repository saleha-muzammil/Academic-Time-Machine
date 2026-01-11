#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>

int main(){
    //shared semaphores
    char sem1Name[]="sem1";
    char sem2Name[]="sem2";
    char sem3Name[]="sem3";
    sem_t* sem1, *sem2, *sem3;
    //opens exisitng semaphores
    sem1=sem_open(sem1Name, 0); 
    sem2=sem_open(sem2Name, 0); 
    sem3=sem_open(sem3Name, 0); 
    sem_wait(sem1);
    //read the numbers from the file
    int fdRead=open("file.txt", O_RDONLY);
    if (fdRead==-1){
        return 2;
    }
    char buffer[1000];
    int bytesRead=read(fdRead, buffer, 1000);
    char* num;
    int sum=0;
    //tokenize and update sum
    num=strtok(buffer, " ");
    while (num!=NULL){
        sum+=atoi(num);
        num=strtok(NULL, " ");
    }
    close(fdRead);
    char sumString[50]; 
    sprintf(sumString, "%d ", sum);
    //write onto the file
    int fdWrite=open("file.txt", O_WRONLY|O_APPEND);
    int bytesWritten=write(fdWrite, sumString, strlen(sumString)*sizeof(char));
    close(fdWrite);
    sem_post(sem1);
    sem_post(sem2); //sends signal to sem2 so p2 begins work

    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);
    return 0;
}
