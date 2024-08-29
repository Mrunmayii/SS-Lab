/*
============================================================================
Name: 10.c
Author: Mrunmayi Shirke
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. 
Date: 29 Aug, 2024
============================================================================

*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("Failed\t");
    }
    
    char *buffer="Hello hey";
    int write1 = write(fd, buffer,10);
    printf("write1 val:%d\n",write1);
    
    int lseekval = lseek(fd,10,SEEK_CUR);
    printf("lseek return value: %d \n",lseekval);

    char *buffer2="Hello mee";
    int write2 = write(fd, buffer2, 10);
    printf("write2 val:%d\n",write2);

    return 0;
}

/*
============================================================================
OUTPUT: 
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ vim 10.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ gcc 10.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ ./a.out
write1 val:10
lseek return value: 20 
write2 val:10
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ od -b test.txt
0000000 110 145 154 154 157 040 150 145 171 000 000 000 000 000 000 000
0000020 000 000 000 000 110 145 154 154 157 040 150 145 171 000
0000036
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/Desktop/linux_ta$ od -c test.txt
0000000   H   e   l   l   o       h   e   y  \0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   H   e   l   l   o       h   e   y  \0
0000036
============================================================================

*/
