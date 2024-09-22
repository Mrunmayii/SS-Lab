/*
============================================================================
Name : 32.c
Author : Mrunmayi Shirke
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore.
Date: 21st Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <errno.h>

// Define union for semctl's semun argument
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Semaphore operations
void sem_wait(int sem_id, int sem_num) {
    struct sembuf sb;
    sb.sem_num = sem_num;
    sb.sem_op = -1; // Wait (P operation)
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

void sem_signal(int sem_id, int sem_num) {
    struct sembuf sb;
    sb.sem_num = sem_num;
    sb.sem_op = 1; // Signal (V operation)
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

// Function to create shared memory for ticket numbers
int* create_shared_ticket() {
    int shmid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    int *ticket_num = (int *)shmat(shmid, NULL, 0);
    if (ticket_num == (int *)-1) {
        perror("shmat");
        exit(1);
    }
    *ticket_num = 1;  // Initialize the ticket number
    return ticket_num;
}

// Ticket number generation process
void ticket_process(int sem_id, int *ticket_num) {
    for (int i = 0; i < 5; i++) {
        sem_wait(sem_id, 0); // Wait on semaphore
        printf("Process %d generated ticket number: %d\n", getpid(), *ticket_num);
        (*ticket_num)++;
        sem_signal(sem_id, 0); // Signal semaphore
        sleep(1);
    }
    exit(0);
}

// Resource usage process
void resource_process(int sem_id, int resource_num) {
    sem_wait(sem_id, resource_num);  // Wait on the resource semaphore
    printf("Process %d using resource %d\n", getpid(), resource_num);
    sleep(2); // Simulate using resource
    printf("Process %d finished using resource %d\n", getpid(), resource_num);
    sem_signal(sem_id, resource_num);  // Release the resource
    exit(0);
}

// Main program
int main() {
    int sem_id;
    int *ticket_num;

    // Create a semaphore set with 3 semaphores (1 for ticket, 2 for resources)
    sem_id = semget(IPC_PRIVATE, 3, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphores
    union semun sem_attr;
    sem_attr.val = 1;
    semctl(sem_id, 0, SETVAL, sem_attr); // Initialize ticket semaphore to 1
    semctl(sem_id, 1, SETVAL, sem_attr); // Initialize resource 0 semaphore to 1
    semctl(sem_id, 2, SETVAL, sem_attr); // Initialize resource 1 semaphore to 1

    // Create shared memory for ticket numbers
    ticket_num = create_shared_ticket();

    // Create ticket generation process
    pid_t pid1 = fork();
    if (pid1 == 0) {
        ticket_process(sem_id, ticket_num);
    }

    // Create resource 0 process
    pid_t pid2 = fork();
    if (pid2 == 0) {
        resource_process(sem_id, 1);
    }

    // Create resource 1 process
    pid_t pid3 = fork();
    if (pid3 == 0) {
        resource_process(sem_id, 2);
    }

    // Wait for child processes to finish
    int status;
    while (wait(&status) > 0);

    // Clean up shared memory
    shmctl(shmget(IPC_PRIVATE, sizeof(int), 0666), IPC_RMID, NULL);

    // Remove semaphore set
    if (semctl(sem_id, 0, IPC_RMID, sem_attr) == -1) {
        perror("semctl IPC_RMID");
        exit(1);
    }

    printf("All processes finished. Semaphore removed.\n");

    return 0;
}

