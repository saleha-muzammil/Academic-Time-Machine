#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
      int pid=fork();
      if (pid==0){
            printf("The pid of the child process is %d.\n", getpid());
            exit(0); //success
      }
      else{
            int pid1=wait(NULL);
            printf("The pid of the child from the parent process is %d.\n", pid1);
      }

      return 0;
}