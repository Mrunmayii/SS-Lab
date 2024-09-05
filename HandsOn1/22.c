/*
============================================================================
Name : 22.c
Author : Mrunmayi Shirke
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 30 August, 2024
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

	int fd = open("test.txt", O_CREAT| O_RDWR);

	if(fd==-1){
		printf("Failed opening file");
	}

	write(fd, "Hello I am parent\n", 19);

	int cid=fork();
	if(!cid){
		write(fd, "Hello I am child\n", 18);
	}

	close(fd);
	
	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 22.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 22.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ls
10.c  12.c  14.c  16a.c  18.c  1a.c  1c.c  21.c  2.c  4.c  7.c  9.c    README.md
11.c  13.c  15.c  16b.c  19.c  1b.c  20.c  22.c  3.c  6.c  8.c  a.out  test.txt
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ cat test.txt
Hello I am parent
Hello I am child
*/
