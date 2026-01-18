#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
    char buff[100];
    int fd=open("np1", O_RDONLY);
    int bytesRead=read(fd, buff, 100);
    close(fd);
    for (int i=0;i<strlen(buff);i++){
        //convert lowercase to uppercase
        if (buff[i]>=97 && buff[i]<=127){
            buff[i]-=32;
        }
        //convert uppercase to lowercase
        else if (buff[i]>=65 && buff[i]<=90){
            buff[i]+=32;
        }
    }
    fd=open("np2", O_WRONLY);
    int bytesWritten=write(fd, buff, 100);
    close(fd);
    
    return 0;
}