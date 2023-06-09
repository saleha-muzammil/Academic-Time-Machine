#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int FD = open("input.txt", O_RDONLY);
	if (FD < 0)
    {
        printf("File does not exist/Error opening file\nerror: %d", FD);
        return 0;
    }
    char* thisLine = (char*) malloc(1000);
    int sum = 0;
    int curr = 0;
    int mul = 1;
    int j = 0;
    read (FD, thisLine, 1000);
    while (j != strlen(thisLine))
    {
        mul = 1;
        curr = 0;
        while (thisLine[j] != '\n')
        {
            curr += (thisLine[j]-48) * mul;
            mul*=10;
            j++;
        }
        while(thisLine[j] == '\n')
            j++;
        sum += curr;
    }
    int newFD = open("output.txt", O_WRONLY | O_RDONLY | O_CREAT);
    dup2(newFD, 1);
    printf("%d\n", sum);
    close(newFD);
    close(FD);
    free(thisLine);
    return 0;
}
