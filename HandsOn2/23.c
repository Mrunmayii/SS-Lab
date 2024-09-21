/*
============================================================================
Name : 23.c
Author : Mrunmayi Shirke
Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 21st Sep, 2024
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>

int main() {
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of files that can be opened within a process: %ld\n", max_files);


    int pipe1[2];

    if (pipe(pipe1) == 0) {
      	long pipe_size = fpathconf( pipe1[0], _PC_PIPE_BUF );
      	printf("Size of pipe(circular buffer): %ld bytes\n", pipe_size);
      
    close(pipe1[0]);
      	close(pipe1[1]);
    } 
    else {
      	perror("Error creating pipe");
    }

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Maximum number of files that can be opened within a process: 1024
Size of pipe(circular buffer): 4096 bytes
*/
