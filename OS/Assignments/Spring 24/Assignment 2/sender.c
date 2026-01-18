#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
      //code 0777 provides open access to the fifo file/named pipe to anyone
      if (mkfifo("Fifo2", 0777)==-1){
            //if not created and not already exist then error
            if (errno!=EEXIST){
                  perror("File not created.\n");
                  return 1;
            }
      }
      //named pipe will only work if there are processes at both the read and the write end
      //taking the input
      char operator, arr[10];
      int oper1, oper2;
      printf("Enter the operator: ");
      fgets(arr, sizeof(arr), stdin);
      operator=arr[0];
      printf("Enter the first operand: ");
      scanf("%d", &oper1);
      printf("Enter the second operand: ");
      scanf("%d", &oper2);
      int fd=open("Fifo2", O_WRONLY);
      if (fd==-1){
            printf("File not opened.\n");
            return 1;
      }
      //sending to worker.c
      int bytesWritten=write(fd, &operator, sizeof(char));
      bytesWritten=write(fd, &oper1, sizeof(int));
      bytesWritten=write(fd, &oper2, sizeof(int));
      close(fd);
      //reading from worker.c
      int fd1=open("Fifo2", O_RDONLY);
      if (fd1==-1){
            printf("File not opened.\n");
            return 1;
      }
      float sum=0;
      int bytesRead=read(fd1, &sum, sizeof(float));
      printf("The sum is %.2f.\n", sum);

      return 0;
}