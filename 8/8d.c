/*
============================================================================
Name : 8d.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
 d. SIGALRM (use alarm system call)
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigHandler(int sig){
  printf("Caught signal %d=SIGALRM(using alarm)\n", sig);
  exit(1);
}

int main() {

    signal(SIGALRM, sigHandler);
    
    alarm(5);

    pause(); 

    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8d.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 14=SIGALRM(using alarm)

*/
