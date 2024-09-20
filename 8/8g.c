/*
============================================================================
Name : 8g.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
 g. SIGPROF (use setitimer system call)
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig){
  printf("Caught signal %d=SIGPROF(using setitimer)\n", sig);
  exit(1);
}
int main() {
    struct itimerval timer;

    signal(SIGPROF, sigHandler);
    
    timer.it_value.tv_sec = 1; //initial trigger after 1 sec;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; //no repeat;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(0);
    }

   
    while (1) {
        printf("Waiting\n");
        for (int i = 0; i < 100000000; i++);
    }

    return 0;
}

/*

OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8g.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Waiting
Waiting
Caught signal 27=SIGPROF(using setitimer)


*/
