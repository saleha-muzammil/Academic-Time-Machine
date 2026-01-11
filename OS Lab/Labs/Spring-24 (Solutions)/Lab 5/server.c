#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

//this may be used as the mode for the named pipe but it reserves the read and write only for the user
//as compared to 0777 which allows anyone to read or write to the file
#define PIPE_PERMISSION (S_IRUSR | S_IWUSR)

int main(){
    if (mkfifo("fifo1", 0777)==-1){
        if (errno!=EEXIST){
            perror("Named Pipe not created: ");
            return 1;
        }
    }
    int fd=open("fifo1", O_RDONLY);
    int i=0;
    while (i<100)
    {
        char buff[100];
        int pid=0;
        int bytesRead=read(fd, buff, 100*sizeof(char));
        sleep(2);
        bytesRead=read(fd, &pid, sizeof(int));
        printf("Message %d: %s from client pid: %d.\n", i+1,buff, pid);
        i++;
    }
    close(fd);
    

    return 0;
}