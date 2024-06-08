#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
int  i=0,wpid;
printf("PID:%d\n",getpid());
while(1){
printf("Hello WOrld!\n");
sleep(2);
}
return 0;
}
