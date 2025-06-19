#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char** argv;
    int argc = 8;
    argv = malloc(argc);
    argv[0] = "man\0";
    argv[1] = "ls\0";
    argv[2] = "|\0";
    argv[3] = "grep\0";
    argv[4] = "ls\0";
    argv[5] = ">\0";
    argv[6] = "file.txt\0";
    argv[7] = NULL;
    execv("/bin/man", argv);
    return 0;
}