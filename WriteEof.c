//Trevor Latchana CS-452
//Unix Lab 02, Open a file and use the Seek function to write to the end of the file.
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{	
	int fd;
	char fn[60];
	int close(int fd);
	off_t ret;
	const char *buf = "THIS IS THE END OF THE FILE.";
	ssize_t nr;
	
	printf("Please enter the name of the file to write to: \n");
	scanf("%s", fn);
	
	//Opens the file for reading only
	fd = open(fn, O_WRONLY);	
	if (fd == -1)
	{
		printf("Unable to open the file.\n");	// error message
	}
	
	//Uses the lseek function to move the file pointer to the end of the file.
	ret = lseek (fd, 0, SEEK_END);
	if (ret == (off_t)-1)
	{
		printf("File pointer is not at the end of the file!.\n");
	}
	//Writes "THIS IS THE END OF THE FILE." to the opened file.
	nr = write (fd, buf, strlen (buf));
	if (nr == -1)
	{
		printf("Failed to write to the file.\n");
	}
	else 
		printf("Wrote to the end of the file.\n");
	//Closes the file, prints an error if it doesn't close.
	if (close(fd) == -1)
	{
		printf("Unable to close the opened file.\n");
	}	
	
	return 0;
}
