/*
============================================================================
Name : 26.c
Author : Mrunmayi Shirke
Description :Write a program to execute an executable program.
 a. use some executable program

Date: 30th August, 2023
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}

