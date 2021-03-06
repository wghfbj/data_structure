#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>
#include "Linklist.h"


//=============Tree
template <class TLinklist>
class Tree
{
public:
	Tree(void);  //创建树
	~Tree();   //销毁树 
	int ClearTree();  //清空树
	TLinklist DeleteTree(unsigned int pPos); //删除树中指定位置的节点 
	TLinklist InsertTree(TLinklist *data, unsigned int pPos); //在树中的指定位置处插入子节点 
	LinkNode<TLinklist>* GetTree(unsigned int pPos); //获取树中指定位置的元素 
	LinkNode<TLinklist>* GetRootTree(void); //获取树中根节点 
	int GetTreeHeight(void); //获取树当前树的高度
	int GetTreeCount(void); //获取当前树的节点数
	int GetTreeDegree(void); //获取当前树的度
	int GetTreeSerch(TLinklist Des);   //获取Des数据在组织链表中的位置并打印对应路径 
	void ShowTree(void);

private:
	Linklist<TLinklist> *strL;
	TLinklist RecursiveDeleteChild(Linklist<TLinklist>* ChiNode); //回溯删除子节点
	void RecursiveShowChild(LinkNode<TLinklist>* ChiNode, unsigned int Blank); //回溯打印子节点
	int RecursiveNodeDegree(LinkNode<TLinklist>* ChiNode); //回溯查找子节点的度
	int RecursiveNodeHeight(LinkNode<TLinklist>* ChiNode, int index); //回溯获取当前树的高度
};


#endif //_TREE_H_
