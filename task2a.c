// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd1;

    // FIFO file path
    char *myfifo = "/tmp/mypipe";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    char operator= 'x';
    int num[2];
    char input[10] = "xd";

    // First open in read only and read
    while (operator== 'x')
    {
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, operator, sizeof(char));
        printf("%c ", operator);
        close(fd1);
    }
    while (strcmp(input, "xd")==0)
    {
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, input, sizeof(int));
        num[0] = atoi(input);
        printf("%d ", num[0]);
        close(fd1);
    }
    strcpy(input, "xd");

    while (strcmp(input, "xd")==0)
    {
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, input, sizeof(int));
        num[1] = atoi(input);
        printf("%d ", num[1]);
        close(fd1);
    }

    int result = 0;
    if (operator== '+')
    {
        result = num[0] + num[1];
    }
    else if (operator== '-')
    {
        result = num[0] - num[1];
    }
    else if (operator== '*')
    {
        result = num[0] * num[1];
    }
    else if (operator== '/')
    {
        result = num[0] / num[1];
    }

    fd1 = open(myfifo, O_WRONLY);
    write(fd1, result, sizeof(int));

    close(fd1);

    return 0;
}