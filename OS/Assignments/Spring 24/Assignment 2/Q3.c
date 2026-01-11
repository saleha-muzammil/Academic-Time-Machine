#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>


int isPrime(int n){
      for (int i=2;i<=n/2;i++){
            if (n%i==0){
                  return 0; //not a prime
            }
      }
      return 1; //is a prime
}


int main(){
      int fd[2];
      if (pipe(fd)==-1){
            perror("Pipes: ");
      }
      else{
            //child
            int pid=fork();
            if (pid==0){
                  //child
                  close(fd[1]);
                  int n=0;
                  int bytesRead=read(fd[0], &n, sizeof(int));
                  close(fd[0]);
                  for (int i=2;i<=n;i++){
                        if (isPrime(i)==1){
                              printf("%d  ", i);
                        }
                  }
                  exit(0);
            }
            else{
                  //parent
                  printf("Enter the max number to search the primes: ");
                  int n;
                  scanf("%d", &n);
                  close(fd[0]);
                  int bytesWritten=write(fd[1], &n, sizeof(int));
                  close(fd[1]);
                  wait(NULL);
            }
      }

      return 0;
}

