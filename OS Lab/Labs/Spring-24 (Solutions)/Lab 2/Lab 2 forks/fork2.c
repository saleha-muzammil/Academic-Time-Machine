#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){
int i=0;
for (i=0;i<3;i++){
pid_t pid=fork();
if (pid==-1){
printf("Error in fork!\n");
return 1;
}
if (pid==0){
printf("Child:%i\n", i);
exit(0);
}
else{
wait(NULL);
}
}

return 0;
}
