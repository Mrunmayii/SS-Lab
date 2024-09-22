/*
============================================================================
Name : 18.c
Author : Mrunmayi Shirke
Description : Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2, pid3;

    // Create 2 pipes
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
   if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }
    
    // Fork the first child for `ls -l`
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
        // Child process 1: `ls -l`
        close(pipe1[0]); // Close reading end of pipe1
        close(STDOUT_FILENO);
        
        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(pipe1[1]); // Close the original writing end of the pipe1
        
        execlp("ls", "ls", "-l", (char *)NULL); // Execute ls -l
        
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    // Fork the second child for `grep`
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork2");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        // Child process 2
        close(pipe1[1]); // Close writing end of pipe1
        close(STDIN_FILENO);
        dup2(pipe1[0], STDIN_FILENO); // Redirect stdin to pipe
        close(pipe1[0]); // Close the original reading end of the pipe2
        
        // Redirect stdout to the second pipe
        dup2(pipe2[1], STDOUT_FILENO);
        //close(pipe1[0]); // Close the original reading end of pipe1
        close(pipe2[1]); // Close the original writing end of pipe2
        
        execlp("grep", "grep", "^d", (char *)NULL); // Execute grep
        
        perror("execlp grep");
        exit(EXIT_FAILURE);
    }
    
    // Fork the third child for `wc'
    pid3 = fork();
    if (pid3 == -1) {
        perror("fork3");
        exit(EXIT_FAILURE);
    }
    
     if (pid3 == 0) {
        // Child process 3: `wc`
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]); // Close writing end
        close(STDIN_FILENO);
        
        dup2(pipe2[0], STDIN_FILENO); // Redirect stdin to pipe
        close(pipe2[0]); // Close the original reading end of the pipe
        
        execlp("wc", "wc", (char *)NULL); // Execute wc
        
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    
    // Parent process: close both ends of the pipe
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for both child processes to complete
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

/* 
OUTPUT

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 18.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
      2      18     118

*/
