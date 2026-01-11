#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int pid = fork();
    int pid1=fork();
    if (pid==0 && pid1==0){
        printf("This is a child process(pid=%d).\n", getpid());
        exit(0); //exit with status 0 means succesfully exited
    }
    else if (pid==0 && pid1!=0){
        wait(NULL); //wait for the child process to terminate
        printf("This is a parent process(pid=%d).\n", getpid());
    }

    if (pid!=0 && pid1==0){
        printf("This is a child process(pid=%d).(2)\n", getpid());
        exit(0);    
    }
    else if ((pid!=0 && pid1!=0)) {
        wait(NULL);
        printf("This is a parent process(pid=%d).(2)\n", getpid());
    }
    return 0;
}

// Process Tree
            //        P
            //      /    \
            //     P      C
            //    / \    / \
            //   P  C1  C  c2
        