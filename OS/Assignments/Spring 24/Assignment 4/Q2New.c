#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 5

sem_t customers;    
sem_t barber;      
sem_t mutex;        
int num_waiting = 0;  

void *barber_function(void *arg)
{
    while (1)
    {
        sem_wait(&customers);  
        sem_wait(&mutex);
        num_waiting--;
        sem_post(&mutex);
        sem_post(&barber);      
        printf("Barber is cutting hair\n");
        sleep(2);              
        printf("Barber finished cutting hair\n");
    }
}

void *customer_function(void *arg)
{
    int id = *((int *)arg);
    sem_wait(&mutex);
    if (num_waiting < NUM_CHAIRS)
    {
        num_waiting++;
        sem_post(&customers);  
        sem_post(&mutex);
        sem_wait(&barber);    
        printf("Customer %d  haircut\n", id);
    }
    else
    {
        sem_post(&mutex);      
        printf("Customer %d left, all chairs are occupied\n", id);
    }
}

int main() {
    pthread_t barber_thread;
    pthread_t customer_threads[NUM_CHAIRS];
    sem_init(&customers, 0, 0);
    sem_init(&barber, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&barber_thread, NULL, barber_function, NULL);
    int i, customer_ids[NUM_CHAIRS];
    for (i = 0; i < NUM_CHAIRS; i++) {
        customer_ids[i] = i + 1;
        pthread_create(&customer_threads[i], NULL, customer_function, &customer_ids[i]);
        sleep(1);  
    }

    pthread_join(barber_thread, NULL);
    for (i = 0; i < NUM_CHAIRS; i++) {
        pthread_join(customer_threads[i], NULL);
    }

    sem_destroy(&customers);
    sem_destroy(&barber);
    sem_destroy(&mutex);

    return 0;
}