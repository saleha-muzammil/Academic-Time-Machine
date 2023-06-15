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
    char *myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    char operator = "+";
    int operands[2] = {4,5};

    // Open FIFO for write only
    fd = open(myfifo, O_WRONLY);
    write(fd, operator, sizeof(char));
    close(fd);
    fd = open(myfifo, O_WRONLY);

    write(fd, operands[0], sizeof(int));
    close(fd);
    fd = open(myfifo, O_WRONLY);
    write(fd, operands[1], sizeof(int));
    close(fd);
    

    int result = 0;
    fd = open(myfifo, O_RDONLY);
    read(fd, result, sizeof(int));
    close(fd);

    printf("Result is %d\n", result);

    return 0;
}
