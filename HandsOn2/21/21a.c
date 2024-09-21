#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char write_msg[100], read_msg[100];

    fd1 = open("fifo1", O_WRONLY);
    if (fd1 < 0) {
        perror("Error opening fifo1 for writing");
        exit(1);
    }

    fd2 = open("fifo2", O_RDONLY);
    if (fd2 < 0) {
        perror("Error opening fifo2 for reading");
        exit(1);
    }

    while (1) {
 
        printf("Program 1: Enter a message: ");
        fgets(write_msg, 100, stdin);
        write(fd1, write_msg, sizeof(write_msg));

        read(fd2, read_msg, sizeof(read_msg));
        printf("Program 1 received: %s\n", read_msg);
    }

    close(fd1);
    close(fd2);

    return 0;
}

