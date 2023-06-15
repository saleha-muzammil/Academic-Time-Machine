// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    // FIFO file path
    char * myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    printf("Creating named pipe: /tmp/mypipe\n");
    char str[80]="";
    while (1)
    {
        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str, 80);
        printf("Waiting for input...Got it: %s", str);
        // Print the read string and close
        close(fd1);
        if (strcmp(str, "exit\n")==0){
        	break;
        }
    }

    printf("Exiting\n");
    
    return 0;
}
