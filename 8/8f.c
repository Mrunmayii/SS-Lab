/*
============================================================================
Name : 8f.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
 f. SIGVTALRM (use setitimer system call)
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigHandler(int sig){
  printf("Caught signal %d=SIGVTALRM(using setitimer)\n", sig);
  exit(1);
}


int main() {
    struct itimerval timer;
    signal(SIGVTALRM, sigHandler);
    
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;


    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(1);
    }

    while(1) {
        for(int i=0; i<100000000; i++); 
        //for loop will consume cpu time for itimer virtual to work.
    }

    return 0;
}


/*
output:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8f.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 26=SIGVTALRM(using setitimer)
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ 


*/
