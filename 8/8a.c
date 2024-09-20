/*
============================================================================
Name : 8a.c
Author : Mrunmayi Shirke
Description:Write a separate program using signal system call to catch the following signals.
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
  if(signal(SIGSEGV, sigHandler) == SIG_ERR){
    printf("Error\n");
    exit(1);
  }
  
  int *ptr = NULL;
  *ptr = 10;

  
  return 0;
  
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 8a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Caught signal 11=Segmentation fault
*/
