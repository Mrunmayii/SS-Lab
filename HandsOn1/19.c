/*
============================================================================
Name : 19.c
Author : Mrunmayi Shirke
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
Date: 30th Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

static inline uint64_t rdtsc() {
    uint32_t lo, hi;
    asm volatile (
        "rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    
    uint64_t start, end;
    
    start = rdtsc();
    pid_t pid = getpid();
    end = rdtsc();
    
    printf("PID: %d\n", pid);
    printf("Time taken (in cycles): %llu\n", (unsigned long long)(end - start));
    
    return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
PID: 4977
Time taken (in cycles): 6144
*/

