#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

#define totalComputers 10
sem_t computers;
int count=0;


void* accessLabComp(void* arg){
    int* a=(int*)arg;
    printf("Student %d waiting to enter the lab.\n", *a);
    sem_wait(&computers);
    printf("Student %d using the lab.\n", *a);
    sleep(rand()%3);
    sem_post(&computers);
    printf("Student %d leaving the lab.\n", *a);
    free(a); //dynamic memory needs to be freed
}

int main(){
    sem_init(&computers, 0, totalComputers);
    int i=0;
    while (i<20){
        count++;
        pthread_t tid;
        int* a=(int*)calloc(1, sizeof(int));
        *a=count;
        pthread_create(&tid, NULL, accessLabComp, a);
        sleep(rand()%2); //can be used random here
        i++;
    }

    sem_destroy(&computers);
    return 0;
}