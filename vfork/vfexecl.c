#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
int child,status,Wpid;
pid_t ppid,pid;
child =vfork();
pid = getpid();
ppid = getppid();
if(child == -1)
{
perror("no child is created\n");
}
else if(child == 0)
{
printf("I am Child %d of parent %d\n",pid,ppid);
execl("./op/hello","hello",NULL);
exit(9);
}
else
{
printf("I am Parent %d of child %d\n",pid,child);
Wpid=wait(&status);
printf("Received child %d termination status %d : %d",Wpid,status,WEXITSTATUS(status));
return 0;
}

}
