#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<limits.h>

//Trevor Latchana, Unix Lab 6
//Program spawns a child process to print the current directory.

int main()
{
	pid_t pid;
	pid = fork();
	char cwd[PATH_MAX];

	if(pid>0)
	  {
	    printf("Parent process pid = %jd\n", (__intmax_t)getppid());
	  }
	else if(!pid)
	{
	  printf("Child pid = %jd\n", (__intmax_t)getpid());

	  if(getcwd(cwd, sizeof(cwd)) != NULL)
	  {
	    printf("Current working dir: %s\n", cwd);
	  }
	  else
	  {
	    perror("getcwd() error");
	  }
	  
	  _exit(0);
	}
	else if(pid == -1)
	  perror("fork");


        return 0;

}


