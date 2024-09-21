/*
============================================================================
Name : 15.c
Author : Mrunmayi Shirke
Description : Write a simple program to send some data from parent to the child process.
Date: 20 Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main() {

    int pipefd[2];
    pid_t pid;
    const char *message = "Hello from parent process";
    char buffer[50];

    
    pipe(pipefd);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    else if (pid == 0) {
        // Child process
        close(pipefd[1]); 
        read(pipefd[0], buffer, strlen(message)); 
        printf("Child received: %s\n", buffer);
        close(pipefd[0]); 
    } 
    else {
        close(pipefd[0]); 
        write(pipefd[1], message, strlen(message)); 
        close(pipefd[1]);
    }

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 15.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Child received: Hello from parent process
*/
