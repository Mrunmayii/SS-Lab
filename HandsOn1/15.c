/*
============================================================================
Name : 15.c
Author : Mrunmayi Shirke
Description : Write a program to display the environmental variable of the user (use environ)

Date: 30th Aug, 2024
============================================================================
*/

#include <stdio.h>

extern char **environ;

int main() {
    int i=0;

    while (environ[i]) {
        printf("%s\n", environ[i]);
        i++;
    }

    return 0;
}



