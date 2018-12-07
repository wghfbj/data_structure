#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include "Seqlist.h"

template <class Tseqlist>
class SeqStack
{
public:
	SeqStack(int Length);  //����ջ
	~SeqStack(void);  //����ջ
	
	bool Clear_SeqStack(void); //���ջ
	bool Push_SeqStack(Tseqlist *data); //ѹ���ݽ�ջ
	Tseqlist Pop_SeqStack(void);    //����ջ������
	Tseqlist GetTop_SeqStack(void);   //��ȡջ������
	int GetLength_SeqStack(void);   //��ȡջ�ĳ���
	int GetMaxLength_SeqStack(void);   //��ȡջ�ܱ������󳤶�

private:
	Seqlist<Tseqlist> *S;
};




#endif  //_SEQSTACK_H
