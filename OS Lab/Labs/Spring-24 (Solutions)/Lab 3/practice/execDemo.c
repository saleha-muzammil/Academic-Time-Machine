#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
      printf("This is the main program.\n");
      //note that this array will be the same as the command line parameters to the program
      char* arg[]={"./exec.out", "1", "22" , "3", NULL};
      execvp(arg[0], arg);

      printf("Main program terminating.\n");
      return 0;
}