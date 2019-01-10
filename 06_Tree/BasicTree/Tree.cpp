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
	{printf("\n line is %d \n", __LINE__);
		int tmpLength = ChiList->GetLinklistLength();
		for(int tindex=0; tindex<tmpLength; tindex++)
		{printf("\n line is %d tindex is %d \n", __LINE__, tindex);
			LinkNode<TLinklist>* tChild = ChiList->GetLinklist(tindex);
			printf("\n line is %d \n", __LINE__);
			RecursiveDeleteChild(tChild->Child);
			printf("\n line is %d \n", __LINE__);
			ChiList->DeleteLinklist(tindex);
			printf("\n line is %d \n", __LINE__);
		}
		delete(ChiList);
	}
	return ret;
}
 
template <class TLinklist>
TLinklist Tree<TLinklist>::DeleteTree(unsigned int pPos) //删除树中的元素 //O(n)
{
	TLinklist ret = FALSE;
	if(strL != NULL)
	{printf("\n line is %d \n", __LINE__);
		LinkNode<TLinklist>* ParNode = GetTree(pPos);
		if(ParNode != NULL)
		{printf("\n line is %d \n", __LINE__);
			RecursiveDeleteChild(ParNode->Child);
			delete(ParNode);
			ParNode = NULL;
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
			strL->AddLinklist(Node, strL->GetLinklistLength());
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
int Tree<TLinklist>::GetTreeHeight() //获取树当前树的高度
{

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
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeDegree(void) //获取当前树的度
{
	int ret = 0;
	return ret;
}

template <class TLinklist>
void Tree<TLinklist>::ShowTree() //打印树中所有元素  //O(n)
{
	
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeSerch(TLinklist Des)   //获取Des数据在组织链表中的位置并打印对应路径
{
	int ret = 0;
	
	return ret;
}

#endif //_TREE_CPP_
