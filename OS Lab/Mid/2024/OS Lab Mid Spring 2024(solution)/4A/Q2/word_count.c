#include "functions.h"


int main(int argc, char* argv[]){
    if (argc<2){
        printf("Insifficient parameters passed to word_count.\n");
        return 2;
    }
    char* buff[100];
    int wordCount=0;
    char tmp[200];
    strcpy(tmp, argv[1]);
    // printf("The string received in word_count is: %s\n", tmp);
    tokenizeString(tmp, buff, &wordCount);
    printf("The number of words in the string are %d. PID = %d.\nWords are:\n", wordCount, getpid());
    for (int i=0;i<wordCount;i++){
        printf("%s\n", buff[i]);
    }
    printf("\n");
    //printf("The string after processing in word_count is: %s\n", argv[1]);
    //replace with sort program and passes the string as param and through the pipe
    int fd[2];
    if (pipe(fd)==-1){
        perror("Pipe not created: ");
        return 2;
    }
    int pid=fork();
    if (pid==0){
        close(fd[0]);
        int bytesWritten=write(fd[1], argv[1], 1000);
        close(fd[0]);
        exit(0);
    }
    else{
        char* arg[]={"./sort.out", argv[1], NULL};
        if (execvp(arg[0], arg)==-1){
            printf("sort not called.\n");
            return 1;
        }
    }

    return 0;
}