#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int main(int argc, char* argv[]){
    char* fifoName="fifo1";
    if (argc!=3){
        printf("Insufficient number of parameters passed.\n");
        return 1;
    }
    if (mkfifo(fifoName, 0777)==-1){
        if (errno!=EEXIST){
            printf("Named pipe could not be created.\n");
            return 2;
        }
    }
    int pid1, pid2;
    pid1=fork();
    if (pid1==0){
        pid2=fork();
    }
    if (pid1==0 && pid2==0){
        //child 1
        //file reader: pipe->input, out.txt->out
        char* arg[]={"fileWriter.out", fifoName, "out.txt", NULL};
        execvp(arg[0], arg);
        printf("File reader not executed.\n");
        return 2;
    }
    else{
        //child 2
        //file writer: in.txt->input, pipe->out
        char* arg[]={"fileReader.out", "in.txt", fifoName, NULL};
        execvp(arg[0], arg);
        printf("File writer not executed.\n");
        return 2;
    }
    wait(NULL);
    wait(NULL);
    //reverses the words
    char* arg[]={"fileReader.out", "in.txt", "out.txt", NULL};
    execvp(arg[0], arg);
    printf("word reverser did not work.\n");

    return 0;
}