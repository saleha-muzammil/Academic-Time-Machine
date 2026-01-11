#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
      char* arg[]={"./exec.out", "1", "22" , NULL};
      execvp(arg[0], arg);
      printf("executed.\n");
      return 0;
}