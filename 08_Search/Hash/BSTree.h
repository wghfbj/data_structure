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
	BSTree(void);  //������  ��� 
	~BSTree();   //������ 
	int ClearBSTree();  //�����
	TLinklist DeleteBSTree(TLinklist Des); //ɾ������ָ��λ�õĽڵ� 
	TLinklist InsertBSTree(TLinklist key, TLinklist *data); //�����е�ָ��λ�ô������ӽڵ�   ��� 
	TreeNode<TLinklist>* GetBSTree(TLinklist Des); //��ȡ����ָ��λ�õ�Ԫ�� 
	TreeNode<TLinklist>* GetRootBSTree(void); //��ȡ���и��ڵ� 
	int GetBSTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetBSTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetBSTreeDegree(void); //��ȡ��ǰ���Ķ�
	int GetBSTreeSerch(TLinklist Des);   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·�� 
	void ShowBSTree(void);

private:
	TreeNode<TLinklist> *root;
	int Length;
	void RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank); //���ݴ�ӡ�ӽڵ�
	int RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode); //���ݲ����ӽڵ�Ķ�
	int RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index); //���ݻ�ȡ��ǰ���ĸ߶�
	int BSTreeCompare(TLinklist a, TLinklist b); //�Ƚ�����Node���ݴ�С
	TLinklist RecursiveInsert(TreeNode<TLinklist> *RootNode, TreeNode<TLinklist> *ChiNode); //���ݻ�ȡ��ǰ���ĸ߶�
	TreeNode<TLinklist>* RecursiveGet(TreeNode<TLinklist>* ChiNode, TLinklist Des); //���ݻ�ȡ���Ľڵ� 
};


#endif //_BSTREE_H_
