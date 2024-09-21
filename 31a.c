/*
============================================================================
Name : 31a.c
Author : Mrunmayi Shirke
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 21 September, 2024
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

int main() {
    key_t key;
    int semid;

    key = ftok("binary_sem", 65); 

    semid = semget(key, 1, 0666 | IPC_CREAT); 

    if (semid == -1) {
        perror("semget failed");
        exit(EXIT_FAILURE);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl initialization failed");
        exit(EXIT_FAILURE);
    }

    printf("Binary semaphore created and initialized to 1 (unlocked).\n");

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 31a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Binary semaphore created and initialized to 1 (unlocked).
*/
