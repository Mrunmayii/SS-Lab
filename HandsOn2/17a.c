/*
============================================================================
Name : 17a.c
Author : Mrunmayi Shirke
Description : Write a program to execute ls -l | wc.
a. use dup
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child for `ls -l`
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process 1: `ls -l`
        close(pipefd[0]); // Close reading end of the pipe

        // Duplicate the pipe's writing end to stdout
        close(STDOUT_FILENO);          // Close stdout
        if (dup(pipefd[1]) == -1) {    // Duplicate pipefd[1] to lowest available fd (stdout)
            perror("dup");
            exit(EXIT_FAILURE);
        }
        close(pipefd[1]); // Close the original writing end of the pipe
        
        // Execute `ls -l`
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp");   //only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Fork the second child for `wc`
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process 2: `wc`
        close(pipefd[1]); // Close writing end of the pipe

        // Duplicate the pipe's reading end to stdin
        close(STDIN_FILENO);           // Close stdin
        if (dup(pipefd[0]) == -1) {    // Duplicate pipefd[0] to lowest available fd (stdin)
            perror("dup");
            exit(EXIT_FAILURE);
        }
        close(pipefd[0]); // Close the original reading end of the pipe
        
        // Execute `wc`
        execlp("wc", "wc", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Parent process: close both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both child processes to complete
    wait(NULL);
    wait(NULL);

    return 0;
}


/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 17a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
      6      47     299
*/




