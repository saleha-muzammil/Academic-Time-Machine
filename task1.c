#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int i = 0;

void *findAverage(void *args)
{
    int *arr = (int *)args;
    int sum, j;
    for (j = 0; j < i; j++)
    {
        sum += arr[j];
    }
    int avg = sum / (i);
    pthread_exit(avg);
}
void *findMin(void *args)
{
    int *arr = (int *)args;
    int min = arr[0], j;
    for (j = 1; j < i; j++)
    {
        if (arr[j] < min)
            min = arr[j];
    }
    pthread_exit(min);
}
void *findMax(void *args)
{
    int *arr = (int *)args;
    int max = arr[0], j;
    for (j = 1; j < i; j++)
    {
        if (arr[j] > max)
            max = arr[j];
    }
    pthread_exit(max);
}
int main(int argc, char **argv)
{

    int *arr = (int *)calloc((argc - 1), sizeof(int));
    for (i; i < argc - 1; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    pthread_t avg_thread, max_thread, min_thread;
    int avg, min, max;

    pthread_create(&avg_thread, NULL, findAverage, (void *)arr);
    pthread_join(avg_thread, (void **)&avg);
    printf("The average value is %d\n", avg);

    pthread_create(&max_thread, NULL, findMax, (void *)arr);
    pthread_join(max_thread, (void **)&max);
    printf("The max value is %d\n", max);

    pthread_create(&min_thread, NULL, findMin, (void *)arr);
    pthread_join(min_thread, (void **)&min);
    printf("The min value is %d\n", min);

    return 0;
}