#ifndef _BSTREE_CPP_
#define _BSTREE_CPP_

#include "BSTree.h"


//=============TreeNode
template <class TLinklist>
TreeNode<TLinklist>::TreeNode(TLinklist data)
{
	this->data = data;
	this->bRight = NULL;
	this->bLeft = NULL;
}

//=============BSTree
template <class TLinklist>
BSTree<TLinklist>::BSTree()  //������ //O(1)
{
	root = NULL;
	Length = 0;
}

template <class TLinklist>
BSTree<TLinklist>::~BSTree()  //������  //O(1)
{
	ClearBSTree();
	if(root != NULL)
	{
		delete(root);
		root = NULL;
	}
}

template <class TLinklist>
int BSTree<TLinklist>::ClearBSTree()  //����� //O(1)
{
	if(root != NULL)
	{

	}
	Length = 0;
	return TRUE;
}

template <class TLinklist>
TLinklist BSTree<TLinklist>::DeleteBSTree(TLinklist Des) //ɾ�����е�Ԫ��
{
	TLinklist ret = FALSE;
	if(root != NULL)
	{
		ret = TRUE;
	}
	return ret;
}

template <class TLinklist>
TLinklist BSTree<TLinklist>::RecursiveInsert(TreeNode<TLinklist> *RootNode, TreeNode<TLinklist> *ChiNode)
{
	TLinklist ret = FALSE;
	if((ChiNode != NULL) && (RootNode != NULL))
	{
		if(BSTreeCompare(RootNode->data, ChiNode->data) > 0)
		{
			if(RootNode->bLeft != NULL)
			{
				RecursiveInsert(RootNode->bLeft, ChiNode);
			}
			else
			{
				RootNode->bLeft = ChiNode;
				Length++;
				ret = TRUE;
			}
		}
		else if(BSTreeCompare(RootNode->data, ChiNode->data) < 0)
		{
			if(RootNode->bRight != NULL)
			{
				RecursiveInsert(RootNode->bRight, ChiNode);
			}
			else
			{
				RootNode->bRight = ChiNode;
				Length++;
				ret = TRUE;
			}
		}
		else if(BSTreeCompare(RootNode->data, ChiNode->data) == 0)
		{
			ret = FALSE;
		}
	}
	return ret;
}

template <class TLinklist>
TLinklist BSTree<TLinklist>::InsertBSTree(TLinklist *data) //�����е�ĳ��λ�����Ԫ��
{
	TLinklist ret = FALSE;
	TreeNode<TLinklist> *tNode = new TreeNode<TLinklist>(*data);
	if((data != NULL) && (tNode != NULL))
	{
		TreeNode<TLinklist> *CurrNode = root;

		if(CurrNode == NULL) //Add root node
		{
			root = tNode;
			Length++;
			ret = TRUE;
		}
		else
		{
			ret = RecursiveInsert(CurrNode, tNode);
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
TreeNode<TLinklist>* BSTree<TLinklist>::RecursiveGet(TreeNode<TLinklist>* ChiNode, TLinklist Des)
{
	TreeNode<TLinklist>* ret = NULL;
	if(ChiNode != NULL)
	{
		if(BSTreeCompare(ChiNode->data, Des) == 0)
		{
			ret = ChiNode;
		}
		else if(BSTreeCompare(ChiNode->data, Des) > 0)
		{
			if(ChiNode->bLeft != NULL)
			{
				RecursiveGet(ChiNode->bLeft, Des);
			}
		}
		else if(BSTreeCompare(ChiNode->data, Des) < 0)
		{
			if(ChiNode->bRight != NULL)
			{
				RecursiveGet(ChiNode->bRight, Des);
			}
		}
	}
	return ret;
}

template <class TLinklist>
TreeNode<TLinklist>* BSTree<TLinklist>::GetBSTree(TLinklist Des) //��ȡ����ĳ��λ�õ�Ԫ��
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		TreeNode<TLinklist> *CurrNode = root;
		ret = RecursiveGet(CurrNode, Des);
	}
	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index) //���ݻ�ȡ��ǰ���ĸ߶�
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
int BSTree<TLinklist>::GetBSTreeHeight() //��ȡ����ǰ���ĸ߶�
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
TreeNode<TLinklist>* BSTree<TLinklist>::GetRootBSTree(void) //��ȡ���и��ڵ�
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		ret = root;
	}
	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::GetBSTreeCount(void) //��ȡ��ǰ���Ľڵ���
{
	int ret = 0;
	if(root != NULL)
	{
		ret = Length;
	} 
	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode) //���ݲ����ӽڵ�Ķ�
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
int BSTree<TLinklist>::GetBSTreeDegree(void) //��ȡ��ǰ���Ķ�
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
void BSTree<TLinklist>::RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank) //���ݴ�ӡ�ӽڵ�
{
	for(unsigned int tindexx = 0; tindexx< Blank*4; tindexx++)
	{
		printf("-");
	}
	if(ChiNode != NULL)
	{
		printf("%d\n", ChiNode->data);
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
void BSTree<TLinklist>::ShowBSTree(void) //��ӡ��������Ԫ��  //O(n)
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
int BSTree<TLinklist>::GetBSTreeSerch(TLinklist Des)   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·��
{
	int ret = 0;

	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::BSTreeCompare(TLinklist a, TLinklist b) // ����ֵ>0 ��ʾa>b ����ֵС��0 ��ʾa<b ����ֵ=0 ��ʾa=b 
{
	int ret = 0;
	ret = a - b;
	return ret;
}

#endif //_BSTREE_CPP_
