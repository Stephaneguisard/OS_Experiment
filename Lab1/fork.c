# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{
int pid1,pid2;

printf ("I am father!\n");// father process having cpu
if ((pid1 = fork())<0)//son process create failed
{
printf("Child1 fail create!\n");
return 1;
}
else if (pid1 == 0)//son process having cpu
{
printf("I am son!\n");
return 0;
}
if ((pid2 = fork())<0)//daughter process create failed
{
printf("Child2 fail create!");
return 1;
}
else if (pid2 == 0)// daughter process having cpu
{
printf("I am daughter!\n");
return 0;
}
}
