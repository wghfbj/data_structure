#ifndef __HASH__H_
#define __HASH__H_

#include <iostream>
#include "BSTree.h"
#include "BSTree.cpp"

class Hash : public BSTree<int>
{
public:
	
	int InsertHash(int key, int *data);
	int* GetHash(int key);
};



#endif //__HASH__H_
