/*
============================================================================
Name : 1c.c
Author : Mrunmayi Shirke
Description : Create the following types of a files using (i) shell command (ii) system call c. FIFO (mkfifo Library Function or mknod system call)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "myfifo";

    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    printf("FIFO '%s' created successfully.\n", fifo_path);
    return 0;
}

/*
OUTPUT:
  Terminal 1:
  mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 1c.c
  mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 1c.c
  mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
  FIFO 'myfifo' created successfully.
  mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ cat < myfifo
  Hello

  Terminal 2:
  mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ echo "Hello" > myfifo


*/
