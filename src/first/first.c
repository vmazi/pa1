#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int input = 0;
  if (argc != 2)
    {
      printf("no number given\n");
    }
  else 
    {
     
      input = atoi(argv[1]);
    }
  int answer = 0;
  int i;


  for ( i =1; i< input;i++)
    {
      if (input%i ==0 && i!=1)
	{
	  answer =1;
	  break;
	}
      }
  if (answer==1)
    {
    printf("no\n");
    }
  else
    {
      printf("yes\n");
    }
  return 0;
}
