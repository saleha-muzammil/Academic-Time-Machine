#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
//included below to use exit.
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    int PipeSend[2], PipeRecieve[2];
    if (pipe(PipeSend) == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }
    if (pipe(PipeRecieve) == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }
    pid_t Process;
    Process = fork();
    if (Process < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (Process > 0)
    {
        //Parent process
        char string_to_pass[30] = "thIs Is a RanDoM stRinG\0";
        printf("I am the first process with Process id %d\nThe string to convert is: %s\n\n", getpid(), string_to_pass);
        /*close read end as message is only sent
        from this process*/
        close(PipeSend[READ_END]);
        write(PipeSend[WRITE_END], string_to_pass, strlen(string_to_pass) + 1);
        //after sending needs to wait
        int x = wait(NULL);
        close(PipeRecieve[WRITE_END]);
        read(PipeRecieve[READ_END], string_to_pass, 30);
        printf("I am in the first process again with Process id %d\nThis is the final string output: %s\n\n", getpid(), string_to_pass);
        close(PipeRecieve[READ_END]);
    }
    else
    {
        printf("I am the second process with Process id %d\nand parent id %d\n\n", getpid(), getppid());
        //Child Process.
        close(PipeSend[WRITE_END]);
        char tempSTR[30];
        read(PipeSend[READ_END], tempSTR, 30);
        for (int i = 0; tempSTR[i] != '\0'; i++)
        {
            if (tempSTR[i] >= 65 && tempSTR[i] <= 90)
                tempSTR[i]+=32;
            else 
                if (tempSTR[i] >= 97 && tempSTR[i] <= 122)
                    tempSTR[i]-=32;
        }
        close(PipeSend[READ_END]);
        close(PipeRecieve[READ_END]);
        write(PipeRecieve[WRITE_END], tempSTR, strlen(tempSTR) + 1);
        close(PipeRecieve[WRITE_END]);
        exit(0);
    }
    return 0;
}