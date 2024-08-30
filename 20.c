/*
============================================================================
Name : 20.c
Author : Mrunmayi Shirke
Description : Find out the priority of your running program. Modify the priority with nice command
Date: 30th August, 2024
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){

	//first parameter is for process, if we want group process priority use PRIO_PGRP. 
	//But we want the prioirty for process, hence PRIO_PROCESS
	//second parameter is 0 because we want the priority for the current process
		
	int priority = getpriority(PRIO_PROCESS,0);
	printf("Current priority is: %d\n",priority);
	
	printf("Enter the nice value to change the priority: ");
	int inp;	
	scanf("%d",&inp);
	
	if (nice(inp) == -1) {
          perror("Failed to change priority");
          return 1;
        } 

        int new_nice = getpriority(PRIO_PROCESS, 0);
        printf("Updated nice value is: %d\n", new_nice);

	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 20.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 20.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Current priority is: 0
Enter the nice value to change the priority: 1
Updated nice value is: 1
*/
