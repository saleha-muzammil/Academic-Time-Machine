#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd = open("math", O_RDONLY);
    if (fd < 0)
    {
        printf("error opeining pipe\n");
        return 1;
    }
    char* tempIN = (char*) malloc(100);
    read(fd, tempIN, 100);
    char operand = tempIN[0];
    char split[100];
    strcpy (split, strtok(tempIN, " "));
    int operators[2];
    for (int i = 0; i < 2; i++)
    {
        strcpy (split, strtok(NULL, " "));
        operators[i] = atoi(split);
    }
    close(fd);

    int ans = 0;
    if (operand == '+')
    {
        ans = operators[0] + operators[1];
    }
    else if (operand == '/')
    {
        ans = operators[0] / operators[1];
    }
    else if (operand == '*')
    {
        ans = operators[0] * operators[1];
    }
    else if (operand == '-')
    {
        ans = operators[0] - operators[1];
    }
    else
    {
        printf("operand not allowed\n");
        close(fd);
        return -2;
    }
    free(tempIN);

    fd = open("math", O_WRONLY);
    if (fd < 0)
    {
        printf("error opeining pipe\n");
        return 1;
    }
    if (write(fd, &ans, sizeof(ans)) < 0)
    {
        printf("error writing in pipe\n");
        return 2;
    }
    close(fd);
    printf("Calculated\n");

    return 0;
}