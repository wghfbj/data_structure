#ifndef _LINKLISTFORQUEUE_H_
#define _LINKLISTFORQUEUE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TLinklist;


//=============LinkNode
template <class TLinklist>
class LinkNode
{
public:
	LinkNode(TLinklist data);
	TLinklist data;
	LinkNode *NextNode;
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
	TLinklist AddLinklist(TLinklist *data, unsigned int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TLinklist GetLinklist(unsigned int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetLinklistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowLinklist(void);

private:
	int Length;
};


#endif //_LINKLISTFORQUEUE_H_
