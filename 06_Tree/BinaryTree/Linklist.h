#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

template <class TLinklist>
class Linklist;
//typedef int TLinklist;


//=============LinkNode
template <class TLinklist>
class LinkNode
{
public:
	LinkNode(TLinklist data);
	TLinklist data;
	int Index;
	LinkNode *NextNode;
	LinkNode *Parent;
	Linklist<TLinklist> *Child;
};


//=============Linklist
template <class TLinklist>
class Linklist : public LinkNode<TLinklist>
{
public:
	Linklist(void);  //�������Ա� 
	~Linklist();   //�������Ա� 
	int ClearLinklist();  //������Ա�
	TLinklist DeleteLinklist(unsigned int index); //ɾ�����Ա��е�Ԫ��
	TLinklist AddLinklist(LinkNode<TLinklist> *data, unsigned int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	LinkNode<TLinklist>* GetLinklist(unsigned int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetLinklistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowLinklist(void);
	TLinklist DeleteChild(LinkNode<TLinklist> *Node);

private:
	int Length;
};


#endif //_LINKLIST_H_
