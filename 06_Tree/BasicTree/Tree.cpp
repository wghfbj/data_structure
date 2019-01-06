#ifndef _TREE_CPP_
#define _TREE_CPP_

#include "Tree.h"
#include "Linklist.cpp"


//=============Tree
template <class TLinklist>
Tree<TLinklist>::Tree():LinkNode<TLinklist>::LinkNode(0)  //创建树 //O(1)
{

}

template <class TLinklist>
Tree<TLinklist>::~Tree()  //销毁树  //O(1)
{

}

template <class TLinklist>
int Tree<TLinklist>::ClearTree()  //清空树 //O(1)
{

	return TRUE;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::DeleteTree(unsigned int pPos) //删除树中的元素 //O(n)
{
	TLinklist ret = FALSE;

	return ret;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::InsertTree(TLinklist *data, unsigned int pPos) //在树中的某个位置添加元素  //O(n)
{
	TLinklist ret = FALSE;
	return ret;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::GetTree(unsigned int pPos) //获取树中某个位置的元素 //O(n)
{
	TLinklist ret = FALSE;
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeHeight() //获取树当前树的高度
{

}

template <class TLinklist>
TLinklist Tree<TLinklist>::GetRootTree(void) //获取树中根节点
{
	TLinklist ret = 0;
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
