#include <sys/types.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int i,j,fd[2]; 
	char s[100];
	pipe(fd);
	if (i=fork()==0) // child process 1 executing
	{
		sprintf(s,"child Process 1 is sending a message! \n"); // write str into S 
		write(fd[1],s,50); // write S into pipe with filedes [1] 
		sleep(3); // sleep for 3s 
		return 0;
	}
	if (j=fork()==0) // child process 2 executing
	{
		sprintf(s,"child Process 2 is sending a message! \n"); // write str into S 
		write(fd[1],s,50); // write S into pipe with filedes [1] 
		sleep(3); // sleep for 3s 	
		return 0;
	}
	else
	{
		wait(0);
		read(fd[0],s,50); // read from pipe with filedes [0] to S 
		printf("%s",s) ;// output S
		read(fd[0],s,50);// read from pipe with filedes[0] to S
		printf("%s",s); // output S 
		return 0;
	}
}
