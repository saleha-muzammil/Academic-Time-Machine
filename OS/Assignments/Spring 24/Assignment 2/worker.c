#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
      int fd=open("Fifo2", O_RDONLY);
      if (fd==-1){
            printf("File not opened.\n");
            return 1;
      }
      //reading from sender.c
      char operator;
      int num1,num2;
      int bytesRead=read(fd, &operator, sizeof(char));
      printf("%c\n", operator);
      bytesRead=read(fd, &num1, sizeof(int));
      printf("%d\n", num1);
      bytesRead=read(fd, &num2, sizeof(int));
      printf("%d\n", num2);
      close(fd);
      //processing it
      float ans=0;
      if (operator=='+'){
        ans=num1+num2;
      }
      else if(operator=='-'){
        ans=num1-num2;
      }
      else if(operator=='*'){
        ans=num1*num2;
      }
      else if(operator=='/'){
        ans=(float)num1/num2;
      }

      //sending back to sender.c
      int fd1=open("Fifo2", O_WRONLY);
      if (fd1==-1){
        printf("File not opened.\n");
        return 1;
      }
      int bytesWritten=write(fd1, &ans, sizeof(float));
      close(fd1);
      
      return 0;
}