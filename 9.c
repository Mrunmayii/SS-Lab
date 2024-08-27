/*
Name: Mrunmayi Shirke
Roll No: MT2024144
Problem Statement: 9. Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
*/


#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input.txt\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", st.st_ino);
    printf("Number of hard links: %lu\n", st.st_nlink);
    printf("UID: %d\n", st.st_uid);
    printf("GID: %d\n", st.st_gid);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Block size: %ld bytes\n", st.st_blksize);
    printf("Number of blocks: %ld\n", st.st_blocks);
    printf("Time of last access: %s", ctime(&st.st_atime));
    printf("Time of last modification: %s", ctime(&st.st_mtime));
    printf("Time of last change: %s", ctime(&st.st_ctime));

    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 9.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 9.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out input.txt
Inode: 2911724
Number of hard links: 1
UID: 1000
GID: 1000
Size: 453 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Tue Aug 27 12:03:00 2024
Time of last modification: Tue Aug 27 12:02:50 2024
Time of last change: Tue Aug 27 12:02:50 2024
*/
