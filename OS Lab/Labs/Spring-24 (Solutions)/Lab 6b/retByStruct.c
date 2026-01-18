#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


struct sum{
    int a;
    int b;
    int sum;
};

void* storeSum(void* arg){
    struct sum *tmp=(struct sum*)arg;
    tmp->sum=tmp->a+tmp->b;
    pthread_exit(0);
}

int main(){
    struct sum s1={5,4};
    pthread_t tid;
    pthread_create(&tid, NULL, storeSum, &s1);
    pthread_join(tid, NULL);
    printf("The sum from the main thread is %d.\n", s1.sum);
    return 0;
}