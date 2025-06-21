#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int* arr, n;

int convert_Int(char* word)
{
    int retInt = 0;
    int mul = 1;
    int i = strlen(word) - 1;
    for (i; i >= 0; i--)
    {
        retInt += (word[i] - 48) * mul;
        mul*= 10;
    }
    return retInt;
}

void* stats(void* parseVal)
{
    int x = *(int*)parseVal;
    if (x == 0)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        printf("Mean is: %d\n", sum/n);
    }
    else
    if (x == 1)
    {
        int max = arr[0];
        for (int i = 0; i < n; i++)
            if (max < arr[i])
                max = arr[i];
        printf("Max is: %d\n", max);
    }
    else
    {
        int min = arr[0];
        for (int i = 0; i < n; i++)
            if (min > arr[i])
                min = arr[i];
        printf("Min is: %d\n", min);
    }
}

int main (int argc, char* argv[])
{
    pthread_t t1, t2, t3;
    n = argc - 1;
    arr = (int*)malloc(n);
    printf("Begin\n");

    for (int i = 1; i < argc; i++)
    {
        arr[i-1] = convert_Int(argv[i]);
    }
    
    int x1 = 0, x2 = 1, x3 = 2;
    pthread_create(&t1, NULL, stats, &x1);
    pthread_create(&t2, NULL, stats, &x2);
    pthread_create(&t3, NULL, stats, &x3);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    free (arr);

    return 0;
}