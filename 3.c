/*
============================================================================
Name : 3.c
Author : Mrunmayi Shirke
Description: Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 7 Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit limit;

	 if(getrlimit(RLIMIT_FSIZE, &limit)==0){
                printf("\nOriginal Soft limit for FSIZE: %ld\t", (long)limit.rlim_cur);
	 }

	limit.rlim_cur = 200;
	if(setrlimit(RLIMIT_FSIZE, &limit)==0){
		printf("\nSuccess");
	}	
	else{
		printf("\nError");
	}

	if(getrlimit(RLIMIT_FSIZE, &limit)==0){
                printf("\nNew Soft limit for FSIZE: %ld\t", (long)limit.rlim_cur);
         }

	return 0;

}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 3.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 3.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out

Original Soft limit for FSIZE: -1
Success
New Soft limit for FSIZE: 200
*/
