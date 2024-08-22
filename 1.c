//Name: Mrunmayi Shirke
//Roll No: MT2024144
//Problem Statement: 1. Create the following types of a files using (i) shell command (ii) system call a). soft link (symlink system call)

#include<stdio.h>
#include<unistd.h>
int main(){
  symlink("newfile", "softlinknew");
  perror("output");
}

