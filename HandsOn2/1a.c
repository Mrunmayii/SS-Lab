/*
============================================================================
Name : 1a.c
Author : Mrunmayi Shirke
Description :  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
 a. ITIMER_REAL
Date: 7 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>


void handle_alarm(int sig) {
    printf("ITIMER_REAL alarm triggered!\n");
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    signal(SIGALRM, handle_alarm);

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(EXIT_FAILURE);
    }

    while(1) {
        pause(); 
    }

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab/HandsOn2$ vim 1a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab/HandsOn2$ gcc 1a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab/HandsOn2$ ./a.out
ITIMER_REAL alarm triggered!
ITIMER_REAL alarm triggered!
ITIMER_REAL alarm triggered!
^C
*/
