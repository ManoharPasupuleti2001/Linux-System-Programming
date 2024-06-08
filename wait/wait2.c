#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
 int main(int argc,char *argv[])
 {
 int status= 0xd4c3b2a1;
 printf("Process ID :%d EXIT STATUS :%p\n",getpid(),WEXITSTATUS(status));
 return 0;
 }
