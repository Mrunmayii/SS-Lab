/*
============================================================================
Name : 23.c
Author : Mrunmayi Shirke
Description : Write a program to create a Zombie state of the running program
Date: 30th August, 2024
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int cpid = fork();
	
	if (cpid < 0) {
        	perror("fork failed");
         	return 1;
        }
	if(!cpid){
		printf("I am child, PID: %d\n", getpid());
	}
	else{
		printf("This is a parent process: %d\n", getpid());
		sleep(30);
	}
	
	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 23.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
This is a parent process: 5471
I am child, PID: 5472

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ps 5472
    PID TTY      STAT   TIME COMMAND
   5472 pts/0    Z+     0:00 [a.out] <defunct>

*/
