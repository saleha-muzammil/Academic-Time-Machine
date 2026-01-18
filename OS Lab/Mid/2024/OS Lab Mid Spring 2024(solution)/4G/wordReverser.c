#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[]){
    char buff[100];
    int fd=open(argv[1], buff, 100*sizeof(char));
    int bytesRead=read(fd, buff, 100*sizeof(char));
    close(fd);
    char* arr[10];
    char* curr=strtok(buff, ' ');
    int size=0;
    while (curr!=NULL){
        arr[size++]=curr;
        curr=strtok(NULL, ' ');
    }

}