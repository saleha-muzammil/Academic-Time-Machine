#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    char* filePath=argv[1];
    int fd=open(filePath, O_RDONLY);
    if (fd==-1){
        printf("File not opened.\n");
        return 3;
    }
    char buff[100];
    int bytesread=read(fd, buff, 100*sizeof(char));
    close(fd);
    int fd1=open(argv[2], O_WRONLY);
    if (fd1==-1){
        printf("pipe not opened.\n");
        return 3;
    }
    int bytesWritten=write(fd1, buff, 100*sizeof(char));
    close(fd1);
}