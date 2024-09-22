/*
============================================================================
Name : 17c.c
Author : Mrunmayi Shirke
Description : Write a program to execute ls -l | wc.
c. use fcntl
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[0]);
        close(STDOUT_FILENO);
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);

        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(pipefd[1]);
        close(STDIN_FILENO);
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}

/*

OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 17c.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
      8      65     411
*/
