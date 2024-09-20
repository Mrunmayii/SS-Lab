/*
============================================================================
Name : 9.c
Author : Mrunmayi Shirke
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    // Ignore SIGINT signal
    signal(SIGINT, SIG_IGN);  
    printf("SIGINT is being ignored. Press Ctrl+C\n");

    // 10 seconds of ignoring SIGINT
    sleep(5); 

    // reset SIGINT to custom handler (restores the default behavior after this point)
    signal(SIGINT, SIG_DFL);
    printf("\nRestoring default behavior now\n");

    while (1) {
        printf("Press Ctrl+C again to see default behavior.\n");
        sleep(2);  // Sleep for 2 seconds, waiting for signal
    }

    return 0;
}

/*
OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
SIGINT is being ignored. Press Ctrl+C
^C
^C
^C

Restoring default behavior now
Press Ctrl+C again to see default behavior.
^C


*/
