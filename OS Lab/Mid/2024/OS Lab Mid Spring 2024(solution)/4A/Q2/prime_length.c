#include "functions.h"


int main(int argc, char* argv[]){
    if (argc<2){
        printf("Insifficient parameters passed to prime-length.\n");
        return 2;
    }
    int length=findLenght(argv[1]);
    if (length>=2){
        if (isPrime(length)==1){
            printf("The lenght %d is a prime. PID = %d.\n\n", length, getpid());
        }
        else{
            printf("The lenght %d is not a prime. PID = %d.\n\n", length, getpid());
        }
    }
    else{
        printf("The lenght %d is not a prime. PID = %d.\n\n", length, getpid());
    }
    //replace with find-middle program and passes the string as param
    char* arg[]={"./find_middle.out", argv[1], NULL};
    if (execvp(arg[0], arg)==-1){
        printf("find_middle not called.\n");
        return 1;
    }

    return 0;
}