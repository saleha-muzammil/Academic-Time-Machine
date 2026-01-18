#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<pthread.h>

#define PAGESIZE 4096

void* threadReverseCase(void* arg){
    char* buff=(char*)arg; //typecasting to char array as we stored the content as chars
    for (int i=0;i<50;i++){
        if (buff[i]>='a' && buff[i]<='z'){
            buff[i]-=32;
        }
        else if (buff[i]>='A' && buff[i]<='Z'){
            buff[i]+=32;
        }
    }
    pthread_exit(0);
}

int main(int argc, char* argv[]){
    if (argc<=1){
        printf("No cmd arguement passed.\n");
        return 2;
    }
    int fd=open(argv[1], O_RDWR);
    void* buffer=mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); //init memory region with file contents
    close(fd); //may close the fd after using mmap, will not cause any issues
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, threadReverseCase, (void*)(buffer));
    pthread_create(&tid2, NULL, threadReverseCase, (void*)(buffer+50)); //next 50 bytes for threadFunction to process
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("The contents of the file have been updated via memory mapping.\n");
    munmap(buffer, PAGESIZE); //free the memory

    return 0;
}