/*
============================================================================
Name : 17.c
Author : Mrunmayi Shirke
Description : Write a program to simulate online ticket reservation. 
		Implement write lock 
		Write a program to open a file, store a ticket number and exit. 
		Write a separate program, to open the file, implement write lock, 
		read the ticket number, increment the number and print 
		the new ticket number then close the file.
Date: 31st Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd = open("ticket_system.txt", O_RDWR);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // Lock the entire file
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to acquire write lock");
        close(fd);
        return 1;
    }

    int ticket_number;
    read(fd, &ticket_number, sizeof(ticket_number));
    printf("Current ticket number: %d\n", ticket_number);

    ticket_number++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket_number, sizeof(ticket_number));
    printf("New ticket number: %d\n", ticket_number);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 17ticket.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Ticket number 1000 stored in file.
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 17.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Current ticket number: 1000
New ticket number: 1001
*/
