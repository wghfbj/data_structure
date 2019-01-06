#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TTree;


//=============LinkNode
template <class TTree>
class LinkNode
{
public:
	LinkNode(TTree data);
	TTree data;
	LinkNode *NextNode;
};


//=============Tree
template <class TTree>
class Tree : public LinkNode<TTree>
{
public:
	Tree(void);  //创建树
	~Tree();   //销毁树 
	int ClearTree();  //清空树
	TTree DeleteTree(unsigned int index); //删除树中指定的元素
	TTree InsertTree(TTree *data, unsigned int index); //在树中的某个位置添加元素 
	TTree GetTree(unsigned int index); //获取树中某个位置的元素
	TTree GetRootTree(void); //获取树中根节点 
	int GetTreeHeight(void); //获取树当前树的高度
	int GetTreeCount(void); //获取当前树的节点数
	int GetTreeDegree(void); //获取当前树的度 
	void ShowTree(void);

private:
	int Length;
};


#endif //_TREE_H_
