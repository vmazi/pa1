#include <stdio.h>
#include<stdlib.h>
#include "eighth.h"
struct BST 
{
  struct BST* Lsubtree;  
  struct BST* Rsubtree;  
  int data; 
  
};


struct BST* create (int data)
{
  struct BST* new = (struct BST*) malloc(1*sizeof(struct BST));
  new->data = data;
  new->Lsubtree = NULL;
  new->Rsubtree = NULL;
  return new;
}


struct BST*  getNode(struct BST* node, int target,int* height)
{
  struct BST* result = NULL;
  if(node==NULL){
    return node;
  }
  else if(node->data == target){
    return node;

  }
  else if(target < node->data&&node->Lsubtree==NULL){
    return node;
  }
  else if(target>node->data&&node->Rsubtree==NULL){
    return node;
  }
  if(target < node->data){
    *height=*height+1;
     result = getNode(node->Lsubtree,target,height);
     return result;
  }
  else{
    *height=*height+1;
    result = getNode(node->Rsubtree,target,height);
    return result; 
  }

}



void insert(int newData, struct BST** input)
{
  int height = 1;
  struct BST* insertedat =  getNode(*input, newData,&height);
  
  if(insertedat == NULL)
    {
    *input = create(newData);
    printf("inserted %d\n",height);
    }
  else if(insertedat->data == newData)
    {
    printf("duplicate %d\n",height);
    }
  else if(insertedat->data < newData)
    {
    insertedat->Rsubtree = create(newData);
    height++;
    printf("inserted %d\n",height);
    }
  else
    {
    insertedat->Lsubtree = create(newData);
    height++;
    printf("inserted %d\n",height);
    }
}


void search (int newData, struct BST* input)
{
  int height = 1;
  struct BST* insertedat =  getNode(input, newData,&height);

  if(insertedat == NULL)
    {
      printf("absent\n");
    }
  else if(insertedat->data == newData)
    {
      printf("present %d\n",height);
    }
  else
    {
      printf("absent\n");
    }
}





int main(int argc, char** argv)
{
  if(argc != 2)
    {
      printf("error\n");
      return 0;
    }
  char letter;
  int data;
  struct BST* tree = NULL;
  FILE* file;
  
  file = fopen(argv[1],"r");
    if(!file)
      {
	printf("error\n");
      }
  while (!feof(file))
    {
      fscanf(file,"%c",&letter);

      if (letter == '\n')
	{
	  if(!feof(file))
	    {
	      continue;
	    }
	  else
	    {
	      return 0;
	    }
	}
      else  if(letter == 'i')
	{
	  fscanf(file,"%d",&data);
	  insert(data,&tree);
	}
      else if(letter == 's')
	{
	  fscanf(file,"%d",&data);
	  search(data,tree);
	}
      else
	{
	  printf("error\n");
	  return 0;
	}
    }
  return 0;
}


