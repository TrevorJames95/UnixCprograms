//Trevor Latchana CS-452
//Unix Lab 01, Reading bytes from a file.
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{	
	int fd;
	char fn[60];
	int close(int fd);
    char c;
	int counter = 0;
	ssize_t nr;
	
	printf("Please enter the name of the file to read the first 20 bytes from: \n");
	scanf("%s", fn);
	
	//Opens the file for reading only
	fd = open(fn, O_RDONLY);	
	if (fd == -1)
	{
		printf("Unable to open the file.\n");	// error message
	}
	
	//Reading bytes from the file, read function taken from textbook.
	while(counter < 20)
	{
	    nr = read(fd, &c, sizeof(c));
		if (nr == -1)
		{
			printf("Error reading from file.\n");	
		}
	
		printf("%c ", c);
		
		counter++;	
	}

	//Closes the file, prints an error if it doesn't close.
	if (close(fd) == -1)
	{
		printf("Unable to close the opened file.\n");
	}	
	
	return 0;
}
