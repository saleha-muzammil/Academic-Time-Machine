#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 0

int main(){
int pid=fork();
int pid1=fork();
int pid2=fork();
//3 forks so 8 total processes->4 parent and 4 child
int p1=0,p2=0,p3=0,p4=0;

//child proceses
if (pid!=0 && pid1!=0 && pid2==0){
printf("This is the first child process.\n");
exit(0);
}
else if (pid!=0 && pid1==0 && pid2==0){
printf("This is the second child process.\n");
exit(0);
}
else if (pid==0 && pid1!=0 && pid2==0){
printf("This is the third child process.\n");
exit(0);
}
else if (pid==0 && pid1==0 && pid2==0){
printf("This is the fourth child process.\n");
exit(0);
}
//parent
if (pid!=0 && pid1!=0 && pid2!=0){
printf("This is the first parent process.\n");
wait(NULL);
}
else if (pid!=0 && pid1==0 && pid2!=0){
printf("This is the second parent process.\n");
wait(NULL);
}
else if (pid==0 && pid1!=0 && pid2!=0){
printf("This is the third parent process.\n");
wait(NULL);
}
else if (pid==0 && pid1==0 && pid2!=0){
printf("This is the fourth parent process.\n");
wait(NULL);
}
//as there are 4 wait command so each parent will stop at their respective wait command
//until their child their respective child has been terminated
// wait(NULL);
// wait(NULL);
// wait(NULL);
// wait(NULL);


return 0;
}