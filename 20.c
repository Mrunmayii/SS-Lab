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
#include <sys/stat.h>


int main() {
    int fd;
    char message[100];

    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, sizeof(message));
    printf("Producer: Message sent to FIFO.\n");

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
