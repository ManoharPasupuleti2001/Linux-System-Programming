#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int child,wpid,status;
pid_t pid,ppid;
char *env[] = {"PATH:./op/hello",NULL};
child = fork();
pid = getpid();
ppid =getppid();
if(child == -1)
{
perror("No child is created!\n");
}
else if(child == 0)
{
printf("I am child :%d of thhhe parent :%d\n",pid,ppid);
execvpe("op/hello",&argv[1],env);
exit (1);
}
else 
{
printf("I am the Parent:%d of child :%d\n",pid,child);
wpid=wait(&status);
printf("Received child:%d termination status %p :%p\n",wpid,status,WEXITSTATUS(status));
exit (2);
}
return 0;
}
