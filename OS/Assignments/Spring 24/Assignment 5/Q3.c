#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

#define numPhilosphers 5
sem_t chopsticks[numPhilosphers], mutex;
int currCount=0;


/*         P1
     P5 /-----\ P2
       |       |
     P4 \-----/ P3

     5 phils numbered from 0 to 1 sitting on a table and haring 5 chopsticks
     each can pick a chopstick on its right and left and eat when have both
     if not available then waits until available
*/


void* philospher(void* arg){
    int* i=(int*)arg;
    sem_wait(&chopsticks[*i]);
    sem_wait(&chopsticks[(*i+1)%numPhilosphers]);
    printf("Philospher %d eating with chopsticks %d and %d.\n", *i+1, *i+1, ((*i+1)%5)+1);
    //eating
    sleep(rand()%2);
    printf("Philospher %d done with chopsticks %d and %d.\n", *i+1, *i+1, ((*i+1)%5)+1);
    sem_post(&chopsticks[*i]);
    sem_post(&chopsticks[(*i+1)%numPhilosphers]);
    //thinking
    sleep(rand()%2);
    free(i); //deallocate the dynamic parameter
}


int main(){
    for (int i=0;i<numPhilosphers;i++){
        sem_init(&chopsticks[i], 0, 1);
    }
    sem_init(&mutex, 0, 1); //for mutual exclusion of currCount
    while (1){
        currCount++;
        pthread_t tid;
        int* a=(int*)calloc(1, sizeof(int));
        *a=(currCount%numPhilosphers);
        pthread_create(&tid, NULL, philospher, a);
        sleep(2); //can be used to random here to make the philosphers wait here
    }
    sleep(3); //main thread waits for the other thread to terminate
    for (int i=0;i<numPhilosphers;i++){
        sem_destroy(&chopsticks[i]);
    }
    
    return 0;
}