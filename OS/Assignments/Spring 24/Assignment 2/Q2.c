#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ranlib.h>
#include <time.h>

struct BankAccount{
      int accNum;
      int balance;
};

void withdrawAmount(struct BankAccount* acc){
      int n=acc->balance+1;
      printf("Enter the amount to withdraw: ");
      scanf("%d", &n); 
      while (n>acc->balance){
            printf("The amount should be less than the balance %d: ", acc->balance);
            scanf("%d", &n);     
      }
      acc->balance-=n;
      printf("Your new balance is %d.\n\n", acc->balance);
      
}

int main(){
      int fd[2];
      if (pipe(fd)){
            perror("Pipes not working correctly.\n");
            return 1;
      }
      struct BankAccount account[5];
      for (int i=0;i<5;i++){
            int pid=fork();
            if (pid==0){
                  //child
                  srand(time(NULL));
                  account[i].accNum=i+1;
                  account[i].balance=rand()%10000;
                  printf("Account Number %d has a balance of %d.\n", i+1, account[i].balance);
                  withdrawAmount(&account[i]);
                  exit(0);
            }
            else{
                  //parent
                  wait(NULL);
            }
      }
      
      return 0;
}