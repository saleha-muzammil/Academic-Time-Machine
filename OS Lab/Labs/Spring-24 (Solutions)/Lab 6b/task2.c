#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


void* printThread(void* arg){
    printf("Hello, I have thread ID = %lu.\n", (unsigned long)(pthread_self()));
    pthread_exit(0);
}


int main(int argc, char* argv[]){
    if (argc<2){
        return 2;
    }
    int numThreads=atoi(argv[1]);
    if (numThreads==0){
        return 3;
    }
    pthread_t threadArr[numThreads];
    for (int i=0;i<numThreads;i++){
        if ((i+1)%4==0){
            sleep(2);
        }
        pthread_create(&threadArr[i], NULL, printThread, NULL);
    }
    for (int i=0;i<numThreads;i++){
        pthread_join(threadArr[i], NULL);
    }
    printf("All threads exited.\n");
    return 0;
}