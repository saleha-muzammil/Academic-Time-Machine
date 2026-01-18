#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
    //we can also use a single named pipe here that we will open first for write, close it and then for read and then close it also at the end
    if (mkfifo("np1", 0777)==-1){
        if (errno!=EEXIST){
            perror("Named pipe 1 error: ");
            return 1;
        }
    }
    if (mkfifo("np2", 0777)==-1){
        if (errno!=EEXIST){
            perror("Named pipe 2 error: ");
            return 1;
        }
    }
    char buff[100];
    //take user input
    printf("Enter a string to invert the letter case: ");
    fgets(buff, 100*sizeof(char), stdin);
    //send to the receiver
    int fd=open("np1", O_WRONLY);
    int bytesWritten=write(fd, buff, 100*sizeof(char));
    close(fd);
    //recieve the processed string
    fd=open("np2", O_RDONLY);
    int bytesRead=read(fd, buff, 100*sizeof(char));
    close(fd);
    //print it
    printf("OUTPUT: %s\n", buff);
    
    return 0;
}