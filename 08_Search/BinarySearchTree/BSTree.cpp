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
BSTree<TLinklist>::BSTree()  //创建树 //O(1)
{
	root = NULL;
	Length = 0;
}

template <class TLinklist>
BSTree<TLinklist>::~BSTree()  //销毁树  //O(1)
{
	ClearBSTree();
	if(root != NULL)
	{
		delete(root);
		root = NULL;
	}
}

template <class TLinklist>
int BSTree<TLinklist>::ClearBSTree()  //清空树 //O(1)
{
	if(root != NULL)
	{

	}
	Length = 0;
	return TRUE;
}

template <class TLinklist>
TLinklist BSTree<TLinklist>::DeleteBSTree(TLinklist Des) //删除树中的元素
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
TLinklist BSTree<TLinklist>::InsertBSTree(TLinklist *data) //在树中的某个位置添加元素
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
TreeNode<TLinklist>* BSTree<TLinklist>::GetBSTree(TLinklist Des) //获取树中某个位置的元素
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
int BSTree<TLinklist>::RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index) //回溯获取当前树的高度
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
int BSTree<TLinklist>::GetBSTreeHeight() //获取树当前树的高度
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
TreeNode<TLinklist>* BSTree<TLinklist>::GetRootBSTree(void) //获取树中根节点
{
	TreeNode<TLinklist>* ret = NULL;
	if(root != NULL)
	{
		ret = root;
	}
	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::GetBSTreeCount(void) //获取当前树的节点数
{
	int ret = 0;
	if(root != NULL)
	{
		ret = Length;
	} 
	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode) //回溯查找子节点的度
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
int BSTree<TLinklist>::GetBSTreeDegree(void) //获取当前树的度
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
void BSTree<TLinklist>::RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank) //回溯打印子节点
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
void BSTree<TLinklist>::ShowBSTree(void) //打印树中所有元素  //O(n)
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
int BSTree<TLinklist>::GetBSTreeSerch(TLinklist Des)   //获取Des数据在组织链表中的位置并打印对应路径
{
	int ret = 0;

	return ret;
}

template <class TLinklist>
int BSTree<TLinklist>::BSTreeCompare(TLinklist a, TLinklist b) // 返回值>0 表示a>b 返回值小于0 表示a<b 返回值=0 表示a=b 
{
	int ret = 0;
	ret = a - b;
	return ret;
}

#endif //_BSTREE_CPP_
