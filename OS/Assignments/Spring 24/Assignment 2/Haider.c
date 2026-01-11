#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
      int fd=open("Fifo1", O_RDONLY);
      if (fd==-1){
            printf("File not opened.\n");
            return 1;
      }
      //reading from Mahad.c
      char arr[100];
      int n=0;
      int bytesRead=read(fd, &n, sizeof(int));
      bytesRead=read(fd, arr, sizeof(int)*n);
      close(fd);
    //   printf("%s", arr);
      //processing it
      for (int i=0;i<n;i++){
        //convert lowercase to uppercase
        if (arr[i]>=97 && arr[i]<=127){
            arr[i]-=32;
        }
        //convert uppercase to lowercase
        else if (arr[i]>=65 && arr[i]<=90){
            arr[i]+=32;
        }
      }
    //   printf("%s", arr);
      //sending back to Mahad.c
      int fd1=open("Fifo1", O_WRONLY);
      if (fd1==-1){
        printf("File not opened.\n");
        return 1;
      }
      int bytesWritten=write(fd1, arr, sizeof(char)*n);
      close(fd);

      return 0;
}