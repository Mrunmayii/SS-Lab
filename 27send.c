/*
============================================================================
Name : 27send.c
Author : Mrunmayi Shirke
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include<unistd.h>

struct mbuf {
    long msg_type;
    char msgtext[100];
};

int main() {
    key_t key = ftok("key2", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct mbuf message;
    message.msg_type = 1; // Set the message type

    while (1) {
        printf("Enter a message (or type 'exit' to quit): ");
        //fgets(message.msgtext, sizeof(message.msgtext), stdin);
        int bytes_read = read(0, message.msgtext, sizeof(message.msgtext)-1);
        // Remove newline character from input
        if(message.msgtext[bytes_read-1] == '\n'){
            message.msgtext[bytes_read-1] = '\0';
          }
          else{
              message.msgtext[bytes_read-1] = '\0';
          }

        // Check for exit condition
        if (strcmp(message.msgtext, "exit") == 0) {
            break;
        }

        msgsnd(msgid, &message, sizeof(message.msgtext), 0);
        printf("Message sent to the queue.\n");
    }

    return 0;
}

/*

OUTPUT:

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 27b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Receiving with flag 0:
Received message: hello 27th
Receiving with IPC_NOWAIT:
Received message: its msg queue

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 27a.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Enter a message (or type 'exit' to quit): newmsg
Message sent to the queue.
Enter a message (or type 'exit' to quit): exit
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 27b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Receiving with flag 0:
Received message: newmsg
Receiving with IPC_NOWAIT:
No messages in the queue.

*/
