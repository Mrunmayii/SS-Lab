/*
============================================================================
Name : 27.c
Author : Mrunmayi Shirke
Description : Write a program to execute ls -Rl by the following system calls
 		a. execl
 		b. execlp
 		c. execle
 		d. execv
 		e. execvp
Date: 30th August, 2024
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main(){

	int n;
	printf("Choose Option\n");
	printf("1. execl\n");
	printf("2. execlp\n");
	printf("3. execle\n");
	printf("4. execv\n");
	printf("5. execvp\n");

	printf("Enter the option:\t");
	scanf("%d",&n);

	switch(n){
		case 1:
			printf("execl\n");
			execl("/bin/ls","ls","-Rl",(char *) NULL);
			break;

		case 2:
			printf("execlp\n");
			execlp("ls","ls","-Rl",(char *) NULL);
			break;

		case 3:
			printf("execle\n");
			char *env[] = { NULL };
           		execle ("/bin/ls", "ls", "-Rl", (char *)0, env);	
			break;

		case 4:
			printf("execv\n");
			char *cmd[] = { "ls", "-Rl", (char *)0 };
           		execv ("/bin/ls", cmd);
                        break;

		case 5:
			printf("execv\n");
                        char *cmd1[] = { "ls", "-Rl", (char *)0 };
           		execvp ("ls", cmd1);
                        break;

		}
	return 0;
}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Choose Option
1. execl
2. execlp
3. execle
4. execv
5. execvp
Enter the option:	3
execle
.:
total 140
-rw-rw-r-- 1 mrunmayi mrunmayi  1861 Aug 30 01:50 10.c
-rw-rw-r-- 1 mrunmayi mrunmayi  2314 Aug 30 01:44 11.c
-rw-rw-r-- 1 mrunmayi mrunmayi   897 Aug 30 11:55 12.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1314 Aug 30 12:04 13.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1764 Aug 30 15:16 14.c
-rw-rw-r-- 1 mrunmayi mrunmayi   485 Aug 30 15:28 15.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1343 Aug 30 16:33 16a.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1394 Aug 30 16:49 16b.c
-rw-rw-r-- 1 mrunmayi mrunmayi  2468 Aug 30 17:08 18.c
-rw-rw-r-- 1 mrunmayi mrunmayi   937 Aug 30 17:53 19.c
-rw-rw-r-- 1 mrunmayi mrunmayi   820 Aug 30 09:19 1a.c
-rw-rw-r-- 1 mrunmayi mrunmayi   695 Aug 30 10:52 1b.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1068 Aug 30 11:00 1c.c
-rw-rw-r-- 1 mrunmayi mrunmayi   503 Aug 30 10:13 2.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1388 Aug 30 18:07 20.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1002 Aug 30 18:21 21.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1230 Aug 30 18:29 22.c
-rw-rw-r-- 1 mrunmayi mrunmayi   978 Aug 30 18:45 23.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1671 Aug 30 23:06 24.c
-rw-rw-r-- 1 mrunmayi mrunmayi  2332 Aug 30 23:24 25.c
-rw-rw-r-- 1 mrunmayi mrunmayi   762 Aug 31 00:11 26b.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1271 Aug 31 08:02 27a.c
-rw-rw-r-- 1 mrunmayi mrunmayi   629 Aug 26 17:58 3.c
-rw-rw-r-- 1 mrunmayi mrunmayi   890 Aug 26 18:09 4.c
-rw-rw-r-- 1 mrunmayi mrunmayi   632 Aug 26 18:51 6.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1039 Aug 27 11:09 7.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1102 Aug 27 12:03 8.c
-rw-rw-r-- 1 mrunmayi mrunmayi  1646 Aug 27 12:22 9.c
-rw-rw-r-- 1 mrunmayi mrunmayi     8 Aug 20 10:35 README.md
-rwxrwxr-x 1 mrunmayi mrunmayi 16312 Aug 31 08:04 a.out
-rw-rw-r-- 1 mrunmayi mrunmayi   527 Aug 31 00:08 prog.out.c
-rw--wx--T 1 mrunmayi mrunmayi    37 Aug 30 18:27 test.txt
*/
