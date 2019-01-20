#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int Tseqlist;

template <class Tseqlist>
class Seqlist
{
public:
	Seqlist(int Len);  //�������Ա� 
	~Seqlist();   //�������Ա� 
	int ClearSeqlist();  //������Ա�
	Tseqlist DeleteSeqlist(int index); //ɾ�����Ա��е�Ԫ��
	Tseqlist AddSeqlist(Tseqlist *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	Tseqlist* GetSeqlist(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetSeqlistMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetSeqlistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowSeqlist(void);

private:
	int Length;
	int MaxLength;
	Tseqlist **Node;
};


#endif //_SEQLIST_H_
