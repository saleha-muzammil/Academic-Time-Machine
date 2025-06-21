#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shmid = -1;

struct arguments
{
    key_t key;
    size_t size;
    sem_t thisTask;
    int start, end;
};

void* Read(void* args)
{
    struct arguments* Ptr = (struct arguments*) args;
    sem_wait(&Ptr->thisTask);
    if (shmid != -1)
    {
        shmctl(shmid, IPC_RMID, NULL);
    }
    printf("Input data\n");
    Ptr->key = ftok("shared", 65);
    Ptr->size = 1024;
    shmid = shmget(Ptr->key, Ptr->size, 0666 | IPC_CREAT | IPC_PRIVATE);
    char* myStr = shmat(shmid, (void*)0, 0);
    scanf("%s", myStr);
    shmdt(myStr);
    sem_post(&Ptr->thisTask);
}
void* Write(void* args)
{
    struct arguments P = *(struct arguments*) args;
    sem_wait(&P.thisTask);
    char* str = (char*) shmat(shmid, (void*)0, 0);
    for (int i = P.start; i < P.end && str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    shmdt(str);
    sem_post(&P.thisTask);
}