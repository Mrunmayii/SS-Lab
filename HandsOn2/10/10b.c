/*
============================================================================
Name : 10b.c
Author : Mrunmayi Shirke
Description: Write a separate program using sigaction system call to catch the following signals.
 b. SIGINT
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
  printf("\nCaught signal %d= SIGINT(pressed ctrl+c)\n", sig);
  exit(1);
}

int main(){
  
  struct sigaction sa;
  sa.sa_handler = sigHandler;

  if(sigaction(SIGINT, &sa, NULL) == -1){
    printf("Error\n");
    exit(1);
  }
  
  while(1);
  return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 10b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
^C
Caught signal 2= SIGINT(pressed ctrl+c)

*/

