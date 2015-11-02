#include <stdio.h>
#include<stdlib.h>
#include "ninth.h"
struct BST 
{
  struct BST* parent;
  struct BST* Lsubtree;  // left subtree of this tree (may be NULL)
  struct BST* Rsubtree;  // right subtree of this tree (may be NULL)
  int data; // data at this node of the tree
  
};


struct BST* create (int data)
{
  struct BST* new = (struct BST*) malloc(1*sizeof(struct BST));
  new->data = data;
  new->Lsubtree = NULL;
  new->Rsubtree = NULL;
  new->parent = NULL;
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
    insertedat->Rsubtree->parent = insertedat;
    height++;
    printf("inserted %d\n",height);
    }
  else
    {
    insertedat->Lsubtree = create(newData);
    insertedat->Lsubtree->parent = insertedat;
    height++;
    printf("inserted %d\n",height);
    }
}

void delete(int data,struct BST* del)
{ 
  struct BST* ptr;
  struct BST* par;
  struct BST* tmp;
  ptr = del;
  if(!del)
    {
      printf("failed\n");
      return;
    }

  else if(ptr->data == data)
    {
      if(ptr->Lsubtree == NULL&& ptr->Rsubtree == NULL) /*if node has no children*/
	{
	  if(ptr->parent ==NULL)/* if node has no parent*/
	    {
	      free(ptr);
	      del = NULL;
	      printf("success\n");
	      return;
	    }
	  else
	    {
	      par = ptr->parent;/*node has parent*/
	      if(ptr->data < par->data)/*node is left child*/
		{
		  par->Lsubtree = NULL;
		  free(ptr);
		  printf("success\n");
		  return;
		}
	      else
		{
		  par->Rsubtree = NULL;/*node is right child*/
		  free(ptr);
		  printf("success\n");
		  return;
		}
	    }
	}
      else if(ptr->Lsubtree == NULL || ptr->Rsubtree ==NULL)/*node has one child*/
	{
	  if (ptr->Lsubtree ==NULL)/*child is right child*/
	    {
	      if(ptr->parent == NULL)/*node has no parent*/
		{
		  tmp = ptr;
		  ptr =  ptr->Rsubtree;;
		  ptr->parent = NULL;
		  free(tmp);
		  del = ptr;
		  printf("success\n");
		  return;
		}
	      else/*node has a parent*/
		{
		  tmp = ptr;
		  par = ptr->parent;
		  ptr = ptr->Rsubtree;
		  ptr->parent = par;
		  if(ptr->data>par->data)
		    {
		      par->Rsubtree = ptr;
		    }
		  else
		    {
		      par->Lsubtree = ptr;
		    }
		  free(tmp);
		  printf("success\n");
		  return;
		}
	      
	    }
	  else/*child is left child*/
	    {
	      if(ptr->parent == NULL)/*node has no parent*/
                {
                  tmp = ptr;
                  ptr =  ptr->Lsubtree;;
                  ptr->parent = NULL;
                  free(tmp);
		  del = ptr;
		  printf("success\n");
                  return;
                }
              else/*node has parent*/
                {
                  tmp = ptr;
                  par = ptr->parent;
                  ptr = ptr->Lsubtree;
                  ptr->parent = par;
		  if(ptr->data>par->data)/*see if node was a right or left child*/
                    {
                      par->Rsubtree = ptr;
                    }
                  else
                    {
                      par->Lsubtree = ptr;
                    }

                  free(tmp);
		  printf("success\n");
                  return;
                }

	    }
	  
	}
      else/*node has two children*/
	{
	  tmp = ptr->Rsubtree;/*go to right child*/
	  while(tmp->Lsubtree!=NULL)/*find most minimun in right child's tree*/
	    {
	      tmp = tmp->Lsubtree;
	    }
	  ptr->data = tmp->data;/*copy minimum*/
	  par =tmp->parent;
	  if (tmp->data < par->data)/*true if node's right child has left child*/
	    {
	      if(tmp->Rsubtree == NULL)/*if minimum has no right child*/
		{
		  par->Lsubtree = NULL;
		  tmp->parent = NULL;
		  free(tmp);
		  printf("success\n");
		  return;
		}
	    
		else/*minimum has right child*/
		  {
		    par->Lsubtree = tmp->Rsubtree;;
		    tmp->Rsubtree->parent = par;
		    tmp->parent = NULL;
		    tmp->Rsubtree = NULL;
		    free(tmp);
		    printf("success\n");
		    return;
		  }
	    }
	  else/* only if nodes right child has no left child*/
	    {
	      if(tmp->Rsubtree == NULL)/*if right child has no right child*/
		{
		  par->Rsubtree = NULL;
		  tmp->parent = NULL;
		  free(tmp);
		  printf("success\n");
		  return;
		}
	      else/*node's right child has right child*/ 
		{
		  par->Rsubtree = tmp->Rsubtree;
		  tmp->Rsubtree->parent = par;
                  tmp->parent = NULL;
		  tmp->Rsubtree = NULL;
                  free(tmp);
                  printf("success\n");
                  return;

		}

	    }
	}
     
    }
  else/*node does not have data*/
    {
      if(ptr->data < data)
	{
	  delete(data,ptr->Rsubtree);

	}
      else
	{
	  delete(data,ptr->Lsubtree);
	}
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
      else if(letter == 'i')
	{
	  fscanf(file,"%d",&data);
	  insert(data,&tree);
	}
      else if(letter == 's')
	{
	  fscanf(file,"%d",&data);
	  search(data,tree);
	}
      else if(letter == 'd')
	{
	  fscanf(file,"%d",&data);
          delete(data,tree);
	}
      else
	{
	  printf("error\n");
	  return 0;
	}
    }
  return 0;
}


