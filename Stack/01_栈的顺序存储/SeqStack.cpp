#include "SeqStack.h"

#include "Seqlist.cpp"

template <class Tseqlist>
SeqStack<Tseqlist>::SeqStack(int Length)
{
	S = new Seqlist<Tseqlist>(Length);
}

template <class Tseqlist>
SeqStack<Tseqlist>::~SeqStack(void)
{
	if(S != NULL)
	{
		delete(S);
		S = NULL;
	}
}

template <class Tseqlist>
bool SeqStack<Tseqlist>::Clear_SeqStack(void)
{
	int ret = FALSE;
	
	if(S != NULL)
	{
		ret = S->ClearSeqlist();
	}
	return ret;
}

template <class Tseqlist>
bool SeqStack<Tseqlist>::Push_SeqStack(Tseqlist *data)
{
	bool ret = FALSE;
	if(S != NULL)
	{
		if(S->GetSeqlistLength() < S->GetSeqlistMaxLength())
		{
			S->AddSeqlist(data, S->GetSeqlistLength());
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist SeqStack<Tseqlist>::Pop_SeqStack(void)
{
	Tseqlist ret = FALSE;
	if(S != NULL)
	{
		if(S->GetSeqlistLength() > 0)
		{
			ret = S->DeleteSeqlist(S->GetSeqlistLength() - 1);
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist SeqStack<Tseqlist>::GetTop_SeqStack(void)
{
	Tseqlist ret = FALSE;
	if(S != NULL)
	{
		ret = (Tseqlist)S->GetSeqlist(S->GetSeqlistLength() - 1);
	}
	return ret;
}

template <class Tseqlist>
int SeqStack<Tseqlist>::GetLength_SeqStack(void)
{
	if(S != NULL)
	{
		return S->GetSeqlistLength();
	}
	return 0;
}

template <class Tseqlist>
int SeqStack<Tseqlist>::GetMaxLength_SeqStack(void)
{
	if(S != NULL)
	{
		return S->GetSeqlistMaxLength();
	}
	return 0;
}
