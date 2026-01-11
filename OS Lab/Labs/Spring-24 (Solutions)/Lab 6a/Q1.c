#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void convertUpperCaseToLowerCase(char* arr, int size){
    for (int i=0;i<size;i++){
        if (arr[i]>='A' && arr[i]<='Z'){
            arr[i]+=32; //add 32 to the ascii to make uppercase
        }
    }
}


int main(){
    char* fileName="original.txt";
    int fd=open(fileName, O_RDONLY | O_CREAT);
    char buff[100];
    int bytesRead=read(fd, buff, 100*sizeof(char));
    printf("%d bytes read from the file.\n", bytesRead);
    close(fd);
    fd=open(fileName, O_WRONLY|O_TRUNC);
    int newfd=dup(fd); 
    close(fd);

    convertUpperCaseToLowerCase(buff, bytesRead/sizeof(char));

    int bytesWritten=write(newfd, buff, bytesRead);
    printf("%d bytes written to the file.\n", bytesWritten);
    close(newfd);

    return 0;
}