#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
      if (mkfifo("Fifo1", 0777)==-1){
            //if not created and not already exist then error
            if (errno!=EEXIST){
                  perror("File not created.\n");
                  return 1;
            }
      }
      //named pipe will only work if there are processes at both the read and the write end
      char arr[100];
      printf("Enter the message: ");
      fgets(arr, sizeof(arr), stdin);
      int fd=open("Fifo1", O_WRONLY);
      if (fd==-1){
            printf("File not opened.\n");
            return 1;
      }
      //sending to Haider.c
      int x=strlen(arr);
      int bytesWritten=write(fd, &x, sizeof(int));
      bytesWritten=write(fd, arr, sizeof(char)*strlen(arr));
      close(fd);
      //reading from Haider.c
      int fd1=open("Fifo1", O_RDONLY);
      if (fd1==-1){
            printf("File not opened.\n");
            return 1;
      }
      int bytesRead=read(fd1, arr, sizeof(char)*strlen(arr));
      printf("%s", arr);

      return 0;
}