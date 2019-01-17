#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

#define B_RIGHT 1
#define B_LEFT  0

//=============TreeNode
template <class TLinklist>
class TreeNode
{
public:
	TreeNode(TLinklist data);
	TLinklist data;
	TreeNode *bRight;
	TreeNode *bLeft;
};

//=============BTree
template <class TLinklist>
class BTree
{
public:
	BTree(void);  //创建树
	~BTree();   //销毁树 
	int ClearBTree();  //清空树
	TLinklist DeleteBTree(unsigned int pPos); //删除树中指定位置的节点 
	TLinklist InsertBTree(TLinklist *data, long pPos, int count, bool flag); //在树中的指定位置处插入子节点 
	TreeNode<TLinklist>* GetBTree(long pPos, int count); //获取树中指定位置的元素 
	TreeNode<TLinklist>* GetRootBTree(void); //获取树中根节点 
	int GetBTreeHeight(void); //获取树当前树的高度
	int GetBTreeCount(void); //获取当前树的节点数
	int GetBTreeDegree(void); //获取当前树的度
	int GetBTreeSerch(TLinklist Des);   //获取Des数据在组织链表中的位置并打印对应路径 
	void ShowBTree(void);

private:
	TreeNode<TLinklist> *root;
	int Length;
	TLinklist RecursiveDeleteChild(Linklist<TLinklist>* ChiNode); //回溯删除子节点
	void RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank); //回溯打印子节点
	int RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode); //回溯查找子节点的度
	int RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index); //回溯获取当前树的高度
};


#endif //_BTREE_H_
