/*
============================================================================
Name : 11abc.c
Author : Mrunmayi Shirke
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
Date: 29th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>

int main(){
	char *fname = "file.txt";
	
	int fd = open(fname, O_RDWR|O_CREAT|O_APPEND, 0666);
	if(fd == -1){
	 perror("Status");
	 return 1;
	}
	 printf("fd:%d\t",fd);

	char buffer[]="Msg from original descriptor\n";
	int w = write(fd, buffer, sizeof(buffer));
	if(w == -1){
	 perror("Failed to write with original desc");
	 return 1;
	}

	int fd1=dup(fd);
	if (fd1 == -1) {
	        perror("dup failed\n");
	        close(fd);
	        return 1;
	}
	 printf("fd1:%d\t",fd1);

	char buffer1[]="Msg from dup descriptor\n";
        int w1 = write(fd, buffer1, sizeof(buffer1));
        if(w1 == -1){
         perror("Failed to write with dup desc");
         return 1;
        }


	int fd2 = dup2(fd, fd1+1);
	    if (fd2 == -1) {
	        perror("dup2 failed");
	        close(fd);
	        close(fd1);
        	return 1;
   	 }
	    printf("fd2:%d\t",fd2);

        char buffer2[]="Msg from dup2 descriptor\n";
        int w2 = write(fd, buffer2, sizeof(buffer2));
        if(w2 == -1){
         perror("Failed to write with dup2 desc");
         return 1;
        }
	
	int fcntl_fd = fcntl(fd, F_DUPFD, fd2+1);
	if(fd==-1){
		perror("fcntl failed\n");
		return 1;
	}
	 printf("fcntl:%d\t",fcntl_fd);

	 char buff3[]="Msg from fcntl descriptor\n";
	 write(fcntl_fd,buff3, sizeof(buff3));


	close(fd);
	close(fd1);
	close(fd2);
	close(fcntl_fd);
	return 0;

}

/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 11.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 11.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
fd:3	fd1:4	fd2:5	fcntl:6	mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ cat file.txt
Msg from original descriptor
Msg from dup descriptor
Msg from dup2 descriptor
Msg from fcntl descriptor

*/
