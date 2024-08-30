/*
============================================================================
Name : 13.c
Author : Mrunmayi Shirke
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main()
{
   fd_set rfds;
   struct timeval tv;

   FD_ZERO(&rfds);
   FD_SET(0, &rfds);

   tv.tv_sec = 5;
   tv.tv_usec = 0;

   int retval = select(1, &rfds, NULL, NULL, &tv);

   if (retval == -1)
       perror("select()");
   else if (retval)
       printf("Data is available now.\n");
   else
       printf("No data within five seconds.\n");

   return 0;

}

/*
============================================================================

OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 13.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 13.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
No data within five seconds.
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
2
Data is available now.
============================================================================

*/


