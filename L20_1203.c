#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



void* thread1(void* args ){
    int i=0;
    int* ptr=(int *)args;
    for (i;i<50;i++){
        if (ptr[i]>='0'&&ptr[i]<='9'){
            
        }
    }
}

int main(int argc, char** argv){
    if (argc!=2){
        fputs(stderr, "Invalid number of arguments\n");
    }
    char* filename=argv[1];
    int fd=open(filename, "r");
    pthread_t *t1, *t2;
    int *arr=malloc(100);
    pthread_create(&t1, NULL, thread1, (void *)arr);
    pthread_create(&t2, NULL, thread1, (void *)(arr+50));

    
}
    

