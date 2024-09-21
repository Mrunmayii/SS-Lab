/*
============================================================================
Name : 24.c
Author : Mrunmayi Shirke
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>

int main(){

    key_t key = ftok(".", 'a');
    
    if(key==-1){
      printf("Error\n");
      exit(1);
    }

    int ret = msgget(key, 0666|IPC_CREAT);

    if(ret==-1){
       printf("Error creating msg queue\n");
       exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", ret);
    
    return 0;
	
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 24.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Key: 1627874039
Message Queue ID: 1
*/

