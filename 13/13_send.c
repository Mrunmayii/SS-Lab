/*
============================================================================
Name : 13.c
Author : Mrunmayi Shirke
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Enter the PID of the first program: ");
    scanf("%d", &pid);

    kill(pid, SIGSTOP);
    printf("Sent SIGSTOP to process with PID: %d\n", pid);

    return 0;
}
