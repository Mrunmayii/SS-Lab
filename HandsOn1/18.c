/*
============================================================================
Name : 18.c
Author : Mrunmayi Shirke
Description : Write a program to simulate online ticket reservation.
                Implement write lock
                Write a program to open a file, store a ticket number and exit.
                Write a separate program, to open the file, implement write lock,
                read the ticket number, increment the number and print
                the new ticket number then close the file.

Date: 30th Aug, 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct data {
	int val;
};

int main() {
	int fd = open("records.txt", O_RDWR);
	while(1) {
		int choice;
		printf("Enter record (1-3) to lock, or -1 to quit: ");
		scanf("%d", &choice);
		if(choice == -1) {
			break;
		}
		
		int offset = (choice - 1) * sizeof(struct data);
		lseek(fd, offset, SEEK_SET);
		
		printf("Acquiring record lock\n");
		
		struct flock lock;
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = offset;
		lock.l_len = sizeof(struct data);
		lock.l_pid = getpid();
		
		fcntl(fd, F_SETLK, &lock);
		printf("Lock acquired\n");
		
		struct data currRecord;
		read(fd, &currRecord, sizeof(currRecord));
		printf("Previous value of record: %d\n", currRecord.val);
		currRecord.val++;
		printf("Current value of record: %d\n", currRecord.val);
		
		lseek(fd, -sizeof(struct data), SEEK_CUR);
		
		write(fd, &currRecord, sizeof(currRecord));
		printf("Releasing record lock\n");
		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("Lock released\n");
	}
	return 0;
}
		
/*
OUTPUT:
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ vim 18.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 18.c
mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
Enter record (1-3) to lock, or -1 to quit: 1
Acquiring record lock
Lock acquired
Previous value of record: 0
Current value of record: 1
Releasing record lock
Lock released
Enter record (1-3) to lock, or -1 to quit: 1
Acquiring record lock
Lock acquired
Previous value of record: 1
Current value of record: 2
Releasing record lock
Lock released
Enter record (1-3) to lock, or -1 to quit: 3
Acquiring record lock
Lock acquired
Previous value of record: 2
Current value of record: 3
Releasing record lock
Lock released
Enter record (1-3) to lock, or -1 to quit: -1

*/
