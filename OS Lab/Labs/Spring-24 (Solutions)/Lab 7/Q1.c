#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt, mutex;
int readCount=0, count=1;

void start_write(int* val){
    int fd=open("tmp.txt", O_RDWR);
    if (write(fd, val, sizeof(int))==-1){
        printf("Unable to print!\n");
    }
    else{
        printf("Writer %d wrote succesfully.\n", &val);
    }
    close(fd);
}


void end_write(int* val){
    count++;
    printf("Writer %d exiting writing.\n", &val);
    sleep(1);
}


void start_read(){
    int fd=open("tmp.txt", O_RDONLY);
    int a;
    if (read(fd, &a, sizeof(int))==-1){
        printf("Unable to read!\n");
    }
    else{
        printf("Reader read succesfully.\n");
    }
    close(fd);
}


void end_read(){
    printf("Reader exiting Reading.\n");
    sleep((rand()%2)+1);
}


void* writer(void* arg){
    int* a=(int*)arg;
    sem_wait(&wrt);
    //critical section
    start_write(a);
    end_write(a);
    sem_post(&wrt);
    free(a);
}


void* reader(void*){
    sem_wait(&mutex);
    //CS
    readCount++;
    if (readCount==1){ 
        sem_wait(&wrt); //if even one reader then cannot read
    }
    sem_post(&mutex);
    start_read();
    end_read();
    sem_wait(&mutex);
    //CS
    readCount--;
    if (readCount==0){
        sem_post(&wrt); //if no readers left, signal the writer
    }
    sem_post(&mutex);
}


int main(){
    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);
    setvbuf(stdout, NULL, _IONBF, 0);
    while (1){
        sleep(rand()%2); 
        int seed=rand()%2; //generates either 0 or 1
        if (seed==0){
            //writer
            pthread_t tid;
            int* a=(int*)calloc(1, sizeof(int));
            *a=count;
            pthread_create(&tid, NULL, writer, a);
        }
        else{
            //reader
            pthread_t tid;
            pthread_create(&tid, NULL, reader, NULL);
        }
    }
    return 0;
}
