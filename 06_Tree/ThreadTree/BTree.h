#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>
#include "Seqlist.h"

using namespace std;

#define TRUE 1
#define FALSE 0

#define B_RIGHT 0x1
#define B_LEFT  0x0

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
	BTree(void);  //������  ��� 
	~BTree();   //������ 
	int ClearBTree();  //�����
	TLinklist DeleteBTree(long pPos, unsigned int count); //ɾ������ָ��λ�õĽڵ� 
	TLinklist InsertBTree(TLinklist *data, long pPos, unsigned int count); //�����е�ָ��λ�ô������ӽڵ�   ��� 
	TreeNode<TLinklist>* GetBTree(long pPos, unsigned int count); //��ȡ����ָ��λ�õ�Ԫ�� 
	TreeNode<TLinklist>* GetRootBTree(void); //��ȡ���и��ڵ� 
	int GetBTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetBTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetBTreeDegree(void); //��ȡ��ǰ���Ķ�
	int GetBTreeSerch(TLinklist Des);   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·�� 
	void ShowBTree(void);
	
	//����
	void Pre_Traversal(void); //ǰ����� 
	void Mid_Traversal(void);  //������� 
	void Post_Traversal(void); //�������
	
	//������
	void Thread1_Tree(TreeNode<TLinklist>* ChiNode); //ʹ�ÿյ���ָ�������������� 
	void Thread2_Tree(void); //ʹ������������������
	void ShowThread2_Tree(void); //չʾʹ������������������

private:
	TreeNode<TLinklist> *root;
	int Length;
	void RecursiveShowChild(TreeNode<TLinklist>* ChiNode, unsigned int Blank); //���ݴ�ӡ�ӽڵ�
	int RecursiveNodeDegree(TreeNode<TLinklist>* ChiNode); //���ݲ����ӽڵ�Ķ�
	int RecursiveNodeHeight(TreeNode<TLinklist>* ChiNode, int index); //���ݻ�ȡ��ǰ���ĸ߶�
	//���ݱ���
	void RecursivePre_Traversal(TreeNode<TLinklist>* ChiNode);
	void RecursiveMid_Traversal(TreeNode<TLinklist>* ChiNode);
	void RecursivePost_Traversal(TreeNode<TLinklist>* ChiNode);
	//������
	TreeNode<TLinklist> *position;
	Seqlist<TLinklist> *SL;
	void RecursivePost_ShowThread2(TreeNode<TLinklist>* Node);
};


#endif //_BTREE_H_