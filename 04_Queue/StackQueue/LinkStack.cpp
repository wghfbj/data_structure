#include "LinkStack.h"
#include "Linklist.cpp"

template <class TLinklist>
LinkStack<TLinklist>::LinkStack(void)  //创建栈 //O(1) 
{
	S = new Linklist<TLinklist>();
}

template <class TLinklist>
LinkStack<TLinklist>::~LinkStack(void) //销毁栈  //O(1) 
{
	if(S != NULL)
	{
		delete(S);
	}
}

template <class TLinklist>
bool LinkStack<TLinklist>::Clear_LinkStack(void) //清空栈   //O(1) 
{
	return S->ClearLinklist();
}

template <class TLinklist>
bool LinkStack<TLinklist>::Push_LinkStack(TLinklist *data) //压数据进栈   //O(1) 
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
TLinklist LinkStack<TLinklist>::Pop_LinkStack(void) //弹出栈顶数据   //O(1) 
{
	TLinklist ret = FALSE;
	if((S != NULL) && (S->GetLinklistLength() > 0))
	{
		ret = S->DeleteLinklist(0);
	}

	return ret;
}

template <class TLinklist>
TLinklist LinkStack<TLinklist>::GetTop_LinkStack(void) //获取栈顶数据  //O(1) 
{
	TLinklist ret = FALSE;
	if((S != NULL) && (S->GetLinklistLength() > 0))
	{
		ret = S->GetLinklist(0);
	}

	return ret;
}

template <class TLinklist>
int LinkStack<TLinklist>::GetLength_LinkStack(void)  //获取当前栈的长度  //O(1) 
{
	int ret = FALSE;
	
	if(S != NULL)
	{
		ret = S->GetLinklistLength();
	}

	return ret;
}


