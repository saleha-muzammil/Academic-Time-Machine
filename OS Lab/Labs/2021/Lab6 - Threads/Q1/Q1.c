#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

struct parrameters
{
    int n; int t;
};

void* Fib(void* args)
{
    int retVal = 0;
    int a = 0, b = 1;
    struct parrameters P = *(struct parrameters*)args;
    //Wait added to ensure parrallel execution.
    sleep(P.n);
    printf("Thread %d: %d %d ", P.t, a, b);
    for (int i = 0; i < P.n; i++)
    {
        retVal = (a + b);
        printf("%d ", retVal);
        a = b;
        b = retVal;
    }
    printf("\n");
}

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

int main (int argc, char* argv[])
{
    struct parrameters* arguments = (struct parrameters*) malloc(argc);
    pthread_t* threads = (pthread_t*) malloc(argc);

    for (int i = 1; i < argc; i++)
    {
        arguments[i - 1].t = i;
        arguments[i - 1].n = convert_Int(argv[i]);
        pthread_create(&threads[i - 1], NULL, &Fib, &arguments[i - 1]);
    }

    for (int i = 1; i < argc; i++)
    {
        pthread_join(threads[i - 1], NULL);
    }

    return 0; 
}