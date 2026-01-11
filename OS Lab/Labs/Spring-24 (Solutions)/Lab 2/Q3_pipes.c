#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>


int main(int argc, char* arg[]){
      //takes an array as input from the user and 3 child do 3 tasks
      //1-sum print, 2-average print, 3-max print
      int* buff=(int*)calloc(argc-1, sizeof(int));
      int i=1;
      bool arrEnd=false;
      while (i<argc && !arrEnd){
            if (strcmp(arg[i],"$")==0){
                  arrEnd=true;
            }
            else{
                  buff[i-1]=atoi(arg[i]);
            }
            i++;
      }
      i-=2; //number of elements in the buffer
      int fd[2];
      if (pipe(fd)==-1){
            perror("pipe:");
      }
      //even though 3 forks must be used to have 3 children(out of 4) as 2 forks have max 2 children
      int pid=fork();
      int pid1=fork();
         //       P
         //      / \
         //     P   C
         //    /\   /\
         //   P C1 C C2
         if (pid==0 && pid1==0){
            //C2
            //sum
            int sum=0;
            for (int j=0;j<i;j++){
                  sum+=buff[j];
            }
            close(fd[0]);//closes the read end
            int bytesWritten=write(fd[1], &sum, sizeof(int));
            close(fd[1]);
            printf("The sum is %d.\n", sum);
         }
         else if(pid==0 && pid1!=0){
            //C
            //average
            int sum=0;
            close(fd[1]);
            int bytesRead=read(fd[0], &sum, sizeof(int));
            close(fd[0]);
            printf("The average is %f\n", (sum/(float)i));
         }
         else if(pid!=0 && pid1==0){
            //C1
            //max
            int maxVal=INT_MIN;
            for (int j=0;j<i;j++){
                  if (buff[j]>maxVal){
                        maxVal=buff[j];
                  }
            }
            printf("The max value is %d.\n", maxVal);
         }

      return 0;
}
