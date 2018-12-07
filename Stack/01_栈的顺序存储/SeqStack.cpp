#include "SeqStack.h"
#include "Seqlist.cpp"

template <class Tseqlist>
SeqStack<Tseqlist>::SeqStack(int Length)  //创建栈 //O(1)
{
	S = new Seqlist<Tseqlist>(Length);
}

template <class Tseqlist>
SeqStack<Tseqlist>::~SeqStack(void)  //销毁栈  //O(1) 
{
	if(S != NULL)
	{
		delete(S);
		S = NULL;
	}
}

template <class Tseqlist>
bool SeqStack<Tseqlist>::Clear_SeqStack(void) //清空栈  //O(1) 
{
	int ret = FALSE;
	
	if(S != NULL)
	{
		ret = S->ClearSeqlist();
	}
	return ret;
}

template <class Tseqlist>
bool SeqStack<Tseqlist>::Push_SeqStack(Tseqlist *data) //压数据进栈  //O(1)
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
Tseqlist SeqStack<Tseqlist>::Pop_SeqStack(void) //压数据进栈  //O(1)
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
Tseqlist SeqStack<Tseqlist>::GetTop_SeqStack(void)  //弹出栈顶数据   //O(1)
{
	Tseqlist ret = FALSE;
	if(S != NULL)
	{
		ret = (Tseqlist)S->GetSeqlist(S->GetSeqlistLength() - 1);
	}
	return ret;
}

template <class Tseqlist>
int SeqStack<Tseqlist>::GetLength_SeqStack(void)  //获取栈的长度 //O(1)
{
	if(S != NULL)
	{
		return S->GetSeqlistLength();
	}
	return 0;
}

template <class Tseqlist>
int SeqStack<Tseqlist>::GetMaxLength_SeqStack(void)  //获取栈能保存的最大长度  //O(1)
{
	if(S != NULL)
	{
		return S->GetSeqlistMaxLength();
	}
	return 0;
}
