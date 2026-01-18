#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


void* mulArrElemsByTwo(void* arg){
    int* newArr=(int*)calloc(10, sizeof(int));
    int* arr=(int*)arg;
    for (int i=0;i<10;i++){
        newArr[i]=arr[i]*2;
    }
    pthread_exit((void*)newArr);
}


int main(){
    int arr[10];
    for (int i=0;i<10;i++){
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    pthread_t tid;
    pthread_create(&tid, NULL, mulArrElemsByTwo, arr);
    int* newArr;
    pthread_join(tid, (void**)&newArr);
    printf("Elements multiplied by two are:\n");
    for (int i=0;i<10;i++){
        printf("%d , ", newArr[i]);
    }

    return 0;
}