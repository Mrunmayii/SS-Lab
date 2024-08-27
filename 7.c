/*
Name: Mrunmayi Shirke
Roll No: MT2024144
Problem Statement: 7. Write a program to copy file1 into file2 ($cp file1 file2). 
*/

#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int file1 = open(argv[1], O_RDONLY);
	if(file1 <0){
		perror("Status");
		exit(0);
	}
	int file2 = open(argv[2], O_WRONLY| O_CREAT, 0600);
	if(file2<0){
	 perror("Status");
	 exit(0);
	}
	char buffer[1024];
	int size_read;
	while((size_read = read(file1, buffer, sizeof(buffer)))> 0){
		write(file2, buffer, size_read);
	}
	printf("FD1 is: %d\t", file1);
	printf("FD2 is: %d\t", file2);
	close(file1);
	close(file2);
	return 0;
}

/*
OUPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 7.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 7.c -o 7.out
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./7.out input.txt output.txt
FD1 is: 3	FD2 is: 4	
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ nano output.txt


 */
