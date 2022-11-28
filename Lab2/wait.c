#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
int pid_t,pid;
int status,i;

if((pid=fork())<0){  //create child process failed
	printf("create child process failed\n");
}else if (pid == 0){   //child process executing
	printf("This is the child process.pid =%d\n",getpid());//output the pid of child process
	exit(5); //the exit code of child process is 5
}
else{ //father process executing
	sleep(1); //father process sleep for 1s
	printf("This is the parent process,wait for child...\n");
	pid=wait(&status); //waiting for the result of child proce	
	i=WEXITSTATUS(status); //extract the exit code from status
	printf("child's pid =%d.exit status=%d\n",pid,i); //output the pid and exit code
}
}
