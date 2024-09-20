/*
============================================================================
Name : 10c.c
Author : Mrunmayi Shirke
Description: Write a separate program using sigaction system call to catch the following signals.
 c. SIGFPE
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
  printf("Caught signal %d=SIGFPE(arithmetic exception)\n", sig);
  exit(1);
}

int main(){
  
  struct sigaction sa;
  sa.sa_handler = sigHandler;

  if(sigaction(SIGFPE, &sa, NULL) == -1){
    printf("Error\n");
    exit(1);
  }
  
  for(int i=0; i<=1; i++){
    printf("%d", 10/i);
  }
  
  return 0;
}

/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 10c.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 8=SIGFPE(arithmetic exception)


*/

