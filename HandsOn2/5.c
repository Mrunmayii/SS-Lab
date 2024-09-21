/*
============================================================================
Name : 5.c
Author : Mrunmayi Shirke
Description : Write a program to print the system limitation of
 a. maximum length of the arguments to the exec family of functions.
 b. maximum number of simultaneous process per user id.
 c. number of clock ticks (jiffy) per second.
 d. maximum number of open files
 e. size of a page
 f. total number of pages in the physical memory
 g. number of currently available pages in the physical memory. 
Date: 13 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    long args = sysconf(_SC_ARG_MAX);
    if (args == -1)
        perror("error");
    else
        printf("maximum length of arguments to the exec family of functions: %ld\n", args);

    long max_processes = sysconf(_SC_CHILD_MAX);
    if (max_processes == -1)
        perror("error");
    else
        printf("maximum number of simultaneous process per user id: %ld\n", max_processes);

    long clk_tick = sysconf(_SC_CLK_TCK);
    if (clk_tick == -1)
        perror("error");
    else
        printf("number of clock ticks (jiffy) per second: %ld\n", clk_tick);
    
    long open_files = sysconf(_SC_OPEN_MAX);
    if (open_files == -1)
        perror("error");
    else
        printf("maximum number of open files: %ld\n", open_files);

    long pg_size = sysconf(_SC_PAGESIZE);
    if (pg_size == -1)
        perror("error");
    else
        printf("size of a page: %ld bytes\n", pg_size);

    long total_pages = sysconf(_SC_PHYS_PAGES);
    if (total_pages == -1)
       perror("error");
    else
        printf("total number of pages in physical memory: %ld\n", total_pages);

    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if (avail_pages == -1)
        perror("error");
    else
        printf("number of currently available pages in physical memory: %ld\n", avail_pages);

    return 0;
}

/*

mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 5.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 5.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
maximum length of arguments to the exec family of functions: 2097152
maximum number of simultaneous process per user id: 30193
number of clock ticks (jiffy) per second: 100
maximum number of open files: 1024
size of a page: 4096 bytes
total number of pages in physical memory: 1951163
number of currently available pages in physical memory: 1106382

*/
