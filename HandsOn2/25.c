/*
============================================================================
Name : 25.c
Author : Mrunmayi Shirke
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
 a. access permission
 b. uid, gid
 c. time of last message sent and received
 d. time of last change in the message queue
 d. size of the queue
 f. number of messages in the queue
 g. maximum number of bytes allowed
 h. pid of the msgsnd and msgrcv
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>

int main(){

  struct msqid_ds msq;
  
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
  
  msgctl(ret, IPC_STAT, &msq);//fills msqid_ds strucutre(msq) qith metadata abt msg queue.

  
  printf("access permission: %o\n", msq.msg_perm.mode);
  printf("uid: %ld\n", (long)msq.msg_perm.uid);
  printf("gid: %ld\n", (long)msq.msg_perm.gid);
  printf("time of last message sent: %ld\n", (long)msq.msg_stime);
  printf("time of last message received: %ld\n", (long)msq.msg_rtime);
  printf("time of last change in the message queue: %ld\n", (long)msq.msg_ctime);
  printf("number of messages in the queue: %ld\n", (long)msq.msg_qnum);
  printf("maximum number of bytes allowed: %ld\n", (long)msq.msg_qbytes);
  printf("pid of the msgsnd: %ld\n", (long)msq.msg_lspid);
  printf("pid of the msgrcv: %ld\n", (long)msq.msg_lrpid);
  
  return 0;
}

/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 25.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
access permission: 666
uid: 1000
gid: 1000
time of last message sent: 0
time of last message received: 0
time of last change in the message queue: 1726907807
number of messages in the queue: 0
maximum number of bytes allowed: 16384
pid of the msgsnd: 0
pid of the msgrcv: 0

*/
