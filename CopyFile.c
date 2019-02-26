#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64
#define TOT 4

void upper_string(char s[]);

int main()
{
  char line[TOT][BUF];
  FILE *fp, *fp1, *fp2 = NULL;
  int i = 0;
  int total = 0;
  char c;
  char oldname[] = "todolist.txt";
  char newname[] = "toDoList.txt";

  fp = fopen("todolist.txt", "r");
  while(fgets(line[i], BUF, fp))
    {
      if(i == 3)
	{
	  line[i][strlen(line[i])] = '\0';
	  i++;
	}
      else
	{
	  line[i][strlen(line[i])-1] = '\0';
	  i++;
	}   
    }
  fclose(fp);
  total = i;

  printf("The original file contents are: \n");
  for(i = 0; i < total; i++)
    printf("%s\n", line[i]);

  upper_string(line[2]);
  printf("\n");

  fp1 = fopen("todolist.txt", "w");
  fprintf(fp1, "%s \n", line[0]);
  fprintf(fp1, "%s \n", line[1]);
  fprintf(fp1, "%s \n", line[2]);
  fprintf(fp1, "%s \n", line[3]);

  fclose(fp1);

  rename(oldname, newname);

  printf("The changed file contents are: \n");

  fp2 = fopen("toDoList.txt", "r");
  while((c = fgetc(fp2)) != EOF)
  {
       printf("%c", c);
  }
  fclose(fp2);

return 0;
  
}

void upper_string(char s[])
{
  int c = 0;
  
  while(s[c] != '\0')
  {
    if( s[c] >= 'a' && s[c] <= 'z')
      {
         s[c] = s[c] - 32;
      }
    c++;  
  }
}
