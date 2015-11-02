#ifndef THIRD_H_
#define THIRD_H_

struct linknode;
struct hashtable;
struct hashtable* createhashtable(int size);
void addVal(int input,struct hashtable* here);
void searchVal(int input,struct hashtable* here);
#endif
