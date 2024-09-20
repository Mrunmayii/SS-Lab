/*
============================================================================
Name : 10a.c
Author : Mrunmayi Shirke
Description: Write a separate program using sigaction system call to catch the following signals.
 a. SIGSEGV
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
  printf("Caught signal %d=Segmentation fault\n", sig);
  exit(1);
}

int main(){
  
  struct sigaction sa;
  sa.sa_handler = sigHandler;

  if(sigaction(SIGSEGV, &sa, NULL) == -1){
    printf("Error\n");
    exit(1);
  }
  
  int *ptr = NULL;
  *ptr = 1;
  
  return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 10a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 11=Segmentation fault
*/

