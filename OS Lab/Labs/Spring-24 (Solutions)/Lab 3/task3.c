#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
      int fd1[2], fd2[2];
      if ((pipe(fd1))<0 || pipe(fd2)<0){
            perror("Pipes error: ");
            return 2;
      }
      else{
            //fd1 will be used to send data from parent to child
            //fd2 will be vice versa
            //fd[0]->read, fd[1]->write
            int pid=fork();
            if (pid==0){
                  //child process
                  close(fd1[1]);
                  int valReceived;
                  int bytes=read(fd1[0], &valReceived, sizeof(int));
                  close(fd1[0]);
                  // printf("%d", valReceived);
                  int square=valReceived*valReceived;
                  close(fd2[0]);
                  int bytes1=write(fd2[1], &square, sizeof(int));
                  close(fd2[1]);
                  exit(0);
            }
            else{
                  //parent process
                  int num;
                  printf("Enter a number: ");
                  scanf("%d", &num);
                  close(fd1[0]);
                  //sends the data to the child process to compute sum
                  int bytes=write(fd1[1], &num, sizeof(int));
                  close(fd1[0]); //close write end after use
                  close(fd2[1]);
                  int square=0;
                  wait(NULL); //waits for the child process to finish
                  int bytes1=read(fd2[0], &square, sizeof(int));
                  close(fd2[0]); //close read end after use
                  printf ("The square of %d is %d\n.", num, square);
            }
      }
      return 0;
}
