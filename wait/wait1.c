#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int child,status;
	pid_t ppid,pid;
	child = fork();
	pid = getpid();
	ppid = getppid();
	if(child == -1)
	perror("child is not created!");
	else if(child != 0 )
	{
	printf("I am the parent %d of child %d\n",pid,child);
	status = wait(&status);
	printf("I am child process %d termination status %p : %p\n",child,status,WEXITSTATUS(status));
	return 0;	
	}
	else
	{
	printf("I am the Child %d of the parent %d\n",pid,ppid);
	printf("Enter the Exit Status:");
	scanf("%d",&status);
	exit(status);
	}


}
