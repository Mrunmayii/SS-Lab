/*
============================================================================
Name : 27rcv.c
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
#include <errno.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

void receive_message(int msgid, int flag) {
    struct msg_buffer message;
    ssize_t result = msgrcv(msgid, &message, sizeof(message.msg_text), 1, flag);

    if (result < 0) {
        if (errno == ENOMSG) {
            printf("No messages in the queue.\n");
        } else {
            perror("Error receiving message");
        }
    } else {
        printf("Received message: %s\n", message.msg_text);
    }
}

int main() {
    key_t key = ftok("key2", 65);
    int msgid = msgget(key, 0666);

    printf("Receiving with flag 0:\n");
    receive_message(msgid, 0); // Blocking call

    printf("Receiving with IPC_NOWAIT:\n");
    receive_message(msgid, IPC_NOWAIT); // Non-blocking call

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
