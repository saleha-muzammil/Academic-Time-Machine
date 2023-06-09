#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    if (mkfifo("math", 0777) == -1)
    {
        printf("error making pipe\n");
        return -1;
    }
    printf("input something for calculation: ");
    char* tempIN = (char*) malloc(100);
    fgets(tempIN, 100, stdin);

    int fd = open("math", O_WRONLY);
    if (fd < 0)
    {
        printf("error opening pipe\n");
        return 1;
    }
    if (write(fd, tempIN, sizeof(tempIN)) < 0)
    {
        printf("error writing in pipe\n");
        return 2;
    }
    close(fd);
    free (tempIN);

    int ans = 0;
    fd = open("math", O_RDONLY);
    if (fd < 0)
    {
        printf("error opening pipe\n");
        return 1;
    }
    if (read(fd, &ans, sizeof(ans)) < 0)
    {
        printf("error reading from pipe\n");
        return 3;
    }
    printf("sum is: %d\n", ans);
    close(fd);

    execlp("/usr/bin/rm", "rm", "math", NULL);    

    return 0;
}