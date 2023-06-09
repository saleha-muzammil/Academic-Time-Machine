#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define READ_END 0
#define WRITE_END 1
#define LEN 50

//Printf only used to ouput errors

int main(void)
{
    int fd[2];
    pid_t Process;

    if (pipe(fd) == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }

    Process = fork();
    if (Process < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    //Parent process
    if (Process > 0)
    {
        char Read[LEN];
        int file = open("readFile.txt", O_RDONLY, S_IRUSR);
        read(file, Read, LEN);
        /*Close read end,
        since this portion only writes to file*/
        printf("%s\n", Read);
        close(fd[READ_END]);
        write(fd[WRITE_END], Read, strlen(Read) + 1);
        close(fd[WRITE_END]);
    }
    //Child process
    else
    {
        char Write[LEN];
        /*Close write end,
        since this portion reads only*/
        close(fd[WRITE_END]);
        read(fd[READ_END], Write, LEN);
        printf("%s\n", Write);
        int file = open("writeFile.txt", O_WRONLY, S_IWUSR);
        write(file, Write, strlen(Write) + 1);
        close(fd[READ_END]);
    }

    return 0;
}
