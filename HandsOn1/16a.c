/*
============================================================================
Name : 16.c
Author : Mrunmayi Shirke
Description : Write a program to perform mandatory locking.
 		a. Implement write lock
 		b. Implement read lock
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

int main() {
    int fd = open("mrunmayi.txt", O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    struct flock lock = {F_WRLCK, SEEK_SET,0,0,0};
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            printf("File is already locked for writing.\n");
        } else {
            perror("Failed to acquire write lock");
        }
    } else {
        printf("Write lock acquired.\n");
    }

    printf("Press Enter to release the lock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);
    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 16a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Write lock acquired.
Press Enter to release the lock...

Write lock released.
*/

