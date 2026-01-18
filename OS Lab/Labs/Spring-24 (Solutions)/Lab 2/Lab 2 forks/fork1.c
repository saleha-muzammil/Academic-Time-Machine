#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
pid_t pid = fork();
if (pid == -1) {
printf("Error in fork!\n");
return 1;
}
if (pid == 0) {
// Child process
printf("Child Process!\n");
exit(0);
} else {
// Parent process
printf("Parent Process!\n");
wait(NULL);
}

return 0;
}

