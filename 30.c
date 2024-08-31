/*
============================================================================
Name : 30.c
Author : Mrunmayi Shirke
Description : Write a program to run a script at a specific time using a Daemon process
Date: 31st August, 2024
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/time.h>


int main(){
	int inp;
	printf("Enter the number of nimutes after which you want to run the task:");
        scanf("%d",&inp);

        if(!fork()){
                setsid();
                chdir("/");
                //umask(0);

		printf("Inside daemon process\n");
		struct timeval now;
    		int rc;
		
    		rc=gettimeofday(&now, NULL);	
    		
		if(rc==0) {
        		printf("gettimeofday() successful.\n");
        		printf("current time in seconds.milliseconds = %lu.%06lu\n",now.tv_sec, now.tv_usec);
    		}
    		else {
        		printf("gettimeofday() failed\n");
        		return -1;
    		}
		
		//scanf("%d",&inp);

		int newtime = now.tv_sec + inp*60;

		while(newtime!=now.tv_sec){			
			rc = gettimeofday(&now, NULL);

			if(newtime==now.tv_sec){
				printf("Task executed successfully after %d minutes\n", inp);
				printf("After executing the task current time is: %lu\n",now.tv_sec);
			}
		}

	}
        
	else
                exit(0);
	printf("outside daemon\n");
        return 0;
}


/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Enter the number of nimutes after which you want to run the task:1
Inside daemon process
gettimeofday() successful.
current time in seconds.milliseconds = 1725085307.632751
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ Task executed successfully after 1 minutes
After executing the task current time is: 1725085367
outside daemon
*/
