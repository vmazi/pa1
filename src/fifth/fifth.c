#include <stdio.h>
#include<stdlib.h>
int main (int argc,char** argv)
{
  FILE *file;
  int i,j,e;
  int rows,cols,rows2,cols2;
  if(argc !=2)
    {
      return 0;
    }

  file = fopen(argv[1],"r");
  if(!file)
    {
      return 0;
    }
 
  
      fscanf(file,"%i",&rows);
      fscanf(file,"%i",&cols);

      int **right = (int **)malloc(rows * sizeof(int*));
      for(i = 0; i < rows; i++)
	{
	  right[i] = (int *)malloc(cols * sizeof(int));
	}

      for(i=0;i<rows;i++)
        {
          for(j=0;j<cols;j++)
            fscanf(file,"%d",&right[i][j]);
        }
      fscanf(file,"%d",&rows2);
      fscanf(file,"%d",&cols2);
      if(cols!= rows2)
	{
	  return 0;
	}

      int **left = (int **)malloc(rows2 * sizeof(int*));
      for(i = 0; i < rows2; i++)
	{
	  left[i] = (int *)malloc(cols2 * sizeof(int));
	}

      int **output = (int **)malloc(rows * sizeof(int*));
      for(i = 0; i < rows; i++)
        {
          output[i] = (int *)malloc(cols2 * sizeof(int));
        }



      for(i=0;i<rows2;i++)
	{
	  for(j=0;j<cols2;j++)
	    fscanf(file,"%d",&left[i][j]);
	}
    
  fclose(file);
  

  for(i=0;i<cols2;i++)
    {
      for(j=0;j<cols2;j++)
	{

	  output[i][j] = 0;
	}
    }
  for(i=0;i<rows;i++)
    {
      for(j=0;j<cols2;j++)
	{
	  for(e=0;e<cols;e++)
	    {
	      output[i][j]+=right[i][e]*left[e][j];
	    }
	}
    }
  for(i=0;i<rows;i++)
    {
      for(j=0;j<cols2;j++)
        {
	  printf("%d\t", output[i][j]); 
	  if(j==cols2-1)
	    {
	      printf("\n");
	    }
        }
    }

  return 0;
}
