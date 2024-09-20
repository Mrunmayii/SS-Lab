/*
============================================================================
Name : 11.c
Author : Mrunmayi Shirke
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 20 Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sa_ignore, NULL);
    printf("SIGINT is being ignored. Press Ctrl+C\n");

    sleep(5);

    sa_default.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa_default, NULL);
    printf("Restoring default behavior now. Press Ctrl+C \n");

    sleep(5);

    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 11.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
SIGINT is being ignored. Press Ctrl+C
^C
^C
^C
Restoring default behavior now. Press Ctrl+C 
^C
*/
