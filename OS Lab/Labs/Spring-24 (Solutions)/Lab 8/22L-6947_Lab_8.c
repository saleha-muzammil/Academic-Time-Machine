#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>


int laps, lapTime;

void displayTotalTime(){
    printf("The total time is %d.\n", laps*lapTime);
}

//SIGCHILS is generated when a child program temrinates
void signal_Handler_SIGCHLD(int sig){
    printf("SIGCHLD recieved.\n");
    displayTotalTime();
    return;
}


int main(){
    printf("Enter the number of laps:");
    scanf("%d", &laps);
    printf("Enter the lap time:");
    scanf("%d", &lapTime);

    signal(SIGCHLD, signal_Handler_SIGCHLD);

    int pid=fork();
    if (pid==0){
        //child
        int i=1;
        while (i<=laps){
            sleep(lapTime);
            printf("Lap %d completed.\n", i);
            i++;
        }
        exit(0); //terminates the child process
    }
    else{
        //parent
        wait(NULL);
    }

    return 0;
}
