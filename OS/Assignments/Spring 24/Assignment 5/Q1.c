#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_ROOMS 3
#define MAX_ROOM_CAPACITY 4  //stores the max capacity of all rooms combine as need not to know whcih room entered by the student

sem_t rooms[NUM_ROOMS], mutex;


void* accessLibraryStudyRooms(void* arg){
    int* a=(int*)arg;
    printf("Student %d is waiting outside the library.\n", *a);
    
    sem_wait(&mutex); //only one may enter the room at a time
    int currRoom=-1, avail=0;
    for (int i=0;i<NUM_ROOMS;i++){
        //trywait only decrements value if space value, if no space available then does no get stuck
        if (sem_trywait(&rooms[i])==0){ //if succesfully locked
            currRoom=i;
            avail=1;
            break;
        }
    }
    if (currRoom==-1){
        currRoom=rand()%3;
    }
    sem_post(&mutex);
    if (avail==0)
        sem_wait(&rooms[currRoom]); //if no seat available then wait outside any room

    printf("Student %d has entered in study room %d.\n", *a, currRoom);
    sleep(rand()%3); //estimated studying time
    
    sem_post(&rooms[currRoom]); //empty rhe room
    printf("Student %d has left room %d.\n", *a, currRoom);
    free(arg);
    sleep(1);
}


int main(){    
    sem_init(&mutex, 0, 1);   
    for (int i=0;i<NUM_ROOMS;i++){
        sem_init(&rooms[i], 0, MAX_ROOM_CAPACITY);   
    }
    int i=0;
    while (i<=20){
        i++;
        pthread_t tid;
        int* a=(int*)calloc(1, sizeof(int));
        *a=i;
        pthread_create(&tid, NULL, accessLibraryStudyRooms, (void*)a);
        sleep(1); //students arrive at fixed intervals
    }

    for (int i=0;i<NUM_ROOMS;i++){
        sem_destroy(&rooms[i]);
    }

    return 0;
}