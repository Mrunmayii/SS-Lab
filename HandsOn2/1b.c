/*
============================================================================
Name : 1b.c
Author : Mrunmayi Shirke
Description :  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
 a. ITIMER_VIRTUAL
Date: 7 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include<time.h>

void handle_alarm(int sig) {
	
    time_t curr_time;
    struct tm *local_time;
    time(&curr_time);
    local_time=localtime(&curr_time);
    printf("Curr time is:%s ", asctime(local_time));

    printf("ITIMER_VIRTUAL alarm triggered!\n");
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    signal(SIGVTALRM, handle_alarm);

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(1);
    }

    while(1) {
        for(int i=0; i<10000; i++); //for loop will consume cpu time for itimer virtual
				   //to work.
    }

    return 0;
}


/*
output:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 1b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 1b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Curr time is:Sat Sep 7 20:00:14 2024
 ITIMER_VIRTUAL alarm triggered!
Curr time is:Sat Sep 7 20:00:24 2024
 ITIMER_VIRTUAL alarm triggered!
Curr time is:Sat Sep 7 20:00:34 2024
 ITIMER_VIRTUAL alarm triggered!
^C

*/
