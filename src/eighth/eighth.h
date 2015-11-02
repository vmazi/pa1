#ifndef EIGHTH_H_
#define EIGHTH_H_

struct BST;
struct BST* create (int data);
struct BST*  getNode(struct BST* node, int target,int* height);
void insert(int newData, struct BST** input);
void search (int newData, struct BST* input);

#endif




