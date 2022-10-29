#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>


int sem1, sem2, mutex;

void *producer()
{
    int fd1;

    // FIFO file path
    char *myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    char str[255]="data block";

    do
    {

        wait(&sem1);
        wait(&mutex);
        // printf("Input data\n");
        // fgets(str, 255, stdin);
        fd1 = open(myfifo, O_WRONLY);
        write(fd1, str, 255*sizeof(char));
        close(fd1);
        signal(&mutex);
        signal(&sem2);
    } while (1);
}
void *consumer()
{
    int fd1;

    // FIFO file path
    char *myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    char str[255];
    do
    {
        wait(&sem2);
        wait(&mutex);
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, str, 255*sizeof(char));
        printf("Received: %s", str);
        close(fd1);

        signal(&mutex);
        signal(&sem1);
    } while (1);
}
int main()
{
    printf("Input N: ");
    scanf("%d", &sem1);
    sem2=0;
    mutex=1;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
