#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>


//Trevor Latchana, Unix Lab 7
//Program spawns a child process to execute another c program.

int main()
{
	int ret;

	pid_t pid;
	pid = fork();

	if(pid>0)
	  {
	    printf("Parent process pid = %jd\n", (__intmax_t)getppid());
	    printf("The file name is CS452_group2_lab07_1.c\n");
	  }

	else if(!pid)
	{
	  ret = execl("test","NULL", NULL);
	  if(ret == -1)
	    perror("execl");
	  
	  _exit(0);
	}

	else if(pid == -1)
	  perror("fork");


        return 0;

}
