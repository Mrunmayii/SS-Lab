/*
============================================================================
Name : 1b.c
Author : Mrunmayi Shirke
Description : Create the following types of a files using (i) shell command (ii) system call b. hard link (link system call)
Date: 30 Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
  link("myfile", "hrdlnk");
  perror("output");
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 1b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
output: Success
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ls -l hrdlnk
-rw-rw-r-- 2 mrunmayi mrunmayi 0 Aug 30 10:48 hrdlnk
*/
