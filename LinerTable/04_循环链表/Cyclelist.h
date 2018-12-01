#ifndef _CYCLELIST_H_
#define _CYCLELIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TCyclelist;


//=============LinkNode
template <class TCyclelist>
class LinkNode
{
public:
	LinkNode(TCyclelist data);
	TCyclelist data;
	LinkNode *NextNode;
};


//=============Cyclelist
template <class TCyclelist>
class Cyclelist : public LinkNode<TCyclelist>
{
public:
	Cyclelist(void);  //�������Ա� 
	~Cyclelist();   //�������Ա� 
	int ClearCyclelist();  //������Ա�
	TCyclelist DeleteCyclelist(int index); //ɾ�����Ա��е�Ԫ��
	TCyclelist AddCyclelist(TCyclelist *data, unsigned int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TCyclelist GetCyclelist(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetCyclelistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowCyclelist(void);

private:
	int Length;
};


#endif //_CYCLELIST_H_
