#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
int child,wpid,status;
pid_t pid,ppid;
child = fork();
pid = getpid();
ppid = getppid();

if(child == -1)
{
	perror("No child is created!");
}
else if(child == 0)
	{
	printf("I am child :%d of parent :%d\n",pid,ppid);
	printf("Calling EXECLE()\n");
	sleep(5);
	execle("op/wait5","wait5",NULL,NULL);
	exit (9);
	}
else 
{
	wait(NULL);
	printf("I am Parent:%d of child:%d exit status :%d \n",pid,child,WEXITSTATUS(status));
	return 0;
	
}
}
