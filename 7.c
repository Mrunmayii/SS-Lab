/*
============================================================================
Name : 7.c
Author : Mrunmayi Shirke
Description: Write a simple program to print the created thread ids.
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>


void* thread_function(void* arg) {
    printf("This is thread %ld\n", (long)arg);
    pthread_t id = pthread_self();
    printf("ID is: %ld\n", (long)id);
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
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
This is thread 0
ID is: 139709372167872
This is thread 1
ID is: 139709363775168
This is thread 2
ID is: 139709355382464

*/
