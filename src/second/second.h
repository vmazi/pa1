#ifndef FIRST_H_
#define FIRST_H_

struct listnode;

struct listnode*  addEnd (int val,struct listnode* list);
void printNode(struct listnode* input);
void  split(struct listnode* input,struct listnode** left, struct listnode** right);
struct listnode*  deleteNode(struct listnode* del, int tdel);
struct listnode* merge(struct listnode* left, struct listnode* right);
void mergesort(struct listnode** unsort);

#endif // SECOND_H_
