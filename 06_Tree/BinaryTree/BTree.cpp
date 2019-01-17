#ifndef _BTREE_CPP_
#define _BTREE_CPP_

#include "BTree.h"


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
BTree<TLinklist>::BTree()  //������ //O(1)
{
	root = NULL;
	Length = 0;
}

template <class TLinklist>
BTree<TLinklist>::~BTree()  //������  //O(1)
{
	ClearBTree();
	if(root != NULL)
	{
		delete(root);
		root = NULL;
	}
}

template <class TLinklist>
int BTree<TLinklist>::ClearBTree()  //����� //O(1)
{
	if(root != NULL)
	{

	}
	Length = 0;
	return TRUE;
}

template <class TLinklist>
TLinklist BTree<TLinklist>::RecursiveDeleteChild(Linklist<TLinklist>* ChiList) //����ɾ���ӽڵ�
{
	TLinklist ret = FALSE;
	if(ChiList != NULL)
	{

	}
	return ret;
}
 
template <class TLinklist>
TLinklist BTree<TLinklist>::DeleteBTree(unsigned int pPos) //ɾ�����е�Ԫ�� //O(n)
{
	TLinklist ret = FALSE;
	if(root != NULL)
	{

	}
	return ret;
}

template <class TLinklist>
TLinklist BTree<TLinklist>::InsertBTree(TLinklist *data, long pPos, int count, bool flag) //�����е�ĳ��λ�����Ԫ��  //O(n)
{
	TLinklist ret = FALSE;
	TreeNode<TLinklist> tNode = new TreeNode<TLinklist>(*data);
	if((data != NULL) && (tNode != NULL))
	{
		bool tBit = pPos & 0x01;
		TreeNode<TLinklist> tNode = new TreeNode<TLinklist>(*data);
		TreeNode<TLinklist> *ParNode = root;
		TreeNode<TLinklist> *CurrNode = root;
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
		}
		if(ParNode == NULL) //Add root node
		{
			root = tNode;
			Length++;
			ret = TRUE;
		}
		else
		{
			if(flag == B_RIGHT)
			{
				ParNode->bRight = tNode;
				Length++;
				ret = TRUE;
			}
			else if(flag == B_LEFT)
			{
				ParNode->bLeft = tNode;
				Length++;
				ret = TRUE;
			}
		}
	}
	return ret;
}

template <class TLinklist>
TreeNode<TLinklist>* BTree<TLinklist>::GetBTree(long pPos, int count) //��ȡ����ĳ��λ�õ�Ԫ�� //O(n)
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		ret = strL->GetLinklist(pPos);
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::RecursiveNodeHeight(LinkNode<TLinklist>* ChiNode, int index) //���ݻ�ȡ��ǰ���ĸ߶�
{
	int ret = 0;
	if(ChiNode != NULL)
	{
		ret = index;
		int tindexx = 0;
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildLength = tChildLinkList->GetLinklistLength();
			for(int tindexy = 0; tindexy<tChildLength; tindexy++)
			{
				tindexx = RecursiveNodeHeight(tChildLinkList->GetLinklist(tindexy), index+1);
				if(tindexx > ret)
				{
					ret = tindexx;
				}
			}
		}
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeHeight() //��ȡ����ǰ���ĸ߶�
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetBTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeHeight(rootNode, 1);
		}
	} 
	return ret; 
}

template <class TLinklist>
TreeNode<TLinklist>* BTree<TLinklist>::GetRootBTree(void) //��ȡ���и��ڵ�
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		ret = root;
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeCount(void) //��ȡ��ǰ���Ľڵ���
{
	int ret = 0;
	if(strL != NULL)
	{
		ret = strL->GetLinklistLength();
	} 
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::RecursiveNodeDegree(LinkNode<TLinklist>* ChiNode) //���ݲ����ӽڵ�Ķ� 
{
	int ret = 0;
	if(strL != NULL)
	{
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildDegree = tChildLinkList->GetLinklistLength();
			ret = tChildDegree;
			for(int tindex = 0; tindex<tChildDegree; tindex++)
			{
				int tmp = RecursiveNodeDegree(tChildLinkList->GetLinklist(tindex));
				if(tmp > tChildDegree)
				{
					ret = tmp;
				}
				else
				{
					ret = tChildDegree;
				}
			}
		}
	}
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeDegree(void) //��ȡ��ǰ���Ķ�
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetBTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeDegree(rootNode);
		}
	}
	return ret;
}

template <class TLinklist>
void BTree<TLinklist>::RecursiveShowChild(LinkNode<TLinklist>* ChiNode, unsigned int Blank) //���ݴ�ӡ�ӽڵ�
{
	if(ChiNode != NULL)
	{
		for(unsigned int tindexx = 0; tindexx< Blank*4; tindexx++)
		{
			printf("-");
		}
		printf("%c\n", ChiNode->data);
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildLength = tChildLinkList->GetLinklistLength();
			for(int tindexy = 0; tindexy<tChildLength; tindexy++)
			{
				RecursiveShowChild(tChildLinkList->GetLinklist(tindexy), Blank+1);
			}
		}
	}
} 

template <class TLinklist>
void BTree<TLinklist>::ShowBTree() //��ӡ��������Ԫ��  //O(n)
{
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetBTree(0);
		if(rootNode != NULL)
		{
			printf("\n");
			RecursiveShowChild(rootNode, 1);
			printf("\n");
		}
	} 
}

template <class TLinklist>
int BTree<TLinklist>::GetBTreeSerch(TLinklist Des)   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·��
{
	int ret = 0;
	
	return ret;
}

#endif //_BTREE_CPP_
