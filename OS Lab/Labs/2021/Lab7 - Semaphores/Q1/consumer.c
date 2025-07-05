#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <semaphore.h>

int main2(int argc, char* argv[])
{
    char* sharedMemory;
    sem_t* semaphore;

    int sID = shmget(133, 1024, 0);
    int id = shmget(134, 1024, 0);

    sharedMemory = (char*) shmat(123, NULL, 0);
    semaphore = (sem_t*) shmat(124, NULL, 0);

    for (int i = 0; sharedMemory[i] != '$'; i++)
    {
        sem_wait(semaphore);
        for (int j = 0; j < 20 && sharedMemory[j] != '$'; j++)
            printf("%d", sharedMemory[i]);
        printf("\n");
        printf("press enter to return to previous task\n");
        getchar();
        sem_post(semaphore);
    }

    shmdt(semaphore);
    shmdt(sharedMemory);

    return 0;
}