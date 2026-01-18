#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

int main(){
    char semm1Name[]="sem1";
    char semm2Name[]="sem2";
    char semm3Name[]="sem3";
    sem_t* sem1, sem2, sem3;
    sem1=sem_open(semm1Name, O_CREAT, 0644, 1); 
    sem2=sem_open(semm2Name, O_CREAT, 0644, 0); 
    sem3=sem_open(semm3Name, O_CREAT, 0644, 0); 

    char* fileName="file.txt";
    char arr[]={"10 20 30 40 50 60 "};
    int size=sizeof(arr)/sizeof(char);
    int fd=open(fileName, O_CREAT|O_WRONLY, 0777);
    int bytesWritten=write(fd, arr, size*sizeof(char)-1);
    close(fd);

    return 0;
}
