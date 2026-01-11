#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int main(){
    char* fileName="file.txt";
    int fd=open(fileName, O_RDWR | O_CREAT | O_TRUNC, 0777);
    int newfd=dup2(fd, STDOUT_FILENO);
    close(fd);
    int pid=fork();
    if (pid==0){
        //writes the man ls content to file.txt
        if (execlp("man", "man", "ls", NULL)==-1){
            printf("Error changing to ls.\n");
            return 2;
        }
    }
    else{
        //reads the content from file.txt and applies grep ls to the content
        wait(NULL);
        if (execlp("grep", "grep", "ls", fileName, NULL)==-1){
            printf("Error changing to grep.\n");
            return 2;
        }
    }
    printf("ERROR.....\n");
    return 0;
}
