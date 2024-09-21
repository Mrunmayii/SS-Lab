/*
============================================================================
Name : 4.c
Author : Mrunmayi Shirke
Description : Write a program to measure how much time is taken to execute 100 getppid() system calls. 
Use Time Stamp Counter (TSC) to measure the time.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;

    start = rdtsc();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("CPU cycles taken: %lu\n", end - start);

    return 0;
}

/*
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 4.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
CPU cycles taken: 39087
*/
