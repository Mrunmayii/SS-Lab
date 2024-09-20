/*
============================================================================
Name : 6.c
Author : Mrunmayi Shirke
Description: Write a simple program to create three threads
Date: 13 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>


void* thread_function(void* arg) {
    printf("This is thread %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];      
    
    for(long i = 0; i < 3; i++) {
    //returns +ve val on failure 0 on success
        if(pthread_create(&threads[i], NULL, thread_function, (void*)i)) {
            printf("Error creating thread %ld\n", i + 1);
            return 1;
        }
    }

    // Join the threads (wait for them to finish)
    for(long i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 6.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
This is thread 0
This is thread 1
This is thread 2
*/
