#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
    if (mkfifo("story_pipe", 0777)==-1){
        if (errno!=EEXIST){
            printf("Named pipe not created succesfully.\n");
            return 1;
        }
    }
    return 0;
}