#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket_system.txt", O_WRONLY | O_CREAT, 0666);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    int ticket_number = 1000; // Initial ticket number
    write(fd, &ticket_number, sizeof(ticket_number));
    close(fd);

    printf("Ticket number %d stored in file.\n", ticket_number);
    return 0;
}

