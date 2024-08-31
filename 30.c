/*
============================================================================
Name : 30.c
Author : Mrunmayi Shirke
Description : Write a program to run a script at a specific time using a Daemon process
Date: 31st August, 2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
	if (!fork()){
		setsid();
		chdir("/");
		umask(0);
		while(1){
			sleep(5);
			printf("Child pid:%d\n", getpid());
			printf("daemon is running");
			}
		}
		else{
		exit(0);
		}
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 30.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 30.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ Child pid:4805
pdaemon is runningChild pid:4805
pdaemon is runningChild pid:4805
pdaemon is runningChild pid:4805

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ps -el| grep 4805
1 S  1000    4805    1383  0  80   0 -   654 hrtime ?        00:00:00 a.out
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ daemon is runningChild pid:4805
*/
