#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{

    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0)
    {
        fclose(stdout);
        dup(fd[1]);
        close(fd[0]);

        execlp("ls", "ls", NULL);
    }
    else 
    {
        fclose(stdin);
        dup(fd[0]);
        close(fd[1]);

        execlp("sort", "sort", NULL);
    }
}