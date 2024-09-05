/*
============================================================================
Name : 1a.c
Author : Mrunmayi Shirke
Description : Create the following types of a files using (i) shell command (ii) system call a. soft link (symlink system call)
Date: 22nd Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
  symlink("newfile", "softlinknew");
  perror("output");
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 1a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 1a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
output: Success
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ll -s sftlnk
0 lrwxrwxrwx 1 mrunmayi mrunmayi 7 Aug 30 09:16 sftlnk -> filenew
*/
