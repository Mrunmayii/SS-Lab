/*
============================================================================
Name : 12.c
Author : Mrunmayi Shirke
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process: wait for a signal from the child
        sleep(10);
    } 
    else if (pid == 0) {
        // Child process: send SIGKILL to the parent process
        printf("Child process PID is %d, parent PID is %d\n", getpid(), getppid());
        printf("Child process is sending SIGKILL to parent process.\n");
        
        kill(getppid(), SIGKILL);
        sleep(5);  // Give time to observe the orphaned process
        
        printf("Child process is now an orphan (adopted by init).\n");
        printf("Parent PID(after becoming orphan): %d\n", getppid());
        
    } 
    else {
        printf("Fork failed\n");
    }

    return 0;
}

/*
OUTPUT:
Child process PID is 9467, parent PID is 9466
Child process is sending SIGKILL to parent process.
Killed
Child process is now an orphan (adopted by init).
Parent PID(after becoming orphan): 1422
*/
