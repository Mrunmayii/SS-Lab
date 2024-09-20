/*
============================================================================
Name : 13.c
Author : Mrunmayi Shirke
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigHandler(int sig){
  printf("Signal %d=SIGSTOP caught from another program\n", sig);
  exit(1);
}

int main() {
    
    signal(SIGSTOP, sigHandler);
   
    printf("Process PID: %d\n", getpid());
    printf("Waiting to catch SIGSTOP signal\n");
    
    while(1){
      pause();
    }

    return 0;
}
