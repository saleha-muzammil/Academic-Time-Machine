#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int isPrime(int num){
    if (num<=1){
        return 0;
    }
    for (int i=2;i<=(num/2);i++){
        if (num%i==0){
            return 0;
        }
    }
    return 1;
}


void printPrimesInRange(int start, int end){
    for (int i=start;i<=end;i++){
        if (isPrime(i)==1){
            printf("%d\n", i);
        }
    }
}


int main(){
    //init file names
    char* fName="input.txt";
    char* fName1="output.txt";
    // fflush(stdout);
    //save the fd pointing to stdin for recovery
    int oldstdin=dup(STDIN_FILENO);
    //reading file
    int fd=open(fName, O_RDONLY | O_CREAT);
    if (fd==-1){
        printf("File for read not opened correctly!\n");
        return 2;
    }
    int newfd=dup2(fd, 0); //0 ->fd of stdin
    close(fd);
    int start, end;
    scanf("%d %d", &start, &end); //the input from the file will be space seperated
    close(newfd);
    //recovering the fd to the stdin
    dup2(oldstdin, STDIN_FILENO);
    close(oldstdin);
    //save the fd pointing to stdout for recovery
    int oldstdout=dup(STDOUT_FILENO);
    //writing file
    int fd1=open(fName1, O_RDWR | O_CREAT);
    if (fd1==-1){
        printf("File for write not opened correctly!\n");
        return 2;
    }
    newfd=dup2(fd1, 1); //1->fd of stdout
    close(fd1);
    // close(newfd);
    //printing primes in range
    printPrimesInRange(start, end);
    //recover the original stdout
    // dup2(oldstdout, STDOUT_FILENO);
    // close(oldstdout);

    return 0;
}
