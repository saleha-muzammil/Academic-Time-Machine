#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int fd1[2], fd2[2];
    if (pipe(fd1)==-1){
        perror("Pipe 1: ");
        return 1;
    }
    if (pipe(fd2)==-1){
        perror("Pipe 2: ");
        return 1;
    }
    int pid=fork();
    if (pid==0){
        //student
        char arr[100];
        //receive content from the teacher
        close(fd1[1]);
        int bytesRead=read(fd1[0], arr, sizeof(arr));
        close(fd1[0]);
        //process it
        int i=0, j=0;
        while (arr[i]!='\0' && arr[i]!='\n'){
            if ((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z' || arr[i] == ' ')){
                arr[j++]=arr[i];
            }
            i++;
        }
        arr[j]='\0';
        //send it back
        close(fd2[0]);
        int bytesWritten=write(fd2[1], arr, sizeof(char)*(j+1));
        close(fd2[1]);
        exit(0);
    }
    else{
        //teacher
        char arr[100];
        //take user input
        printf("Enter the content to be proof-read: ");
        fgets(arr, 100, stdin);
        //send the content to the student
        close(fd1[0]);
        int bytesWritten=write(fd1[1], arr, sizeof(arr));
        close(fd1[1]);
        //then receive the processes result
        close(fd2[1]);
        int bytesRead=read(fd2[0], arr, sizeof(arr));
        close(fd2[0]);
        //print the results
        printf("FINAL OUTPUT: %s\n", arr);
        wait(NULL);
    }

    return 0;
}
