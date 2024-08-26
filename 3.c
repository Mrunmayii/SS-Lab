//Name: Mrunmayi Shirke
//Roll No: MT2024144
//Problem Statement: 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
 char *fname ="newfile.txt";
 int filedesc = creat(fname, S_IRWXU|S_IRGRP|S_IROTH);
 if(filedesc == -1){
  printf("Error");
  return 1;
 }
 printf("file descriptor val: %d\n", filedesc);
 close(filedesc);
 
}

//mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ gcc 3.c
//mrunmayi@mrunmayi-HP-Laptop-14s-dr1xxx:~/SS-Lab$ ./a.out
//file descriptor val: 3

