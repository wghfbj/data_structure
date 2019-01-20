#ifndef _BTREE_CPP_
#define _BTREE_CPP_

#include "BTree.h"
#include "Seqlist.cpp"


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
	position = NULL;
	SL = NULL;
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
TLinklist BTree<TLinklist>::DeleteBTree(long pPos, unsigned int count) //ɾ�����е�Ԫ�� //O(n)
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
TLinklist BTree<TLinklist>::InsertBTree(TLinklist *data, long pPos, unsigned int count) //�����е�ĳ��λ�����Ԫ��  //O(n)
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
TreeNode<TLinklist>* BTree<TLinklist>::GetBTree(long pPos, unsigned int count) //��ȡ����ĳ��λ�õ�Ԫ�� //O(n)
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
int BTree<TLinklist>::RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index) //���ݻ�ȡ��ǰ���ĸ߶�
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
int BTree<TLinklist>::GetBTreeHeight() //��ȡ����ǰ���ĸ߶�
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
	if(root != NULL)
	{
		ret = Length;
	} 
	return ret;
}

template <class TLinklist>
int BTree<TLinklist>::RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode) //���ݲ����ӽڵ�Ķ� 
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
int BTree<TLinklist>::GetBTreeDegree(void) //��ȡ��ǰ���Ķ�
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
void BTree<TLinklist>::RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank) //���ݴ�ӡ�ӽڵ�
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
void BTree<TLinklist>::ShowBTree(void) //��ӡ��������Ԫ��  //O(n)
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
int BTree<TLinklist>::GetBTreeSerch(TLinklist Des)   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·��
{
	int ret = 0;
	
	return ret;
}

template <class TLinklist>
void BTree<TLinklist>::RecursivePre_Traversal(TreeNode<TLinklist>* ChiNode)
{
	if(ChiNode != NULL)
	{
		printf("%c ", ChiNode->data);
		RecursivePre_Traversal(ChiNode->bLeft);
		RecursivePre_Traversal(ChiNode->bRight);
	}
}
template <class TLinklist>
void BTree<TLinklist>::Pre_Traversal(void)
{
	if(root != NULL)
	{
		printf("\n");
		printf("%c ", root->data);
		RecursivePre_Traversal(root->bLeft);
		RecursivePre_Traversal(root->bRight);
		printf("\n");
	}
}

template <class TLinklist>
void BTree<TLinklist>::RecursiveMid_Traversal(TreeNode<TLinklist>* ChiNode)
{
	if(ChiNode != NULL)
	{
		RecursiveMid_Traversal(ChiNode->bLeft);
		printf("%c ", ChiNode->data);
		RecursiveMid_Traversal(ChiNode->bRight);
	}
}
template <class TLinklist>
void BTree<TLinklist>::Mid_Traversal(void)
{
	if(root != NULL)
	{
		printf("\n");
		RecursiveMid_Traversal(root->bLeft);
		printf("%c ", root->data);
		RecursiveMid_Traversal(root->bRight);
		printf("\n");
	} 
}

template <class TLinklist>
void BTree<TLinklist>::RecursivePost_Traversal(TreeNode<TLinklist>* ChiNode)
{
	if(ChiNode != NULL)
	{
		RecursivePost_Traversal(ChiNode->bLeft);
		RecursivePost_Traversal(ChiNode->bRight);
		printf("%c ", ChiNode->data);
	}
}
template <class TLinklist>
void BTree<TLinklist>::Post_Traversal(void)
{
	if(root != NULL)
	{
		printf("\n");
		RecursivePost_Traversal(root->bLeft);
		RecursivePost_Traversal(root->bRight);
		printf("%c ", root->data);
		printf("\n");
	} 
}

template <class TLinklist> 
void BTree<TLinklist>::Thread1_Tree(TreeNode<TLinklist>* Node) //ʹ�ÿյ���ָ��������������
{
	if(Node != NULL)
	{
		if(position != NULL)
		{
			position->bLeft = Node;
			position = NULL;
		}
		if(Node->bLeft == NULL)
		{
			position = Node;
		}
		Thread1_Tree(Node->bLeft);
		Thread1_Tree(Node->bRight);
	}
}

template <class TLinklist>
void BTree<TLinklist>::RecursivePost_ShowThread2(TreeNode<TLinklist>* Node)
{
	if((Node != NULL) && (SL != NULL))
	{
		SL->AddSeqlist((TLinklist *)Node, SL->GetSeqlistLength());
		RecursivePost_ShowThread2(Node->bLeft);
		RecursivePost_ShowThread2(Node->bRight);
	}
}

template <class TLinklist>
void BTree<TLinklist>::Thread2_Tree(void) //ʹ������������������
{
	if(root != NULL)
	{
		SL = new Seqlist<TLinklist>(Length);
		if(SL != NULL)
		{
			RecursivePost_ShowThread2(root);
		}
	}
}

template <class TLinklist>
void BTree<TLinklist>::ShowThread2_Tree(void) //չʾʹ������������������
{
	if(SL != NULL)
	{
		printf("\n");
		for(int tindex=0; tindex < SL->GetSeqlistLength(); tindex++)
		{
			TreeNode<TLinklist>* tmp = (TreeNode<TLinklist>*)(SL->GetSeqlist(tindex));
			if(tmp != NULL)
			{
				printf("%c ", tmp->data);
			}
		}
		printf("\n");
	}
} 

#endif //_BTREE_CPP_
