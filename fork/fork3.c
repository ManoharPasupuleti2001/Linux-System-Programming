#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>

int main(int argc,char *argv[])
{
	int child;
	pid_t pid,ppid;
	child = fork();
	pid = getpid();
	ppid = getppid();
	if(child == -1)
	{
	perror("child is not created");
	exit (0);
	}
	else if(child == 0)
	{
	printf("i am child:%d of parent process:%d\n",pid,ppid);
	sleep(10);
	exit (1);
	}
	else 
	{
	printf("received child exit status:%d",WEXITSTATUS())
	printf("i am parent:%d of  child process:%d\n",pid,child);
	exit (2);
	}
return 0;
}
