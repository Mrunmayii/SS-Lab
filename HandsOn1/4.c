//Name: Mrunmayi Shirke
//Roll No: MT2024144
//Problem Statement: 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 


#include<stdio.h>
#include<fcntl.h>

int main(void){
 printf("fd = %d\n", open("myfile", O_CREAT|O_EXCL, 0744));
 perror("fd: ");
 
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 4.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ cat 4.c
#include<stdio.h>
#include<fcntl.h>

int main(void){
printf("fd = %d\n", open("myfile", O_CREAT|O_RDWR, 0744));
perror("fd: ");
 
}
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 4.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
fd = 3
fd: : Success 

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 4.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
fd = -1
fd: : File exists
*/

