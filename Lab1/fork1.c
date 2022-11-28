# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{
 	int pid1,pid2;
	printf("I am father!\n");//requring IO source
	if ((pid1 = fork())<0)//create son process failed
	{
   	printf("Child1 fail create!\n");
   	return 1;
	}
	else if (pid1 == 0)// son process executing
	{
	printf("I am son!\n"); //requiring IO source
	return 0;
	}

	else if (pid1 > 0)//get the process id of son process, and id > 0	
	{
      
	  if ((pid2 = fork()) < 0)//create grandson process failed
	  {
  		printf("child2 create failed\n");
  		return 1;
	  }
	  else if (pid2 == 0)//grandson process executing
	  {
		printf("c\n");// requiring IO source
		return 0;
          }
	}
	return 0;
}

