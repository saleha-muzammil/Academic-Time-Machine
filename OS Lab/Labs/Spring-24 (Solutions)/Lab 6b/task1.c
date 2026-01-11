#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int isDuplicatePresent(int arr[], int n, int num){
    //as in our specific case the 0 index stores the size of the array
    //though we can start from 0 index as it is initialized with number 0
    //so there would be no effect on the final sum and average
    for (int i=1;i<n;i++){
        if (arr[i]==num){
            return 1;
        }
    }
    return 0;
}


void* removeNegativeAndDuplicates(void* arg){
    char* fileName=(char*)arg;
    int fd=open(fileName, O_RDWR);
    char buff[100];
    int bytesRead=read(fd, buff, sizeof(char)*100);
    close(fd);
    int* arr=(int*)calloc(100, sizeof(int));
    char* curr=strtok(buff, " ");
    int j=1;
    while (curr!=NULL){
        arr[j++]=atoi(curr); //converts neg numbers to pos so manually check for a -ve sign
        //something different with tokenized string is that the - sign is at the last index
        //i.e. the digits are placed in a reverse order
        if (curr[strlen(curr)-1]=='-'){
            arr[j-1]*=-1;
        }
        curr=strtok(NULL, " ");
    }

    // for (int i=0;i<j;i++){
    //     printf("%d , ", arr[i]);
    // }
    
    int maxCount=1;
    for (int i=1;i<j;i++){
        if (arr[i]>=0 && isDuplicatePresent(arr, i, arr[i])==0){
            arr[maxCount++]=arr[i];
        }
    }
    //place maxCount at the first index
    arr[0]=maxCount;
    // for (int i=0;i<maxCount;i++){
    //     printf("%d , ", arr[i]);
    // }
    pthread_exit(arr);
}


int main(){
    pthread_t thread1, thread2;
    char* file1="f1.txt", *file2="f2.txt";
    pthread_create(&thread1, NULL, removeNegativeAndDuplicates, file1);
    pthread_create(&thread2, NULL, removeNegativeAndDuplicates, file2);
    int* arr1, *arr2;
    //takes the return value from the thread functions through pthread_exit()
    pthread_join(thread1, (void**) &arr1); //as the second param is of void** type
    pthread_join(thread2, (void**) &arr2);
    int size1=arr1[0];
    int size2=arr2[0];
    int sum=0;
    for (int i=1;i<size1;i++){
        sum+=arr1[i];
    }
    for (int i=1;i<size2;i++){
        sum+=arr2[i];
    }
    free(arr1);
    free(arr2);
    //subtract 2 from the sizes as it also includes the first element containing the sizes of both the arrays
    printf("The average is %f.", (float)sum/(size1+size2-2));

return 0;
}