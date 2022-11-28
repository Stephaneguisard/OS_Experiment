#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	printf("this process will exit!\n");//process executing
        exit(0); //end the process
        printf("never be displayed!\n"); //since exit, this sentence won't be displayed
}


