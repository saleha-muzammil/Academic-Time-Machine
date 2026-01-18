#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* arg[]){

      printf("This is exec.c executed using execvp command.\n");
      printf("Parameters: \n");
      for (int i=1;i<argc;i++){
            printf("%d: %d\n", i, atoi(arg[i]));
      }

      return 0;
}