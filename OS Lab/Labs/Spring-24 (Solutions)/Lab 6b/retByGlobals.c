#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


struct nums{
    int a;
    int b;
};

int sum=0;

void* storeSumGlobally(void* arg){
    struct nums *tmp=(struct nums*)arg;
    sum=tmp->a+tmp->b;
    pthread_exit(0);
}

int main(){
    struct nums s1={5,4};
    pthread_t tid;
    pthread_create(&tid, NULL, storeSumGlobally, &s1);
    pthread_join(tid, NULL);
    printf("The global sum variable is %d.\n", sum);
    return 0;
}