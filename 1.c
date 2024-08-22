#include<stdio.h>
#include<unistd.h>
int main(){
  symlink("filenew", "sftlnk");
  perror("output");
}

