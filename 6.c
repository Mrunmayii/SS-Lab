/*Name: Mrunmayi Shirke
Roll No: MT2024144
Problem Statement: 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
*/

#include<stdio.h>
#include<unistd.h>


int main(int argc, char *argv[]){
	char buffer[32];
	int size_read = read(0, buffer, sizeof(buffer));
	printf("%d\n", size_read);
	fflush(stdout);
	write(1, buffer, sizeof(buffer));
	return 0;
}

/*
OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 6.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 6.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
hello
6
hello
*/
