#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int findLenght(char* arr){
    int i=0;
    while (arr[i]!='\0' && arr[i]!='\n'){
        i++;
    }
    return i;
}

int isPrime(int n){
    for (int i=2;i<=n/2;i++){
        if (n%i==0){
            return 0; //not prime
        }
    }
    return 1; //prime
}

void tokenizeString(char* str, char* arr[], int* wordCount){
    char* curr=strtok(str, " ");
    while (curr!=NULL){
        arr[(*wordCount)++]=curr;
        curr=strtok(NULL, " ");
    }
}

void sort(char arr[], int size){
    //bubble sort
    for (int i=0;i<size;i++){
        for (int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                char tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}