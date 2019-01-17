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
	BTree(void);  //������
	~BTree();   //������ 
	int ClearBTree();  //�����
	TLinklist DeleteBTree(unsigned int pPos); //ɾ������ָ��λ�õĽڵ� 
	TLinklist InsertBTree(TLinklist *data, long pPos, int count, bool flag); //�����е�ָ��λ�ô������ӽڵ� 
	TreeNode<TLinklist>* GetBTree(long pPos, int count); //��ȡ����ָ��λ�õ�Ԫ�� 
	TreeNode<TLinklist>* GetRootBTree(void); //��ȡ���и��ڵ� 
	int GetBTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetBTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetBTreeDegree(void); //��ȡ��ǰ���Ķ�
	int GetBTreeSerch(TLinklist Des);   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·�� 
	void ShowBTree(void);

private:
	TreeNode<TLinklist> *root;
	int Length;
	TLinklist RecursiveDeleteChild(Linklist<TLinklist>* ChiNode); //����ɾ���ӽڵ�
	void RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank); //���ݴ�ӡ�ӽڵ�
	int RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode); //���ݲ����ӽڵ�Ķ�
	int RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index); //���ݻ�ȡ��ǰ���ĸ߶�
};


#endif //_BTREE_H_
