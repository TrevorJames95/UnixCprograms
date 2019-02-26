#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{

   printf("My pid=%jd\n", (__intmax_t)getpid());

  return 0;
}
