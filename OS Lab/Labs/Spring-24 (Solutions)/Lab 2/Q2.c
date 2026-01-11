#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>


int isPrime(int n){
      for (int i=2;i<=n/2;i++){
            if (n%i==0){
                  return 0;
            }
      }
      return 1;      
}


int main(int argc, char* arg[]){
      //argc is the count of arguements
      //arg is the array that stores the parameters in the form of character array/strings
      //at index 0 we have the name of the executable followed by all the parameters seperated by spaces
      //arg is a NULL temrinated string
      int pid=fork();
      int pid1=fork();

      //       P
      //      / \
      //     P   C
      //    /\   /\
      //   P C1 C C2
      //C1 and C2 will be the child processes here

      if (pid==0 && pid1==0){
            //node  C2
            if (argc>=2){
                  //we have atleast one additional parameter to calculate square
                  int n=atoi(arg[1]);
                  int square=n*n;
                  printf("The square of %d is %d.\n", n, square);
            }
            exit(0); //exit with succes status
      }

      if (pid1==0 && pid!=0){
            //node C1
             if (argc>=3){
                  //we have atleast two parameters so can check if the second param is prime or not
                  if (isPrime(atoi(arg[2]))==0){
                        printf("%d is not a prime.\n", atoi(arg[2]));
                  }
                  else{
                        printf("%d is a prime.\n", atoi(arg[2]));
                  }
            }
            exit(0);
      }
      //parent processes wait for the child processes to terminate
      wait(NULL);
      wait(NULL);

      return 0;
}

