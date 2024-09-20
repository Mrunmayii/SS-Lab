/*
============================================================================
Name : 8c.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
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
  if (signal(SIGFPE, sigHandler) == SIG_ERR){
    printf("Error\n");
    exit(1);
  }

  for(int i=0; i<=1; i++){
    printf("%d", 10/i);
  }
  return 0;
  
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8c.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 8=SIGFPE(arithmetic exception)

*/
