#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(){
    int a=0;
    char quote[]="A computer would deserve to be called intelligent if it could deceive a human into believing that it was human.";
    int fd=open("story_pipe", O_WRONLY);
    int bytesWritten=write(fd, quote, strlen(quote)*sizeof(char));
    close(fd);

    return 0;
}