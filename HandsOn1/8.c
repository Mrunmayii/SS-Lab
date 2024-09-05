/*
Name: Mrunmayi Shirke
Roll no: MT2024144
Problem Statement: 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
 */


#include<stdio.h>

int main(){
	FILE *fd = fopen("input.txt", "r");
	if(fd == NULL){
		perror("Error opening file\n");
		return 1;
	}
	
	char buffer[1024];
	
	while (fgets(buffer, sizeof(buffer), fd)!=NULL) {
     	   printf("%s",buffer);
        }
	fclose(fd);
	return 0;
	
}

/*
OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 8.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
Internal representation of a file is given by an inode, which contains a description of the disk layout of the file data and other information such as the file owner, access permissions, and access times. The term inode is a contraction of the term index node. Every file has one inode, but it may have several names, all of which map into the inode. Each name is called a link. When a process creates a new file, the kernel assigns it an unused inode.
*/

