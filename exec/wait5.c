#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int child1(void);
int parent(void);
int child,wpid,status;
pid_t pid,ppid;
int main(int argc,char *argv[])
{
child=fork();
pid = getpid();
ppid = getppid();
switch(child)
{
case -1:
{
perror("\n no child is created\n");
break;
}
case 0:
{
child1();
break;
}
default:
{
parent();
break;
}
}
return 0;
}

int child1(void)
{
	printf("I am the Child %d of the parent %d\n",pid,ppid);
	printf("Enter the Exit Status:");
	scanf("%d",&status);
	exit(status);
}

int parent(void)
{
	printf("I am the parent %d of child %d\n",pid,child);
	wpid = wait(&status);
	if(WIFSIGNALED(status)){
	printf("I am child process %d termination status %d : %p\n",child,status,WTERMSIG(status));
	}
	else{
	printf("I am child process %d termination status %p : %p\n",child,status,WEXITSTATUS(status));
	}
	return 0;
}
