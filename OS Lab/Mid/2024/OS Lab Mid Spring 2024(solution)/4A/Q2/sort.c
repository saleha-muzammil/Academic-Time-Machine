#include "functions.h"

int main(int argc, char* argv[]){
    if (argc<2){
        printf("Insifficient parameters passed to word_count.\n");
        return 2;
    }
    // printf("%s", argv[1]);
    int len=findLenght(argv[1]);
    char tmp[200];
    strcpy(tmp, argv[1]);
    sort(tmp, len);
    printf("The sorted arr is: ");
    for (int i=0;i<len;i++){
        printf("%c", tmp[i]);
    }
    printf(" .PID = %d.\n\n",getpid());

    return 0;
}