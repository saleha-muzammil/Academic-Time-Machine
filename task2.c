#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

void *threadFunction(void *);

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("Invalid number of arguments\n");
        return 1;
    }
    int n = 0, i = 0, retVal = 0;
    pthread_t *thread;

    n = atoi(argv[1]);

    thread = (pthread_t *)malloc(n * sizeof(pthread_t));

    for (i = 0; i < n; i++)
    {
        retVal = pthread_create(&thread[i], NULL, threadFunction, (void *)&i);
        printf("I am thread 1. Created new thread (%d) in iteration %d...\n", (int)thread[i], i + 1);

        if ((i + 1) % 4 == 0)
        {
            sleep(1);
        }

    }

    // for (i = 0; i < n; i++)
    // {
    //     retVal = pthread_join(thread[i], NULL);
    //     if (retVal != 0)
    //     {
    //         printf("pthread_join failed in %d_th pass\n", i);
    //         exit(EXIT_FAILURE);
    //     }
    // }
}

void *threadFunction(void *arg)
{
    int iterationNum = *((int *)arg);

    pid_t tid = pthread_self();

    printf("Hello from thread %d - I was created in iteration %d\n", (int)tid, iterationNum + 1);

    pthread_exit(NULL);
}
