#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>


//=============BTree
template <class TLinklist>
class BTree
{
public:
	BTree(void);  //������
	~BTree();   //������ 
	int ClearBTree();  //�����
	TLinklist DeleteBTree(unsigned int pPos); //ɾ������ָ��λ�õĽڵ� 
	TLinklist InsertBTree(TLinklist *data, unsigned int pPos); //�����е�ָ��λ�ô������ӽڵ� 
	LinkNode<TLinklist>* GetBTree(unsigned int pPos); //��ȡ����ָ��λ�õ�Ԫ�� 
	LinkNode<TLinklist>* GetRootBTree(void); //��ȡ���и��ڵ� 
	int GetBTreeHeight(void); //��ȡ����ǰ���ĸ߶�
	int GetBTreeCount(void); //��ȡ��ǰ���Ľڵ���
	int GetBTreeDegree(void); //��ȡ��ǰ���Ķ�
	int GetBTreeSerch(TLinklist Des);   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·�� 
	void ShowBTree(void);

private:
	Linklist<TLinklist> *strL;
	TLinklist RecursiveDeleteChild(Linklist<TLinklist>* ChiNode); //����ɾ���ӽڵ�
	void RecursiveShowChild(LinkNode<TLinklist>* ChiNode, unsigned int Blank); //���ݴ�ӡ�ӽڵ�
	int RecursiveNodeDegree(LinkNode<TLinklist>* ChiNode); //���ݲ����ӽڵ�Ķ�
	int RecursiveNodeHeight(LinkNode<TLinklist>* ChiNode, int index); //���ݻ�ȡ��ǰ���ĸ߶�
};


#endif //_BTREE_H_
