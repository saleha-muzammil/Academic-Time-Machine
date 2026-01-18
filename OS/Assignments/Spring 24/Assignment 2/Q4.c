#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
      int fd1[2], fd2[2];
      if (pipe(fd1)==-1 || pipe(fd2)==-1){
            perror("Pipes: ");
      }
      else{
            int pid=fork();
            if (pid==0){
                  //child
                  int* arr, n=0;
                  close(fd1[1]);
                  //reading the data from the parent
                  int bytesRead=read(fd1[0], &n, sizeof(int));
                  arr=(int*)calloc(n, sizeof(int));
                  for (int i=0;i<n;i++){
                        bytesRead=read(fd1[0], &arr[i], sizeof(int));
                  }
                  close(fd1[0]);
                  //finding sum
                  int sum=0;
                  for (int i=0;i<n;i++){
                        sum+=arr[i];
                  }
                  //sending the sum back to the parent
                  close(fd2[0]);
                  int bytesWritten=write(fd2[1], &sum, sizeof(int));
                  close(fd2[1]);
                  free(arr);
                  exit(0);
            }
            else{
                  //parent
                  //input from the user
                  int* arr, n;
                  printf("Enter the size of the array: ");
                  scanf("%d", &n);
                  arr=(int*)calloc(n, sizeof(int));
                  for (int i=0;i<n;i++){
                        printf("%d: ", i+1);
                        scanf("%d", &arr[i]);
                  }
                  //transferring to the child using pipe
                  close(fd1[0]);
                  int bytesWritten=write(fd1[1], &n, sizeof(int));
                  for (int i=0;i<n;i++){
                        bytesWritten=write(fd1[1], &arr[i], sizeof(int));
                  }
                  close(fd1[1]);
                  //receiving the sum from the child process
                  close(fd2[1]);
                  int sum=0;
                  int bytesRead=read(fd2[0], &sum, sizeof(int));
                  printf("the sum of the array elements is %d.\n", sum);
                  close(fd2[0]);
                  wait(NULL);
                  free(arr);
            }
      }
      return 0;
}