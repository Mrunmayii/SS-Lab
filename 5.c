/*
============================================================================
Name : 5.c
Author : Mrunmayi Shirke
Description :  Write a program to create five new files with infinite loop. 
		Execute the program in the background and 
		check the file descriptor table at /proc/pid/fd.

Date: 30th Aug, 2024
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	int pid=getpid();
	printf("pid: %d\n",pid);

	int fd1 = creat("f1.txt",O_RDWR);
	int fd2 = creat("f2.txt",O_RDWR);
	int fd3 = creat("f3.txt",O_RDWR);
	int fd4 = creat("f4.txt",O_RDWR);
	int fd5 = creat("f5.txt",O_RDWR);
	printf("fd1: %d , fd2: %d , fd3: %d, fd4: %d, fd5: %d\n",fd1,fd2,fd3,fd4,fd5);

	while(1);

	return 0;
}
