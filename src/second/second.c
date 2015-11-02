  
#include <stdio.h>
#include <stdlib.h>
#include "second.h"
 struct listnode
{
  int data;
  struct listnode* next;
};

struct listnode*  addEnd (int val,struct listnode* list)
{
  struct listnode* ptr1;
  
  struct listnode* new;
  new = (struct listnode*) malloc(1*sizeof(struct listnode));
  new->data = val;
  new->next = NULL;

  if (!list)
    {
         
      return  new;                    
    }
  else
    {
      ptr1 = list;
      while(ptr1->next!=NULL)
	{
	  if(ptr1->data == val)
	    {
	      free(new);
	      return list;
	    }
	  ptr1 = ptr1->next;
	}
      if(ptr1->data == val)
	{
	  free(new);
	  return list;
	}

      
      ptr1->next = new;
      return list;
    }
  

}
void printNode(struct listnode* input)
{
  struct  listnode* ptr = input;
  
  while (ptr!=NULL)
    {
      if(ptr->next==NULL)
	{
	  printf("%d",ptr->data);
	  return;
	}
      printf("%d\t", ptr->data);
      ptr =  ptr->next;
    }
   
}

void  split(struct listnode* input,struct listnode** left, struct listnode** right)
{ struct listnode* normal;
  struct listnode* fast;
  
  normal = input;
  if (!normal->next)
    {
      *left = input;
      *right = NULL;
      return;
    }
  fast = normal->next;
  while(fast&&fast->next)
    {
      fast = fast->next;
      normal = normal->next;
      if(!fast->next)
	{
	  break;
	}
      fast= fast->next;
    }
  
  *left = input;
 
  *right = normal->next;
  normal->next = NULL;
  return;

}
struct listnode*  deleteNode(struct listnode* del, int tdel)
{
  if(del == NULL)
    {
      return del;
    }  
  struct listnode* jc = del;
  struct listnode* tmp;
  if(jc->data == tdel&&jc->next == NULL)
    {
      
      free(jc);
      del = NULL;;
      return del;     
    }
  else if(jc->data ==tdel&&jc->next)
    {
      tmp = del->next;
      free(del);
      
      del = tmp;
      return del;
    }
  else
    {
      while(jc->next)
	{
	  if(jc->next->data == tdel)
	    {
	      if(!jc->next->next)
		{
		  free(jc->next);
		  jc->next = NULL;
		  return del;
		}
	      else
		{
		  tmp = jc->next->next;
		  free(jc->next);
		  jc->next = tmp;
		  return del;
		}
	    }
	  else
	    {
	      jc = jc->next;
	    }
	}

    }
  return del;
}

struct listnode* merge(struct listnode* left, struct listnode* right)
{
  struct listnode* output = NULL;
  if (!left)
    {
      return right;
    }
  else if(!right)
    {
      return left;
    }
  else if(left->data == right->data)
    {
      output = left;
      output->next = merge(left->next,right);
    }
  else if(left->data < right-> data)
    {
      output = left;
      output->next = merge(left->next, right);
    }
  else
    {
      output = right;
      output->next = merge(left,right->next);
    }
  return output;
}
void mergesort(struct listnode** unsort)
{
  struct listnode* left = NULL;
  struct listnode*  right = NULL;  
  struct listnode* tmp = NULL;
  tmp = *unsort;
  if(!tmp||!tmp->next)
    {
      return;
    }
  
  split(tmp,&right,&left);
 
 
  mergesort(&left);
  mergesort(&right);
  
  *unsort= merge( left,right);
  
}


int main (int argc, char** argv)
{
  if(argc != 2)
    {
      return 0;
    }
  
  struct listnode* input = NULL;
  
  struct listnode* garb = NULL; 
  FILE* file;
  char  letter;
  int data;
  char line [80];
  file = fopen(argv[1],"r");
  if(!file)
    {
      printf("error\n");
      return 0;
    }
  else
    {
      
      while((fgets(line,sizeof(line),file)))
   	{
	  
	  
	  sscanf(line,"%c %d",&letter,&data);
	  
	  switch(letter)
	    {
	    case 'i':
	      input = addEnd(data,input);
	      mergesort(&input);
	      break;
	    case 'd':
	      input =  deleteNode(input,data);
	      break;
	    case '\n':
	      break;
	    case '\t':
	      break;
	    default:
	      printf("error\n");
      	      while(input)
		{
		  garb = input;
		  input = input->next;
		  free(garb);
		}	     
	    }
	}
      printNode(input);
      printf("\n");
    }

  while(input)
    {
      garb = input;
      input = input->next;
      free(garb);
    }
  return 0;
}
