#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{

	printf("Parent process pid = %jd\n", (__intmax_t)getpid());
	printf("The file name is: CS452_group2_lab07_2.c\n");
       
	return 0;

}
