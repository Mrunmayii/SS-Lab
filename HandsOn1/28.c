/*
============================================================================
Name : 28.c
Author : Mrunmayi Shirke
Description : Write a program to get maximum and minimum real time priority.
Date: 31st August, 2024
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include<sys/types.h>
 
int main()
{
    printf("The Maximum real time priority FIFO:%d\n", sched_get_priority_max(SCHED_FIFO));
    printf("The Minimum real time priority FIFO:%d\n", sched_get_priority_min(SCHED_FIFO));

    printf("The Maximum real time priority RR:%d\n", sched_get_priority_max(SCHED_RR));
    printf("The Minimum real time priority RR:%d\n", sched_get_priority_min(SCHED_RR));
 
    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 28.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 28.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
The Maximum real time priority FIFO:99
The Minimum real time priority FIFO:1
The Maximum real time priority RR:99
The Minimum real time priority RR:1
*/
