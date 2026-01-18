#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>


void* matrixColsToDecimal(void* arg){
    int* arr=(int*)arg;
    int rows=arr[0], cols=arr[1], colNum=arr[2];
    int mul=pow(2,rows-1);
    int* num=(int*)calloc(1, sizeof(int));
    for (int i=0;i<rows;i++){
        (*num)+=(mul*arr[i+3]);
        mul/=2;
    }
    //free the dynamically created arguement arr
    free(arr);
    //return the decimal digit
    pthread_exit((void*)num);
}


void* matrixRowsToDecimal(void* arg){
    int* arr=(int*)arg;
    int rows=arr[0], cols=arr[1], colNum=arr[2];
    int mul=pow(2,cols-1);
    int* num=(int*)calloc(1, sizeof(int));
    for (int i=0;i<rows;i++){
        (*num)+=(mul*arr[i+3]);
        mul/=2;
    }
    //free the dynamically created arguement arr
    free(arr);
    //return the decimal digit
    pthread_exit((void*)num);
}


int main(){
    int rows, cols;
    printf("Enter the rows of the matrix:");
    scanf("%d", &rows);
    printf("Enter the columns of the matrix:");
    scanf("%d", &cols);
    //create a 2D array for the matrix
    int matrix[rows][cols];
    //taking user input
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            printf("%d,%d:",i+1,j+1);
            scanf("%d", &matrix[i][j]);
            while (matrix[i][j]!=0 && matrix[i][j]!=1){
                printf("Value must be in binary (0 / 1):");
                scanf("%d", &matrix[i][j]);
            }
        }
    }
    //displaying the matrix
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    //taking last digit of roll number as input
    int lastRollDigit;
    printf("Enter the last digit of your roll number:");
    scanf("%d", &lastRollDigit);
    while (lastRollDigit<0 || lastRollDigit>9){
        printf("Enter a single digit:");
        scanf("%d", &lastRollDigit);
    }
    if (lastRollDigit>=0 && lastRollDigit<=4){
        //convert binary columns to decimals
        pthread_t threadArr[cols];
        for (int i=0;i<cols;i++){
            int* arr=malloc(sizeof(int)*(rows+3)); 
            //first 3 index stores the row, col and index respectively
            //followed by the columns
            arr[0]=rows;arr[1]=cols;arr[2]=i;
            for (int j=0;j<rows;j++){
                arr[j+3]=matrix[j][i];
            }
            pthread_create(&threadArr[i], NULL, matrixColsToDecimal, (void*)arr);
        }
        int* decDigits[cols];
        for (int i=0;i<cols;i++){
            pthread_join(threadArr[i],(void**)&decDigits[i]);
        }
        for (int i=0;i<cols;i++){
            printf("Col %d: %d\n",i+1, *decDigits[i]);
        }
    }
    else{
        //convert binary rows to decimals
        pthread_t threadArr[rows];
        for (int i=0;i<rows;i++){
            int* arr=malloc(sizeof(int)*(cols+3)); 
            //first 3 index stores the row, col and index respectively
            //followed by the rows
            arr[0]=rows;arr[1]=cols;arr[2]=i;
            for (int j=0;j<cols;j++){
                arr[j+3]=matrix[i][j];
            }
            pthread_create(&threadArr[i], NULL, matrixRowsToDecimal, (void*)arr);
        }
        int* decDigits[rows];
        for (int i=0;i<rows;i++){
            pthread_join(threadArr[i],(void**)&decDigits[i]);
        }
        for (int i=0;i<rows;i++){
            printf("Row %d: %d\n",i+1, *decDigits[i]);
        }
    }

    return 0;
}
