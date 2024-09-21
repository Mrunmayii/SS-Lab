/*
============================================================================
Name : 31a.c
Author : Mrunmayi Shirke
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
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


    key = ftok("counting_sem", 'a'); 
    semid = semget(key, 1, 0666 | IPC_CREAT); 

    if (semid == -1) {
        perror("semget failed");
        exit(EXIT_FAILURE);
    }

    if (semctl(semid, 0, SETVAL, 5) == -1) {
        perror("semctl initialization failed");
        exit(EXIT_FAILURE);
    }

    printf("Counting semaphore created and initialized to 5 (representing available resources).\n");

    return 0;
}

/*
OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 31b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Counting semaphore created and initialized to 5 (representing available resources).
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ^C

*/
