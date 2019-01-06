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
	Tree(void);  //������
	~Tree();   //������ 
	int ClearTree();  //�����
	TTree DeleteTree(unsigned int index); //ɾ������ָ����Ԫ��
	TTree InsertTree(TTree *data, unsigned int index); //�����е�ĳ��λ�����Ԫ�� 
	TTree GetTree(unsigned int index); //��ȡ����ĳ��λ�õ�Ԫ��
	TTree GetRootTree(void); //��ȡ���и��ڵ� 
	int GetTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetTreeDegree(void); //��ȡ��ǰ���Ķ� 
	void ShowTree(void);

private:
	int Length;
};


#endif //_TREE_H_
