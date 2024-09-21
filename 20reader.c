/*
============================================================================
Name : 20.c
Author : Mrunmayi Shirke
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int fd;
    char buffer[100];


    fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


    read(fd, buffer, sizeof(buffer));
    printf("Consumer: Received message: %s\n", buffer);

    close(fd);

    return 0;
}

/*
TERMINAL 1:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./20
Enter a message to send: hello
Producer: Message sent to FIFO.

TERMINAL 2:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./20reader
Consumer: Received message: hello

*/
