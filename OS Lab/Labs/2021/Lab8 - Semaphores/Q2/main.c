#include "main.h"

int main()
{
    printf("input number of threads to make.\n");
    char* input;
    scanf("%s", input);
    int numOfTs = atoi(input);
    sem_t* mutex = malloc(numOfTs);
    pthread_t readerThread;
    pthread_t* writerThreads = malloc(numOfTs);
    struct arguments* args = malloc(numOfTs);

    while(1)
    {
        pthread_create(&readerThread, 0, &Read, &args[0]);
        pthread_join(readerThread, NULL);
        for (int i = 1; i < numOfTs; i++)
        {
            args[i].key = args[i - 1].key;
            args[i].size = args[i - 1].size;
        }
        int divs = (args[0].size/8)/numOfTs;
        for (int i = 0; i < numOfTs; i++)
        {
            if (i == 0)
            {
                args[0].start = 0;
                args[0].end = args[0].start + divs;
            }
            else
            {
                args[i].start = args[i - 1].end;
                args[i].end = args[i - 1].end + divs;
            }
            args[i].thisTask = mutex[i];
            pthread_create(&writerThreads[i], 0, &Write, &args);
        }
        for (int i = 0; i < numOfTs; i++)
        {
            pthread_join(writerThreads[i], NULL);
        }
    }

    return 0;
}