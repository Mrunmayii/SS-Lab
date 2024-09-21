/*
============================================================================
Name : 16.c
Author : Mrunmayi Shirke
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 20 Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int pipe1[2], pipe2[2];  // pipe1: parent to child, pipe2: child to parent
    pid_t pid;
    char parent_msg[100];
    char child_msg[100];
    char buffer[100];

    // Create pipe1 for parent to child communication
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    // Create pipe2 for child to parent communication
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        
         while (1) {

            read(pipe1[0], buffer, 100);
            printf("\nChild: Received from parent: %s\n", buffer);

            printf("\nChild: Enter a msg to send to the parent: ");
            fgets(child_msg, 100, stdin);

            write(pipe2[1], child_msg, strlen(child_msg) + 1);
        }

        close(pipe1[0]);
        close(pipe2[1]);
    } 
    else {
        close(pipe1[0]);
        close(pipe2[1]);

        while(1){
          printf("\nParent: Enter msg to child: ");
          fgets(parent_msg, 100, stdin);
          
          write(pipe1[1], parent_msg, strlen(parent_msg)+1);
          
          read(pipe2[0], buffer, 100);
          printf("\nParent received from child:%s\n", buffer);
        }
       
        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}

/*

output:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out

Parent: Enter msg to child: hello

Child: Received from parent: hello


Child: Enter a msg to send to the parent: hi

Parent received from child:hi


Parent: Enter msg to child: this is parent

Child: Received from parent: this is parent


Child: Enter a msg to send to the parent: and this is child

Parent received from child:and this is child


Parent: Enter msg to child: ^C
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:

*/
