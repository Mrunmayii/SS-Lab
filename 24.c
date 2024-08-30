/*
============================================================================
Name : 24.c
Author : Mrunmayi Shirke
Description : Write a program to create an orphan process

Date: 30th August, 2024
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

	pid_t pid;
    	pid = fork();
    	if (pid < 0) {
	    	perror("fork failed");
        return 1;
        }

	if (pid > 0) {
       	        printf("Parent process (PID: %d) is exiting..\n", getpid());
	        exit(0); // Parent exits, leaving the child an orphan
        }
       	else {
		sleep(1);
		printf("Child started. Child process id: %d\n", getpid());
	        
		sleep(5); 
        
        	printf("After becoming orphan, parent id for child: %d\n", getppid());
        
	        sleep(1);
	        printf("Child process stopped\n");
		return 0;
    }

    return 0;	
}		
/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 24.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 24.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Parent process (PID: 8980) is exiting..
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ Child started. Child process id: 8981
After becoming orphan, parent id for child: 6655
Child process stopped
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 24.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 24.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Parent process (PID: 8980) is exiting..
Child started. Child process id: 8981
After becoming orphan, parent id for child: 6655
Child process stopped
*/
