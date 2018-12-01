#ifndef _STATICLIST_H_
#define _STATICLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TStaticlist;


//=============StaticNode
template <class TStaticlist>
class StaticNode
{
public:
	StaticNode(TStaticlist data);
	TStaticlist data;
	int NextNode;
};


//=============Staticlist
template <class TStaticlist>
class Staticlist
{
public:
	Staticlist(int MaxLength);  //�������Ա� 
	~Staticlist();   //�������Ա� 
	int ClearStaticlist();  //������Ա�
	TStaticlist DeleteStaticlist(int index); //ɾ�����Ա��е�Ԫ��
	TStaticlist AddStaticlist(TStaticlist *data, unsigned int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TStaticlist GetStaticlist(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetStaticlistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	int GetStaticlistMaxLength(void); //��ȡ���Ա��������ݳ���
	void ShowStaticlist(void);

private:
	int MaxLength;
	StaticNode<TStaticlist> **SN;
};


#endif //_STATICLIST_H_
