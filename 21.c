/*
============================================================================
Name : 21.c
Author : Mrunmayi Shirke
Description : Write a program, call fork and print the parent and child process id
Date: 30th August, 2024
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    printf("Parent ID: %d\t", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else {
  //      printf("Parent process ID: %d\n", getpid());
        printf("\nChild process ID from parent: %d\n", pid);
    }

	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 21.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 21.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Parent ID: 5252
Child process ID from parent: 5253
Parent ID: 5252
Child process ID from parent: 0
*/
