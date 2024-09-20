/*
============================================================================
Name : 8e.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
 e. SIGALRM (use setitimer system call)
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void sigHandler(int sig){
  printf("Caught signal %d=SIGALRM(using setitimer)\n", sig);
  exit(1);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, sigHandler);
    
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;


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
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8d.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 14=SIGALRM(using setitimer)


*/
