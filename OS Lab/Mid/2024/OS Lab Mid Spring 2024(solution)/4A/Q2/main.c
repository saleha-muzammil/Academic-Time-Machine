#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(){
    char buff[200];
    printf("Enter a string: ");
    fgets(buff, 100, stdin);
    buff[strlen(buff)-1]='\0'; //replaces the new line character with null character
    printf("String input:  %s.\nPID = %d\n\n", buff, getpid());
    //replace with prime_length program
    char* arg[]={"./prime_length.out", buff, NULL};
    if (execvp(arg[0], arg)==-1){
        printf("Prime-length not called.\n");
        return 1;
    }

    return 0;
}