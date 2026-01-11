#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>


sem_t semaphore_NS, semaphore_EW, semaphore_ped;
int eastWestPedestrianCrossing=0, northSouthPedestrianCrossing=0;


void pedestrian_crossing(){
    sem_wait(&semaphore_ped);
    if (northSouthPedestrianCrossing==1){
        printf("Pedestrians travelling on the North and South roads...\n");
    }
    else if (eastWestPedestrianCrossing==1){
        printf("Pedestrians travelling on the East and West roads...\n");
    }
    sleep(1);
    sem_post(&semaphore_ped);
}


void traffic_light_NorthSouth(){
    sem_wait(&semaphore_NS);
    printf("North-South Traffic flowing...\n");
    northSouthPedestrianCrossing=0;
    eastWestPedestrianCrossing=1;
    pedestrian_crossing();
    sleep(2);
    printf("North-South Traffic flow stopped...\n");
    sem_post(&semaphore_NS);
}


void traffic_light_EastWest(){
    sem_wait(&semaphore_EW);
    printf("East-West Traffic flowing...\n");
    northSouthPedestrianCrossing=1;
    eastWestPedestrianCrossing=0;
    pedestrian_crossing();
    sleep(2);
    printf("East-West Traffic flow stopped...\n");
    sem_post(&semaphore_EW);
}


int main(){
    //out assumption is that when vehicles ae moving in one direction i.e. North-South they will not turn East or West so the pedestrian crossing will open for both
    sem_init(&semaphore_NS, 0, 1);
    sem_init(&semaphore_EW, 0, 1);
    sem_init(&semaphore_ped, 0, 1);

    while (1){
        traffic_light_EastWest();
        sleep(2);
        traffic_light_NorthSouth();
        sleep(2);
    }

    return 0;
}