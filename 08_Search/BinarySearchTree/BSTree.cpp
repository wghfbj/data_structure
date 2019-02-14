#ifndef _BTREE_CPP_
#define _BTREE_CPP_

#include "BSTree.h"


//=============TreeNode
template <class TLinklist>
TreeNode<TLinklist>::TreeNode(TLinklist data)
{
	this->data = data;
	this->bRight = NULL;
	this->bLeft = NULL;
}

//=============BTree
template <class TLinklist>
BTree<TLinklist>::BTree()  //创建树 //O(1)
{
	root = NULL;
	Length = 0;
}

template <class TLinklist>
BTree<TLinklist>::~BTree()  //销毁树  //O(1)
{
	ClearBTree();
	if(root != NULL)
	{
		delete(root);
		root = NULL;
	}
}

template <class TLinklist>
int BTree<TLinklist>::ClearBTree()  //清空树 //O(1)
{
	if(root != NULL)
	{

	}
	Length = 0;
	return TRUE;
}

template <class TLinklist>
TLinklist BTree<TLinklist>::DeleteBTree(long pPos, unsigned int count) //删除树中的元素 //O(n)
{
	TLinklist ret = FALSE;
	unsigned int tCount = count;
	long tPos = pPos;
	if(root != NULL)
	{
		bool tBit = pPos & 0x01;
		TreeNode<TLinklist> *CurrNode = root;
		TreeNode<TLinklist> *ParNode = root;
		while((CurrNode != NULL) && (count != 0))
		{
			ParNode = CurrNode;
			if(tBit == B_RIGHT)
			{
				CurrNode = CurrNode->bRight;
			}
			else if(tBit == B_LEFT)
			{
				CurrNode = CurrNode->bLeft;
			}
			count--;
			pPos = pPos>>1;
			tBit = pPos & 0x01;
		}
		if(CurrNode != NULL)
		{
			long tmpr = (tPos<<1) | B_RIGHT;
			long tmpl = (tPos<<1) | B_LEFT;
			DeleteBTree(tmpr, tCount+1);
			DeleteBTree(tmpl, tCount+1);
			delete(CurrNode);
			CurrNode = NULL;
			if(tBit == B_RIGHT)
			{
				ParNode->bRight = NULL;
			}
			else if(tBit == B_LEFT)
			{
				ParNode->bLeft = NULL;
			}
			Length--;
		}
	}
	return ret;
}

template <class TLinklist>
TLinklist BTree<TLinklist>::InsertBTree(TLinklist *data, long pPos, unsigned int count) //在树中的某个位置添加元素  //O(n)
{
	TLinklist ret = FALSE;
	TreeNode<TLinklist> *tNode = new TreeNode<TLinklist>(*data);
	if((data != NULL) && (tNode != NULL))
	{
		bool tBit = pPos & 0x01;
		TreeNode<TLinklist> *tNode = new TreeNode<TLinklist>(*data);
		TreeNode<TLinklist> *CurrNode = root;
		while((CurrNode != NULL) && (count != 0))
		{
			if(tBit == B_RIGHT)
			{
				CurrNode = CurrNode->bRight;
			}
			else if(tBit == B_LEFT)
			{
				CurrNode = CurrNode->bLeft;
			}
			count--;
			pPos = pPos>>1;
			tBit = pPos & 0x01;
		}

		if(CurrNode == NULL) //Add root node
		{
			root = tNode;
			Length++;
			ret = TRUE;
		}
		else
		{
			if(tBit == B_RIGHT)
			{
				CurrNode->bRight = tNode;
				Length++;
				ret = TRUE;
			}
			else if(tBit == B_LEFT)
			{
				CurrNode->bLeft = tNode;
				Length++;
				ret = TRUE;
			}
		}
	}
	else
	{
		delete(tNode);
		tNode = NULL;
	}
	return ret;
}

template <class TLinklist>
TreeNode<TLinklist>* BTree<TLinklist>::GetBTree(long pPos, unsigned int count) //获取树中某个位置的元素 //O(n)
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		bool tBit = pPos & 0x01;
		TreeNode<TLinklist> *CurrNode = root;
		while((CurrNode != NULL) && (count != 0))
		{
			if(tBit == B_RIGHT)
			{
				CurrNode = CurrNode->bRight;
			}
			else if(tBit == B_LEFT)
			{
				CurrNode = CurrNode->bLeft;
			}
			count--;
		}
		ret = CurrNode;
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index) //回溯获取当前树的高度
{
	int ret = 0;
	if(ChiNode != NULL)
	{
		ret = index;
		int tindexx = RecursiveNodeHeight(ChiNode->bLeft, index+1);
		if(tindexx > ret)
		{
			ret = tindexx;
		}
		tindexx = RecursiveNodeHeight(ChiNode->bRight, index+1);
		if(tindexx > ret)
		{
			ret = tindexx;
		}
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeHeight() //获取树当前树的高度
{
	int ret = 0;
	if(root != NULL)
	{
		TreeNode<TLinklist> * rootNode = root;
		ret = RecursiveNodeHeight(rootNode, 1);
	} 
	return ret; 
}

template <class TLinklist>
TreeNode<TLinklist>* BTree<TLinklist>::GetRootBTree(void) //获取树中根节点
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		ret = root;
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeCount(void) //获取当前树的节点数
{
	int ret = 0;
	if(root != NULL)
	{
		ret = Length;
	} 
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode) //回溯查找子节点的度 
{
	int ret = 0;
	if(ChiNode != NULL)
	{
		if((ChiNode->bLeft != NULL) && (ChiNode->bRight != NULL))
		{
			ret = 2;
		}
		else if((ChiNode->bLeft != NULL) || (ChiNode->bRight != NULL))
		{
			ret = 1;
		}

		int tmp = RecursiveNodeDegree(ChiNode->bLeft);
		if(ret < tmp)
		{
			ret = tmp;
		}
		tmp = RecursiveNodeDegree(ChiNode->bLeft);
		if(ret < tmp)
		{
			ret = tmp;
		}
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeDegree(void) //获取当前树的度
{
	int ret = 0;
	if(root != NULL)
	{
		TreeNode<TLinklist> * rootNode = root;
		ret = RecursiveNodeDegree(rootNode);
	}
	return ret;
}

template <class TLinklist>
void BTree<TLinklist>::RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank) //回溯打印子节点
{
	for(unsigned int tindexx = 0; tindexx< Blank*4; tindexx++)
	{
		printf("-");
	}
	if(ChiNode != NULL)
	{
		printf("%c\n", ChiNode->data);
		if((ChiNode->bLeft != NULL) || (ChiNode->bRight != NULL))
		{
			RecursiveShowChild(ChiNode->bLeft, Blank+1);
			RecursiveShowChild(ChiNode->bRight, Blank+1);
		}
	}
	else
	{
		printf("\n");
	}
} 

template <class TLinklist>
void BTree<TLinklist>::ShowBTree(void) //打印树中所有元素  //O(n)
{
	if(root != NULL)
	{
		TreeNode<TLinklist> * rootNode = root;
		printf("\n");
		RecursiveShowChild(rootNode, 1);
		printf("\n");
	} 
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeSerch(TLinklist Des)   //获取Des数据在组织链表中的位置并打印对应路径
{
	int ret = 0;
	
	return ret;
}

#endif //_BTREE_CPP_
