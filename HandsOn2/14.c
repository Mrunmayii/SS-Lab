/*
============================================================================
Name : 14.c
Author : Mrunmayi Shirke
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int pipefd[2]; 
    char buffer[100]; 
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    const char *msg = "Hello from the main process!";
    write(pipefd[1], msg, strlen(msg)+1); 
    close(pipefd[1]); 

    read(pipefd[0], buffer, sizeof(buffer));  
    printf("Received: %s\n", buffer);
    close(pipefd[0]); 

    return 0;
}

/*
output:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 14.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Received: Hello from the main process!

*/
