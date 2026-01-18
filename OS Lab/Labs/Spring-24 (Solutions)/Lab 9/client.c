#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/shm.h>    
#include <sys/ipc.h>
#include <string.h>

#define key 99999

int main(int argc, char* argv[]){
    if (argc<=1){
        printf("No file arguement passed.\n");
        return 2;
    }
    int shmid=shmget(key, 1024, 0666|IPC_CREAT|IPC_EXCL); //the flags passed are for creation of shared mem
    if (shmid==-1){
        printf("Unable to create a shared memory.\n");
        return 2;
    }
    void* shmaddr=shmat(shmid, NULL, 0); //auto determine address by OS
    if (shmaddr==NULL){
        printf("Unable to attatch the shared memory.\n");
        return 2;
    }
    //reading the data from the file
    int fd=open(argv[1], O_RDONLY);
    char arr[1024];
    int bytesRead=read(fd, arr, 1024*sizeof(char));
    strncpy(shmaddr, arr, strlen(arr));
    
    sleep(10); //wait for some time before detatching the mem and unlinking
    if (shmdt(shmaddr)==-1){
        printf("Unable to detatch the shared memory.\n");
        return 2;
    }
    if (shmctl(shmid, IPC_RMID, NULL)==-1){
        printf("Unable to delete the shared memory.\n");
    }

    return 0;
}