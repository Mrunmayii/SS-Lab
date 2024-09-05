/*
============================================================================
Name : 14.c
Author : Mrunmayi Shirke
Description: Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file. 
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
 struct stat fileinfo;

 if (argc != 2) {
     printf("Argument error.\nUsage: %s <pathname>\n", argv[0]);
     return 1;
 }

 lstat(argv[1], &fileinfo);
 printf("File type:");

 switch (fileinfo.st_mode & S_IFMT) {
 case S_IFBLK:  
	 printf("Block device\n");            
	 break;
 case S_IFCHR:  
	 printf("Character device\n");        
	 break;
 case S_IFDIR:  
	 printf("Directory\n");               
	 break;
 case S_IFIFO:  
	 printf("FIFO\n");               
	 break;
 case S_IFLNK:  
	 printf("Symlink\n");                 
	 break;
 case S_IFREG:  
	 printf("Regular file\n");            
	 break;
 case S_IFSOCK: 
	 printf("Socket\n");                  
	 break;
 default:       
	 printf("Unknown\n");                
	 break;
 }

 return 0;
}
/*
============================================================================
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/linux_ta$ vim 14.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/linux_ta$ gcc 14.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/linux_ta$ ./a.out sftlnk
File type:Symlink
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/linux_ta$ ./a.out 9.c
File type:Regular file
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/linux_ta$ ./a.out file.txt
File type:Regular file
============================================================================
 */
