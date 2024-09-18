/*
============================================================================
Name : 2.c
Author : Mrunmayi Shirke
Description: Write a program to print the system resource limits. Use getrlimit system call.
Date: 7 Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

void printlim(int res, char *res_name){
	struct rlimit limit;
	
	if(getrlimit(res, &limit)==0){
		printf("\n\nLimit for %s:\n", res_name);
		printf("\nSoft limit: %ld\t", (long)limit.rlim_cur);
		printf("\nHard limit: %ld\t", (long)limit.rlim_max);
	}else{
		printf("Error");
	}
}

int main() {
    
    printlim(RLIMIT_AS, "virtual memory address space limit");
    printlim(RLIMIT_CORE, "max size of core file");
    printlim(RLIMIT_CPU, "CPU time");
    printlim(RLIMIT_FSIZE, "Maximum file size");
    printlim(RLIMIT_DATA, "Maximum data size");
    printlim(RLIMIT_STACK, "Maximum stack size");
    printlim(RLIMIT_CORE, "Maximum core file size");
    printlim(RLIMIT_RSS, "Maximum resident set size");
    printlim(RLIMIT_NPROC, "Maximum number of processes");
    printlim(RLIMIT_NOFILE, "Maximum number of open files");
    printlim(RLIMIT_MEMLOCK, "Maximum locked memory");
    printlim(RLIMIT_AS, "Address space limit");


    return 0;
}

/*
Limit for virtual memory address space limit:

Soft limit: -1	
Hard limit: -1	

Limit for max size of core file:

Soft limit: 0	
Hard limit: -1	

Limit for CPU time:

Soft limit: -1	
Hard limit: -1	

Limit for Maximum file size:

Soft limit: -1	
Hard limit: -1	

Limit for Maximum data size:

Soft limit: -1	
Hard limit: -1	

Limit for Maximum stack size:

Soft limit: 8388608	
Hard limit: -1	

Limit for Maximum core file size:

Soft limit: 0	
Hard limit: -1	

Limit for Maximum resident set size:

Soft limit: -1	
Hard limit: -1	

Limit for Maximum number of processes:

Soft limit: 30193	
Hard limit: 30193	

Limit for Maximum number of open files:

Soft limit: 1024	
Hard limit: 1048576	

Limit for Maximum locked memory:

Soft limit: 998993920	
Hard limit: 998993920	

Limit for Address space limit:

Soft limit: -1	
Hard limit: -1	
*/
