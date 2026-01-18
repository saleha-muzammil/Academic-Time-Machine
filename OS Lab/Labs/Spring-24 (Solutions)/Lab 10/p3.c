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

    sem_wait(sem3);
    int fdRead=open("file.txt", O_RDONLY);
    if (fdRead==-1){
        return 2;
    }
    char buffer[1000];
    int bytesRead=read(fdRead, buffer, 1000);
    // printf("%s\n", buffer);
    char* num;
    int prev=0, prevprev=0;
    //tokenize and update count
    num=strtok(buffer, " ");
    prev=atoi(num);
    //when the loop ends it will be holding two numbers: 1-sum, 2-count
    while (num!=NULL){
        // printf("%d %d\n", prevprev, prev);
        num=strtok(NULL, " ");
        if (num!=NULL){
            prevprev=prev;
            prev=atoi(num);
        }
    }
    close(fdRead);
    printf("The sum is: %d.\nThe count is: %d.\n", prevprev, prev);
    printf("The average is: %.2f.\n", (float)prevprev/(float)prev);

    sem_post(sem3);
    //closes the sems for the process
    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);
    //removes the named sempahores from the system
    sem_unlink(sem1Name);
    sem_unlink(sem2Name);
    sem_unlink(sem3Name);

    return 0;
}
