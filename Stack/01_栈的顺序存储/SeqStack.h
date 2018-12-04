#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include "Seqlist.h"

template <class Tseqlist>
class SeqStack
{
public:
	SeqStack(int Length);
	~SeqStack(void);
	
	bool Clear_SeqStack(void);
	bool Push_SeqStack(Tseqlist *data);
	Tseqlist Pop_SeqStack(void);
	Tseqlist GetTop_SeqStack(void);
	int GetLength_SeqStack(void);
	int GetMaxLength_SeqStack(void);

private:
	Seqlist<Tseqlist> *S;
};




#endif  //_SEQSTACK_H
