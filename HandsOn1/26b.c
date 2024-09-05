/*
============================================================================
Name : 26.c
Author : Mrunmayi Shirke
Description :Write a program to execute an executable program.
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 30th August, 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    char *arg = "World";
    char *executable = "./prog.out";

    execl(executable, executable, arg, NULL);

    perror("execl failed");
    return 1;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 26b.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Hello, World!
*/
