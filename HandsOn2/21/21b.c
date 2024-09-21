#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main() {
    int fd1, fd2;
    char write_msg[100], read_msg[100];


    fd1 = open("fifo1", O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening fifo1 for reading");
        exit(1);
    }

    fd2 = open("fifo2", O_WRONLY);
    if (fd2 < 0) {
        perror("Error opening fifo2 for writing");
        exit(1);
    }

    while (1) {

        read(fd1, read_msg, sizeof(read_msg));
        printf("Program 2 received: %s\n", read_msg);

        printf("\nProgram 2 Enter a message: ");
        fgets(write_msg, 100, stdin);
        write(fd2, write_msg, sizeof(write_msg));
    }

    close(fd1);
    close(fd2);

    return 0;
}

