// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    printf("Opening named pipe: /tmp/mypipe\n");
    char arr[80]="";
    char exitStr[]="exit";
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);

        // Take an input arr from user.
        // 80 is maximum length
        fgets(arr, 80, stdin);

        // Write the input arr in FIFO
        // and close it
        write(fd, arr, strlen(arr)+1);
        close(fd);
	    printf("Writing buffer to pipe....done\n");
	    if (strcmp( arr, "exit\n")==0){
        	break;
        }
  
    }
    printf("Exiting...\n");
    close(fd);
    return 0;
}


