#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_STUDENTS 10 // Number of students trying to enter the library
#define NUM_ROOMS 3     // Number of study rooms in the library
#define ROOM_CAPACITY 4 // Capacity of each study room

sem_t library;          // Semaphore for controlling access to the library
sem_t room_semaphores[NUM_ROOMS]; // Semaphores for each study room

void *student(void *id) {
    int student_id = *((int *)id);

    // Try to enter the library
    sem_wait(&library);
    printf("Student %d enters the library.\n", student_id);

    // Try to enter a study room
    int room_num = -1;
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (sem_trywait(&room_semaphores[i]) == 0) {
            room_num = i;
            printf("Student %d occupies study room %d.\n", student_id, room_num);
            break;
        }
    }

    if (room_num == -1) {
        printf("Student %d waits for a study room to become available.\n", student_id);
        for (int i = 0; i < NUM_ROOMS; i++) {
            sem_wait(&room_semaphores[i]); // Wait for any room to become available
            if (sem_trywait(&room_semaphores[i]) == 0) {
                room_num = i;
                printf("Student %d occupies study room %d.\n", student_id, room_num);
                break;
            }
        }
    }

    // Simulate studying
    printf("Student %d is studying...\n", student_id);
    sleep(2); // Simulated studying time

    // Leave the study room
    sem_post(&room_semaphores[room_num]);
    printf("Student %d leaves study room %d.\n", student_id, room_num);

    // Leave the library
    sem_post(&library);
    printf("Student %d leaves the library.\n", student_id);

    pthread_exit(NULL);
}

int main() {
    pthread_t students[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

    // Initialize semaphores
    sem_init(&library, 0, NUM_ROOMS); // Initialize library semaphore to number of rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        sem_init(&room_semaphores[i], 0, ROOM_CAPACITY); // Initialize room semaphores to room capacity
    }

    // Create student threads
    for (int i = 0; i < NUM_STUDENTS; i++) {
        student_ids[i] = i + 1;
        pthread_create(&students[i], NULL, student, (void *)&student_ids[i]);
    }

    // Join student threads
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&library);
    for (int i = 0; i < NUM_ROOMS; i++) {
        sem_destroy(&room_semaphores[i]);
    }

    return 0;
}
