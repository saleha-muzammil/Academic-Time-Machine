#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
    int fd=open("fifo1", O_WRONLY);
    while (1)
    {
        char buff[100]="Hello, server!\0";
        int bytesWritten=write(fd, buff, 100*sizeof(char));
        int pid=getpid();
        // sleep(1);
        bytesWritten=write(fd, &pid, sizeof(int));
    }
    close(fd);
    return 0;
}