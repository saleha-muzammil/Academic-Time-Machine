#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaphore[4];
int x;

void* increment(void* args)
{
    int TNum = *(int*)args;
    sem_wait(&semaphore[TNum]);
    printf("x incremented in thread %d\n", TNum + 1);
    x++;
    //delay added to show sequence. (could be commented)
    sleep(1);
    //Signal next execution
    sem_post(&semaphore[TNum + 1]);
}
void* displayCompletion(void* args)
{
    int TNum = *(int*)args;
    sem_wait(&semaphore[TNum]);
    printf("all threads are executed\n");
    //delay added to show sequence.
    sleep(1);
    sem_post(&semaphore[TNum]);
}

int main()
{
    printf("for ease of execution no arguments passed\n");
    printf("threshold number of threads are 4, 5th thread signals task completion\n");
    pthread_t threads[5];
    x = 0;
    int tNum[5] = {0, 1, 2, 3, 4};
    for(int i = 0; i < 4; i++)
    {
        sem_init(&semaphore[i], 0, 0);
    }
    for(int i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, &increment, &tNum[i]);
    }
    pthread_create(&threads[4], NULL, &displayCompletion, &tNum[4]);
    sem_post(&semaphore[0]);
    //joining inverted to show semaphore synchronizes tasks.
    for(int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_wait(&semaphore[4]);
    printf("\n%d\n", x);
    return 0;
}