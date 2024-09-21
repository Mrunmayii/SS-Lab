/*
============================================================================
Name : 19d.c
Author : Mrunmayi Shirke
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20 Sep, 2024.
============================================================================
*/



#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("fifo_mkfifo_syscall", 0666) == -1) {
        perror("Error");
        return 1;
    }
    return 0;
}

/*

OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 19d.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ls -l fifo_mkfifo_syscall
prw-rw-r-- 1 mrunmayi mrunmayi 0 Sep 20 20:53 fifo_mkfifo_syscall
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ stat fifo_mkfifo_syscall
  File: fifo_mkfifo_syscall
  Size: 0         	Blocks: 0          IO Block: 4096   fifo
Device: 259,7	Inode: 2911828     Links: 1
Access: (0664/prw-rw-r--)  Uid: ( 1000/mrunmayi)   Gid: ( 1000/mrunmayi)
Access: 2024-09-20 20:53:08.013270468 +0530
Modify: 2024-09-20 20:53:08.013270468 +0530
Change: 2024-09-20 20:53:08.013270468 +0530
 Birth: 2024-09-20 20:53:08.013270468 +0530
*/
