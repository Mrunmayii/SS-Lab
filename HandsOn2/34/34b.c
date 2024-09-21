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
#include <pthread.h>

#define PORT 8080

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg); // Free the allocated memory for the socket descriptor
    char buffer[1024];
    
    // Read message from client
    int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Client: %s\n", buffer);
        
        // Send response to client
        send(client_socket, "Hi from server", 14, 0);
    } else {
        perror("read");
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            continue; // Try to accept the next connection
        }

        // Allocate memory for the socket descriptor and pass it to the thread
        int *socket_ptr = malloc(sizeof(int));
        if (socket_ptr == NULL) {
            perror("malloc failed");
            close(new_socket);
            continue;
        }
        *socket_ptr = new_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, socket_ptr);
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}

