#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
	int pid1,pid2;
	int i;
	lockf(1,1,0);//lock Io resource
	printf("Parent process:a\n");
	if((pid1=fork())<0)//child process 1 create failed
	{	
	printf("child1 fail create\n");
	return 0;
	}
	else if(pid1==0)//child process 1 executing
	{	//lockf(1,1,0);//lock IO resource
		for(i=0;i<500;i++)//output pid for 500 times
		{
			printf("This is child1(pid=%d) process:b, number=%d\n",getpid(),i);
		
		}
		//lockf(1,0,0);//unlock Io resource
		return 0;
	}
	if((pid2=fork())<0)//child process 2 create failed
	{
		printf("child2 fail create\n");
		return 0;
	}
	else if(pid2==0)//child process 2 executing
	{	
		//lockf(1,1,0);//lock Io resource
		for(i=0;i<500;i++)//output pid for 500 times
		{
			printf("This is child2(pid=%d) process:c, number=%d\n",getpid(),i);
		}	
		//lockf(1,0,0);//unlock Io resource
		return 0;
	}
}


