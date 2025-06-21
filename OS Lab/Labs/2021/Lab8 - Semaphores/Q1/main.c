#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t mutex;
void* printA(void* arg)
{
    //wait
    sem_wait(&mutex);
    //Main
    printf("a\n");
    sleep(1);
    //signal
    sem_post(&mutex);
}
void* printB(void* arg)
{
    //wait
    sem_wait(&mutex);
    //Main
    printf("b\n");
    sleep(1);
    //signal
    sem_post(&mutex);
}
void* printC(void* arg)
{
    //wait
    sem_wait(&mutex);
    //Main
    printf("c\n");
    sleep(1);
    //signal
    sem_post(&mutex);
}
int main()
{
    //printf does not show characters in a single line, so printing in individual lines.
    pthread_t t1, t2, t3, t4, t5;

    while (1)
    {
        sem_init(&mutex, 0, 1);
        pthread_create(&t1, NULL, printA, NULL);
        pthread_create(&t2, NULL, printA, NULL);
        pthread_create(&t3, NULL, printA, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        pthread_join(t3, NULL);
        pthread_create(&t4, NULL, printB, NULL);
        pthread_join(t4, NULL);
        pthread_create(&t5, NULL, printC, NULL);
        pthread_join(t5, NULL);
        sem_destroy(&mutex);
    }
    return 0;
}