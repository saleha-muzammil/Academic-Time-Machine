#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){
if (fork() || (fork() && fork()) || fork()){
    printf("Process Created!\n");
}
else{
    wait(NULL);
}

return 0;
}
