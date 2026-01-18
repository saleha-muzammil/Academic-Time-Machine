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
    char quote[1000];
    int fd=open("story_pipe", O_RDONLY);
    int bytesRead=read(fd, quote, 1000);
    close(fd);

    char* buff[100];
    int size=0;
    char* curr=strtok(quote, " ");
    while (curr!=NULL)
    {
        buff[size++]=curr;
        //  printf("%s\n", curr);
        curr=strtok(NULL, " ");
    }
    //tokenizes the quote so there are number of words equal to size
    int arr[7]={0};
    for (int i=0;i<size;i++){
        if (strcmp(buff[i], "a")==0){
            arr[0]++;
        }
        else if (strcmp(buff[i], "the")==0){
            arr[1]++;
        }
        else if (strcmp(buff[i], "an")==0){
            arr[2]++;
        }
        else if (strcmp(buff[i], "of")==0){
            arr[3]++;
        }
        else if (strcmp(buff[i], "to")==0){
            arr[4]++;
        }
        else if (strcmp(buff[i], "in")==0){
            arr[5]++;
        }
        else if (strcmp(buff[i], "and")==0){
            arr[6]++;
        }
    }
    printf("a: %d\n", arr[0]);
    printf("the: %d\n", arr[1]);
    printf("an: %d\n", arr[2]);
    printf("of: %d\n", arr[3]);
    printf("to: %d\n", arr[4]);
    printf("in: %d\n", arr[5]);
    printf("and: %d\n", arr[6]);

    return 0;
}