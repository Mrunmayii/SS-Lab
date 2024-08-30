/*
============================================================================
Name : 12.c
Author : Mrunmayi Shirke
Description : Write a program to find out the opening mode of a file. Use fcntl

Date: 30th Aug, 2024
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

	int fd = open("test.txt", O_RDWR);
	int mode = fcntl(fd, F_GETFL);
	if(mode == 32768) printf("Mode is: O_RDONLY"); 
	else if(mode == 32769) printf("Mode is: O_WRONLY");
	else if(mode == 32770) printf("Mode is: O_RDWR");
	else if (mode == 33792) printf("Mode is: O_APPEND");
	//printf("rdwr %d\n", mode);

	
	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 12.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 12.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Mode is: O_RDWR
*/
