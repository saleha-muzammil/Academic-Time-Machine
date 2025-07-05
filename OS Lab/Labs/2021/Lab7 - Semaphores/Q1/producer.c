#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <semaphore.h>

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        printf("More commands parssed than allowed\n");
        return -1;
    }
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL)
    {
        printf("file invalid\n");
        return 1;
    }

    char* thisChar = (char*) malloc(2);
    char* sharedMemory;
    sem_t* semaphore;
    int sID = shmget(133, 1024, 0666 | IPC_CREAT | IPC_EXCL);
    semaphore = (sem_t*) shmat(133, NULL, 0);
    int id = shmget(134, 1024, 0666 | IPC_CREAT | IPC_EXCL);
    sharedMemory = (char*) shmat(134, NULL, 0);

    sharedMemory = (char*) malloc(21);
    int i = 0;

    do
    {
        sharedMemory[0] = '\0';
        for (i = 0; i < 20; i++)
        {
            thisChar[0] = fgetc(fd);
            thisChar[1] = '\0';
            strcat(sharedMemory, thisChar);
            if (sharedMemory[i] == '$')
            {
                sharedMemory[i + 1] = '\0';
                break;
            }
        }
        sem_init(semaphore, 1, 0);
        printf("Press enter to print read chars\n");
        getchar();
        sem_post(semaphore);
    } while (sharedMemory[i] != '$');

    free(thisChar);
    sem_destroy(semaphore);
    shmdt(sharedMemory);
    shmdt(semaphore);
    shmctl(id, IPC_RMID, NULL);
    shmctl(sID, IPC_RMID, NULL);

    return 0;
}