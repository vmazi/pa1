#include <stdio.h>
#include<stdlib.h>
#include "third.h"
struct linknode 
{
  
  int data;
  struct linknode* next;
};//linked list to handle collisions.

struct hashtable
{
  
  struct linknode** table;
};

struct hashtable* createhashtable(int size)
{
  int i;
 struct hashtable* new;
 new = (struct hashtable*)malloc(size*sizeof(struct hashtable));
 new->table = (struct linknode**)malloc(size*sizeof(struct linknode*));
   for(i=0;i< size;i++)
     {
       new -> table[i] = NULL;
     }
 
 return new;
}
void addVal(int input,struct hashtable* here)
{
  struct linknode** table = here->table;
  struct linknode* ptr;
  
  int key;
  key = input%10000;

  if (!table[key])
    {
      ptr = (struct linknode*) malloc(sizeof(struct linknode));
      
      ptr->data = input;
      ptr->next = NULL;
      table[key] = ptr;
      printf("inserted\n");
    }
  else
    {
      ptr = table[key];

      while(ptr->next)
	{
	  if(input == ptr->data)
	    {
	      printf("duplicate\n");
	      return;
	    }
	  ptr=ptr->next;
	}
      if(ptr->data != input)
	{
	  ptr->next = (struct linknode*) malloc(sizeof(struct linknode));
     
	  ptr->next->data = input;
	  ptr->next->next = NULL;
      
	  printf("inserted\n");
	}
      else if(ptr->data == input)
	{
	  printf("duplicate\n");
	  return;

	}
    }
}

void searchVal(int input,struct hashtable* here)
{
  struct linknode** table = here->table;
  struct linknode* ptr;
  
  int key;
  key = input%10000;

  if (!table[key])
    {
      
      printf("absent\n");
    }
  else
    {
      ptr = table[key];

      while(ptr->next)
        {
          if(input == ptr->data)
            {
              printf("present\n");
              return;
            }
          ptr=ptr->next;
        }
      if(ptr->data != input)
        {
          

          printf("absent\n");
        }
      else if(ptr->data == input)
        {
          printf("present\n");
          return;

        }
    }
}


int main (int argc, char** argv)
{
  struct linknode* tmp;
  struct linknode* garb;
  struct linknode** trash;
  struct hashtable* hash;
  hash = createhashtable(10000);
  FILE* file;
  char line[100];  
  int data;
  char letter;
  int i;  
  if(argc !=2)
    {
      printf("error\n");
      return 0;
    }  
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
	  if(feof(file))
	    {
	      break;
	    }
          sscanf(line,"%c %d",&letter,&data);

          switch(letter)
            {
            case 'i':
	      addVal(data,hash);
              break;
            case 's':
	      searchVal(data,hash);	      
              break;
	    case '\n':
	      break;
            default:
              printf("error\n");
              break;
            }
        }
     
    }
  trash = hash->table;

  for(i=0;i<10000;i++)
    {
      garb = trash[i];
      while(garb)
	{
	  tmp = garb;
	  garb = garb->next;
	  free(tmp);
      }
    }
  free(trash);
  free(hash);
  return 0;
}
