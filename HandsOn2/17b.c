/*
============================================================================
Name : 17b.c
Author : Mrunmayi Shirke
Description : Write a program to execute ls -l | wc.
b. use dup2
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
        close(pipefd[0]); // Close reading end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(pipefd[1]); // Close the original writing end of the pipe
        execlp("ls", "ls", "-l", (char *)NULL); // Execute ls -l
        perror("execlp");
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
        close(pipefd[1]); // Close writing end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe
        close(pipefd[0]); // Close the original reading end of the pipe
        execlp("wc", "wc", (char *)NULL); // Execute wc
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
OUTPUT

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 17b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
      7      56     355
*/
