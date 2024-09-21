/*
============================================================================
Name : 1c.c
Author : Mrunmayi Shirke
Description :  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
 c. ITIMER_PROF
Date: 7 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int sig) {
    printf("ITIMER_PROF alarm triggered\n");
}

int main() {
    struct itimerval timer;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    signal(SIGPROF, handle_alarm);
    
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(0);
    }

   
    while (1) {
        for (volatile int i = 0; i < 100000000; i++);  
    }

    return 0;
}

/*

OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 1c.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 1c.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
ITIMER_PROF alarm triggered
ITIMER_PROF alarm triggered
ITIMER_PROF alarm triggered
^C

*/
