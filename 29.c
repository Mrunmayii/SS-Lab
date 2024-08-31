/*
============================================================================
Name : 29.c
Author : Mrunmayi Shirke
Description : Write a program to get scheduling policy and modify the scheduling policy 
		(SCHED_FIFO, SCHED_RR)
Date: 31st August, 2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch(policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }
}

int main() {
    int pid = getpid();
    int policy;
    struct sched_param  sp;
    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("Error in sched_getscheduler");
        return 1;
    }

    print_policy(policy);

    if (sched_getparam(pid, &sp) == -1) {
        perror("Error in sched_getparam");
        return 1;
    }

    printf("Modifying scheduling policy to SCHED_FIFO\n\n");
    policy = SCHED_FIFO;
    sp.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(pid, policy, &sp) == -1) {
        perror("Error in sched_setscheduler");
        return 1;
    }

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("Error in sched_getscheduler");
        return 1;
    }

    print_policy(policy);


    printf("Modifying scheduling policy to SCHED_RR\n\n");
    policy = SCHED_RR;
    sp.sched_priority = sched_get_priority_max(SCHED_RR);

    if (sched_setscheduler(pid, policy, &sp) == -1) {
        perror("Error in sched_setscheduler");
        return 1;
    }


    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("Error in sched_getscheduler");
        return 1;
    }

    print_policy(policy);

    return 0;
}


/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 29.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 29.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ sudo ./a.out
Current scheduling policy: SCHED_OTHER
Modifying scheduling policy to SCHED_FIFO

Current scheduling policy: SCHED_FIFO
Modifying scheduling policy to SCHED_RR

Current scheduling policy: SCHED_RR
*/
