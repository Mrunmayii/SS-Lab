/*
============================================================================
Name : 25.c
Author : Mrunmayi Shirke
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)

Date: 30th August, 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;
    pid_t wait_pid;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Failed to fork child 1");
        return 1;
    } else if (pid1 == 0) {
        printf("Child 1 started.PID: %d\n", getpid());
        sleep(2);
        printf("Child 1 exiting PID: %d\n", getpid());
        exit(1);
    }

    
    pid2 = fork();
    if (pid2 < 0) {
        perror("Failed to fork child 2");
        return 1;
    } else if (pid2 == 0) {
        printf("Child 2 started. PID: %d\n", getpid());
        sleep(3); 
        printf("Child 2  exiting. PID: %d\n", getpid());
        exit(2);
    }

   
    pid3 = fork();
    if (pid3 < 0) {
        perror("Failed to fork child 3");
        return 1;
    } else if (pid3 == 0) {
       
        printf("Child 3 started.PID: %d\n", getpid());
        sleep(4); 
        printf("Child 3 (exiting. PID: %d\n", getpid());
        exit(3);
    }

   
    printf("Enter the PID of the child process to wait for: ");
    scanf("%d", &wait_pid);

    printf("Parent waiting for Child with PID: %d to finish.\n", wait_pid);
    if (waitpid(wait_pid, &status, 0) == -1) {
        perror("waitpid failed");
    } 
    else {
        printf("Child with PID: %d exited.\n", wait_pid);
    }

  
    wait(NULL);
    wait(NULL);

    printf("Parent process exiting.\n");
    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 25.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 25.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Child 1 started.PID: 9105
Child 2 started. PID: 9106
Child 3 started.PID: 9107
Enter the PID of the child process to wait for: 
9106
Child 1 exiting PID: 9105
Child 2  exiting. PID: 9106
Child 3 exiting. PID: 9107

Parent waiting for Child with PID: 9106 to finish.
Child with PID: 9106 exited with status 2.
Parent process exiting.

*/

