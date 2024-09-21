/*
============================================================================
Name : 29.c
Author : Mrunmayi Shirke
Description : Write a program to remove the message queue.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {

    key_t key = ftok("keyfile.txt", 'a');
    int msgid = msgget(key, 0666);

    
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Message queue removed successfully.
*/
