#ifndef _TREE_CPP_
#define _TREE_CPP_

#include "Tree.h"
#include "Linklist.cpp"


//=============Tree
template <class TLinklist>
Tree<TLinklist>::Tree()  //创建树 //O(1)
{
	strL = new Linklist<TLinklist>();
}

template <class TLinklist>
Tree<TLinklist>::~Tree()  //销毁树  //O(1)
{
	ClearTree();
	if(strL != NULL)
	{
		delete(strL);
		strL = NULL;
	}
}

template <class TLinklist>
int Tree<TLinklist>::ClearTree()  //清空树 //O(1)
{
	if(strL != NULL)
	{

	} 
	return TRUE;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::RecursiveDeleteChild(Linklist<TLinklist>* ChiList) //回溯删除子节点
{
	TLinklist ret = FALSE;
	if(ChiList != NULL)
	{
		int tmpLength = ChiList->GetLinklistLength();
		for(int tindex=0; tindex<tmpLength; tindex++)
		{
			int tChildIndex = 0;
			LinkNode<TLinklist>* tChild = ChiList->GetLinklist(tindex);
			tChildIndex = tChild->Index;
			RecursiveDeleteChild(tChild->Child);
			ChiList->DeleteLinklist(tindex);
			strL->DeleteLinklist(tChildIndex);
		}
		delete(ChiList);
		ChiList = NULL;
	}
	return ret;
}
 
template <class TLinklist>
TLinklist Tree<TLinklist>::DeleteTree(unsigned int pPos) //删除树中的元素 //O(n)
{
	TLinklist ret = FALSE;
	if(strL != NULL)
	{
		LinkNode<TLinklist>* DeleteNode = GetTree(pPos);
		if(DeleteNode != NULL)
		{
			LinkNode<TLinklist> *ParNode = DeleteNode->Parent;
			RecursiveDeleteChild(DeleteNode->Child);
			strL->DeleteLinklist(pPos);
			if(ParNode != NULL)
			{
				Linklist<TLinklist> *tChiList = ParNode->Child;
				if(tChiList != NULL)
				{
					tChiList->DeleteChild(DeleteNode);
				}
			}
			DeleteNode = NULL;
		}
	}
	return ret;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::InsertTree(TLinklist *data, unsigned int pPos) //在树中的某个位置添加元素  //O(n)
{
	TLinklist ret = FALSE;
	if((strL != NULL) && (data != NULL))
	{
		LinkNode<TLinklist>* Node = new LinkNode<TLinklist>(*data);
		Linklist<TLinklist>* ChList = new Linklist<TLinklist>();
		LinkNode<TLinklist>* ParNode = strL->GetLinklist(pPos);
		if((Node != NULL) && (ChList != NULL))
		{
			Node->Child = ChList;
			Node->Parent = ParNode;
			strL->AddLinklist(Node, strL->GetLinklistLength());
			Node->Index = strL->GetLinklistLength();
			if(ParNode != NULL)
			{
				ParNode->Child->AddLinklist(Node, ParNode->Child->GetLinklistLength());
			}
		}
		else
		{
			delete(Node);
			delete(ChList);
			Node = NULL;
			ChList = NULL;
			ret = FALSE; //Error
		}
	}

	return ret;
}

template <class TLinklist>
LinkNode<TLinklist>* Tree<TLinklist>::GetTree(unsigned int pPos) //获取树中某个位置的元素 //O(n)
{
	LinkNode<TLinklist>* ret = NULL;
	if(strL != NULL)
	{
		ret = strL->GetLinklist(pPos);
	}
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::RecursiveNodeHeight(LinkNode<TLinklist>* ChiNode, int index) //回溯获取当前树的高度
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
int Tree<TLinklist>::GetTreeHeight() //获取树当前树的高度
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeHeight(rootNode, 1);
		}
	} 
	return ret; 
}

template <class TLinklist>
LinkNode<TLinklist>* Tree<TLinklist>::GetRootTree(void) //获取树中根节点
{
	LinkNode<TLinklist>* ret = GetTree(0);
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeCount(void) //获取当前树的节点数
{
	int ret = 0;
	if(strL != NULL)
	{
		ret = strL->GetLinklistLength();
	} 
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::RecursiveNodeDegree(LinkNode<TLinklist>* ChiNode) //回溯查找子节点的度 
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
int Tree<TLinklist>::GetTreeDegree(void) //获取当前树的度
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeDegree(rootNode);
		}
	}
	return ret;
}

template <class TLinklist>
void Tree<TLinklist>::RecursiveShowChild(LinkNode<TLinklist>* ChiNode, unsigned int Blank) //回溯打印子节点
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
void Tree<TLinklist>::ShowTree() //打印树中所有元素  //O(n)
{
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			printf("\n");
			RecursiveShowChild(rootNode, 1);
			printf("\n");
		}
	} 
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeSerch(TLinklist Des)   //获取Des数据在组织链表中的位置并打印对应路径
{
	int ret = 0;
	
	return ret;
}

#endif //_TREE_CPP_
