#include "LinkStack.h"
#include "Linklist.cpp"

template <class TLinklist>
LinkStack<TLinklist>::LinkStack(void)  //����ջ //O(1) 
{
	S = new Linklist<TLinklist>();
}

template <class TLinklist>
LinkStack<TLinklist>::~LinkStack(void) //����ջ  //O(1) 
{
	if(S != NULL)
	{
		delete(S);
	}
}

template <class TLinklist>
bool LinkStack<TLinklist>::Clear_LinkStack(void) //���ջ   //O(1) 
{
	return S->ClearLinklist();
}

template <class TLinklist>
bool LinkStack<TLinklist>::Push_LinkStack(TLinklist *data) //ѹ���ݽ�ջ   //O(1) 
{
	bool ret = FALSE;
	if((data != NULL) && (S != NULL))
	{
		S->AddLinklist(data, 0);
		ret = TRUE;
	}

	return ret;
}

template <class TLinklist>
TLinklist LinkStack<TLinklist>::Pop_LinkStack(void) //����ջ������   //O(1) 
{
	TLinklist ret = FALSE;
	if((S != NULL) && (S->GetLinklistLength() > 0))
	{
		ret = S->DeleteLinklist(0);
	}

	return ret;
}

template <class TLinklist>
TLinklist LinkStack<TLinklist>::GetTop_LinkStack(void) //��ȡջ������  //O(1) 
{
	TLinklist ret = FALSE;
	if((S != NULL) && (S->GetLinklistLength() > 0))
	{
		ret = S->GetLinklist(0);
	}

	return ret;
}

template <class TLinklist>
int LinkStack<TLinklist>::GetLength_LinkStack(void)  //��ȡ��ǰջ�ĳ���  //O(1) 
{
	int ret = FALSE;
	
	if(S != NULL)
	{
		ret = S->GetLinklistLength();
	}

	return ret;
}


