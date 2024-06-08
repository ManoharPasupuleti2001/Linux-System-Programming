#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	pid_t pid,ppid;
	int child;
	child = fork();
	fork();
	pid = getpid();
	ppid = getppid();
	if(child == -1)
	{
	perror("child not created!\n");
	exit(0);
	}
	else if(child == 0)
	{
	printf("I am the child(%d) of parent :%d \n",pid,ppid);
	return 0;
	}
	else
	{
	printf("I the parent(%d) of child Process:(%d)\n",pid,child);
	return 0;
	}

}
