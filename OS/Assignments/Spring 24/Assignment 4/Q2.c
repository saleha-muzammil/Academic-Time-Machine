#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>


/*
A barbershop consists of a waiting room with n chairs, and the barber room containing the barber chair. If there are no customers to be served, the barber goes to sleep. If a customer enters the barbershop and all chairs are occupied, then the customer leaves the shop. If the barber is busy, but chairs are available, then the customer sits in one of the free chairs and wait. If the barber is asleep, the customer wakes up the barber. Write a C program using semaphores to coordinate the barber and the customers
*/

//n chairs is shop(n threads can be supported at max)
//if no customer then barber goes to sleep
//if barber sleeps then customer wakes up the barber
//if chair available then customer sits else leaves

int maxCount=0;

typedef struct {
    int count;
    int value;
} semaphores;

void semaphoreInit(semaphores* s, int val, int cnt){
    s->value=val;
    s->count=cnt;
}

void semaphoreWait(semaphores* s, int num){
    if (s->count==maxCount){
        printf("No seats available. Customer %d leaving.\n\n", num);
        pthread_exit(0);
    }
    s->count++;
    printf("Customer %d is waiting.\n", num);
    while (s->value<=0); //busy waiting
    s->value--;
    s->count--;
}

void semaphoreSignal(semaphores* s, int num){
    printf("Customer %d is leaving.\n\n", num);
    s->value++;
}

semaphores s1;

void* serveCustomer(void* arg){
    int* customerNum=(int*)arg;
    //The main issue here is that there are no memeory locks so even though we can ensure that
    //no two customer enter the CS at once but the reordering of instructions in the signal and wait functions means that the print statement may be delayed before it actually gets executed. hence, it gives the impression that the order of execution is incorrect. SO one of the solution is to use hardware synchronization techniques like memory barriers, atomic variables or hardware based instruction like testandSet() and compAndSwap()
    semaphoreWait(&s1, *customerNum);
    // store(&ready, 1, RELAXED);
    printf("Customer %d is now getting a haircut.\n", *customerNum);
    sleep(rand()%3);
    semaphoreSignal(&s1, *customerNum);
    pthread_exit(0);
}

int main(){
    //take user input of max chairs in the shop
    printf("Enter the max number of customers that the barber can accomodate at any given time:");
    scanf("%d", &maxCount);
    semaphoreInit(&s1, 1, 0);
    setvbuf(stdout, NULL, _IONBF, 0); //sets stdout to line buffered
    //customer arrive indefinitely(infinite loop). Each customer represented by a thread
    int currCount=0;
    while (1){
        currCount++;
        pthread_t customer;
        int* a=(int*)calloc(1, sizeof(int));
        *a=currCount;
        if (pthread_create(&customer, NULL, serveCustomer, (void*)a)==-1){
            return 2;
        }
        sleep(rand()%3);
    }
    // pthread_t customers[4];
    // for (int i=0;i<4;i++){
    //     sleep(rand()%3);
    //     if (pthread_create(&customers[i], NULL, serveCustomer, NULL)==-1){
    //         return 2;
    //     }
    // }
    // for (int i=0;i<4;i++){
    //     pthread_join(customers[i], NULL);
    // }

    return 0;
}

