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
	Tree(void);  //������
	~Tree();   //������ 
	int ClearTree();  //�����
	TLinklist DeleteTree(unsigned int pPos); //ɾ������ָ��λ�õĽڵ� 
	TLinklist InsertTree(TLinklist *data, unsigned int pPos); //�����е�ָ��λ�ô������ӽڵ� 
	LinkNode<TLinklist>* GetTree(unsigned int pPos); //��ȡ����ָ��λ�õ�Ԫ�� 
	LinkNode<TLinklist>* GetRootTree(void); //��ȡ���и��ڵ� 
	int GetTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetTreeDegree(void); //��ȡ��ǰ���Ķ�
	int GetTreeSerch(TLinklist Des);   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·�� 
	void ShowTree(void);

private:
	Linklist<TLinklist> *strL;
	TLinklist RecursiveDeleteChild(Linklist<TLinklist>* ChiNode); //����ɾ���ӽڵ�
};


#endif //_TREE_H_
