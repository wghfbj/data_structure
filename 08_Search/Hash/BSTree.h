#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//=============TreeNode
template <class TLinklist>
class TreeNode
{
public:
	TreeNode(TLinklist key, TLinklist *data);
	TLinklist key; 
	TLinklist *data;
	TreeNode *bRight;
	TreeNode *bLeft;
};

//=============BSTree
template <class TLinklist>
class BSTree
{
public:
	BSTree(void);  //创建树  完成 
	~BSTree();   //销毁树 
	int ClearBSTree();  //清空树
	TLinklist DeleteBSTree(TLinklist Des); //删除树中指定位置的节点 
	TLinklist InsertBSTree(TLinklist key, TLinklist *data); //在树中的指定位置处插入子节点   完成 
	TreeNode<TLinklist>* GetBSTree(TLinklist Des); //获取树中指定位置的元素 
	TreeNode<TLinklist>* GetRootBSTree(void); //获取树中根节点 
	int GetBSTreeHeight(void); //获取树当前树的高度
	int GetBSTreeCount(void); //获取当前树的节点数
	int GetBSTreeDegree(void); //获取当前树的度
	int GetBSTreeSerch(TLinklist Des);   //获取Des数据在组织链表中的位置并打印对应路径 
	void ShowBSTree(void);

private:
	TreeNode<TLinklist> *root;
	int Length;
	void RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank); //回溯打印子节点
	int RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode); //回溯查找子节点的度
	int RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index); //回溯获取当前树的高度
	int BSTreeCompare(TLinklist a, TLinklist b); //比较两个Node数据大小
	TLinklist RecursiveInsert(TreeNode<TLinklist> *RootNode, TreeNode<TLinklist> *ChiNode); //回溯获取当前树的高度
	TreeNode<TLinklist>* RecursiveGet(TreeNode<TLinklist>* ChiNode, TLinklist Des); //回溯获取树的节点 
};


#endif //_BSTREE_H_
