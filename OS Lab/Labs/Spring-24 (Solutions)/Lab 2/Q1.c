#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
      printf("Enter a number to check if even or odd: ");
      int n=10;
      scanf("%d", &n);
      bool isEven=false;
      if (n%2==0){
            isEven=true;
      }
      int pid = fork();

      if (pid==0){
            if (isEven==true){
                  printf("The number is Even.\n");
            }
            else{
                  printf("The number id Odd.\n");
            }
      }
      else{
            wait(NULL); //parent waits for child to terminate to prevent orphan process
      }

      return 0;
}
