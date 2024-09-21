/*
============================================================================
Name : 26.c
Author : Mrunmayi Shirke
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>

struct mbuf {
    long msgtype;
    char msgtext[100];
};


int main(){

  struct mbuf msg;
  
  key_t key = ftok("progfile", 'a');
    
  if(key==-1){
    perror("Status:\n");
    exit(1);
  }

  int ret = msgget(key, 0666|IPC_CREAT);

  if(ret==-1){
     perror("Error creating msg queue\n");
     exit(1);
  }
  
  msg.msgtype=1;
  printf("Enter the msg:\n");
  int bytes_read = read(0, msg.msgtext, sizeof(msg.msgtext)-1);
  
      // Remove newline character if present
  if(msg.msgtext[bytes_read-1] == '\n'){
    msg.msgtext[bytes_read-1] = '\0';
  }
  else{
      msg.msgtext[bytes_read-1] = '\0';
  }
  
  if(msgsnd(ret, &msg, sizeof(msg.msgtext), 0)== -1){
    printf("Error sending msg\n");
    exit(1);
  }
  
  printf("Sent msg is: %s\n", msg.msgtext);
  
  
  
  return 0;
}

/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 26.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Enter the msg:
hey there this is msg queue
Sent msg is: hey there this is msg queue

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          mrunmayi   666        0            0           
0x610762f7 1          mrunmayi   666        0            0           
0x610746b8 2          mrunmayi   666        300          3         

*/
