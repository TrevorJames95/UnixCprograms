#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	int pid1;
	int pid2;

	pid1 = fork();

	if(pid1 == 0)
	{
	  printf("Child pid = %jd and parent pid = %jd\n", (__intmax_t)getpid(), (__intmax_t)getppid());
	
	  _exit(0);
	}
	
	pid2 = fork();

	if(pid2 == 0)
	{
	  printf("Child pid = %jd\n" , (__intmax_t)getpid());
	  _exit(0);
	}

        return 0;

}


