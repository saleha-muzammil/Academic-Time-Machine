#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/shm.h>    
#include <sys/ipc.h>
#include <string.h>

#define key 99999

int main(){
    int shmid=shmget(key, 1024, 0); //pass 0 as last arguement as already created shm
    if (shmid==-1){
        printf("Unable to open the shared memory.\n");
        return 2;
    }
    void* shmaddr=shmat(shmid, NULL, 0);
    if (shmaddr==NULL){
        printf("Unable to attatch the shared memory.\n");
        return 2;
    }
    char buffer[1024];
    strncpy(buffer, shmaddr, 1024);
    // printf("The data read is %s.\n", buffer);

    //tokenizing the string and storing in num arr
    char* ptr=strtok(buffer, " ");
    int num[100];
    int sum=0;
    int i=0;
    while (ptr!=NULL){
        num[i]=atoi(ptr);
        sum+=num[i++];
        ptr=strtok(NULL, " ");
    }
    if (shmdt(shmaddr)==-1){
        printf("Unable to detatch the shared memory.\n");
        return 2;
    }

    printf("The numbers are:\n");
    for (int j=0;j<i;j++){
        printf("%d ", num[j]);
    }
    printf("\nThe sum is %d.\nThe average is: %.2f", sum, (float)sum/i);

    return 0;
}