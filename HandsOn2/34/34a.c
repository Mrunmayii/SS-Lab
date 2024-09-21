/*
============================================================================
Name : 34a.c
Author : Mrunmayi Shirke
Description : Write a program to create a concurrent server.
a. use fork
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_read = read(client_socket, buffer, sizeof(buffer));
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string

    } else {
        perror("read");
    }
    printf("Client: %s\n", buffer);
    send(client_socket, "Hi from server", 14, 0);
    close(client_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        if (fork() == 0) {
            close(server_fd);
            handle_client(new_socket);
            exit(0);
        }
        close(new_socket);
        break;
    }
    return 0;
}
