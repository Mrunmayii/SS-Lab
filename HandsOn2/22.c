/*
============================================================================
Name : 22.c
Author : Mrunmayi Shirke
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *fifo_path = "myfifo";
    if (mkfifo(fifo_path, 0666) == -1) {
            perror("mkfifo");
            exit(1);
    }

    int fd = open(fifo_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    struct timeval tv;
    tv.tv_sec = 10;   
    tv.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &tv);
    
    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);
    } 
    else if (ret == 0) {
        printf("No data within 10 seconds.\n");
    } 
    else {
         if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            int bytes_read = read(fd, buffer, sizeof(buffer)-1);
             if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            }
        }
    }

    close(fd);
    return 0;
}
