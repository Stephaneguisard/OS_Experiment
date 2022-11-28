#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int filedes[2]; 
	char buf[80];
	int pid_t,pid;
	pipe( filedes ); // set pipe read and write 
	if ( (pid=fork()) == 0 ) // child peocess executing
	{
		printf("This is in the child process, here read a string from the pipe.\n" );
		read(filedes [0], buf, sizeof (buf)); // read str from pipe 
		printf("%s\n",buf);// output the str 
		close (filedes[1]);//close pipe read
		close(filedes [1]);// close pipe write
	}
	else
	{
		//father process executing
		sleep(2);
		printf("This is in the father process, here write a string to the pipe.\n");
		char s[] = "Hello world, this is write by pipe. \n";
		write( filedes [1], s, sizeof(s) ); // write str to pipe 
		close( filedes [0] ); // close pipe read 	
		close( filedes [1] ); // close pipe write
	}
	waitpid(pid, NULL,0);
	return 0;
}



