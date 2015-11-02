#include <stdio.h>
#include<stdlib.h>
int main (int argc,char** argv)
{
  FILE *file;
  int i,j;
  int rows,cols;
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
  
  int **matrix1 = (int **)malloc(rows * sizeof(int*));
  for(i = 0; i < rows; i++)
    {
      matrix1[i] = (int *)malloc(cols * sizeof(int));
    }
  int **matrix2 = (int **)malloc(rows * sizeof(int*));
  for(i = 0; i < rows; i++)
    {
      matrix2[i] = (int *)malloc(cols * sizeof(int));
    }
  int** matrix3 = (int **)malloc(rows * sizeof(int*));
  for(i = 0; i < rows; i++)
    {
      matrix3[i] = (int *)malloc(cols * sizeof(int));
    }

  i=0;
  while(!feof(file))
    {
      for(i=0;i<rows;i++)
        {
	  for(j=0;j<cols;j++)
	    fscanf(file,"%d",&matrix1[i][j]);
        }
      for(i=0;i<rows;i++)
        {
          for(j=0;j<cols;j++)
            fscanf(file,"%d",&matrix2[i][j]);
        }

    }
  fclose(file);
  for(i = 0;i<rows;i++)
    {
      for(j=0;j<cols;j++)
	{
	  matrix3[i][j] = matrix1[i][j]+matrix2[i][j];
	}
    }

  for(i = 0;i<rows;i++)
    {
      for(j=0;j<cols;j++)
        {
          printf("%d\t",matrix3[i][j]);
	  if (j == cols - 1)
	    {
	      printf("\n");
	    }
        }
    }
  for(i=0;i<rows;i++)
    {
      free(matrix1[i]);	
    }
  free(matrix1);
  for(i=0;i<rows;i++)
    {
      free(matrix2[i]);
    }
  free(matrix2);
  for(i=0;i<rows;i++)
    {
      free(matrix3[i]);
    }
  free(matrix3);
  
  return 0;

}
