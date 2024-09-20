/*
============================================================================
Name : 8a.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
 b. SIGINT
Date: 20 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
  printf("\nCaught signal %d=SIGINT\n", sig);
  exit(1);
}

int main(){
  if (signal(SIGINT, sigHandler) == SIG_ERR){
    printf("Error\n");
    exit(1);
  }

  for(int i=0; i<5; i++){
    printf("%d\n", i);
    sleep(1);
  }
  
  return 0;
  
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
0
1
^C
Caught signal 2=SIGINT

*/
