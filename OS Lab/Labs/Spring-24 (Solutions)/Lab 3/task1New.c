#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
      int pid1, pid2, pid3, pid4;
      pid1=fork();

      if (pid1==0){
            printf("Child 1.\n");
            pid2=fork();
            if (pid2!=0){
                  wait(NULL);
                  exit(0);
            }
      }

      if (pid2==0){
            printf("Child 2.\n");
            pid3=fork();
            if (pid3!=0){
                  wait(NULL);
                  exit(0);
            }
      }

      if (pid3==0){
            printf("Child 3.\n");
            pid4=fork();
            if (pid4!=0){
                  wait(NULL);
                  exit(0);
            }
      }

      if (pid4==0){
            printf("Child 4.\n");
            exit(0);
      }

      wait(NULL);
      printf("This is the parent.\n");

      return 0;
}
