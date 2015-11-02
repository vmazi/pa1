#ifndef NINTH_H_
#define NINTH_H_


struct BST;
struct BST* create (int data);
struct BST*  getNode(struct BST* node, int target,int* height);
void insert(int newData, struct BST** input);
void delete(int data,struct BST* del);
void search (int newData, struct BST* input);
#endif




