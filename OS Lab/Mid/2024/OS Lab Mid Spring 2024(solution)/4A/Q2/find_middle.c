#include "functions.h"

int main(int argc, char* argv[]){
    if (argc<2){
        printf("Insifficient parameters passed to find_middle.\n");
        return 2;
    }
    int len=findLenght(argv[1]);
    printf("The char at the middle index is '%c'. PID = %d.\n\n", argv[1][len/2], getpid());
    //replace with word_count program
    //replace with find-middle program and passes the string as param
    char* arg[]={"./word_count.out", argv[1], NULL};
    if (execvp(arg[0], arg)==-1){
        printf("word_count not called.\n");
        return 1;
    }

    return 0;
}