#include "Hash.h"


int Hash::InsertHash(int key, int* data)
{
	InsertBSTree(key, data);
}

int* Hash::GetHash(int key)
{
	TreeNode<int>* ret = GetBSTree(key);
	if(ret != NULL)
	{
		return ret->data;
	}

	return 0;
}


