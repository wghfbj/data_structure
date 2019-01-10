#ifndef _LINKLIST_CPP_
#define _LINKLIST_CPP_

#include "Linklist.h"



//=============LinkNode
template <class TLinklist>
LinkNode<TLinklist>::LinkNode(TLinklist data)
{
	this->data = data;
	this->NextNode = NULL;
	this->Parent = NULL;
	this->Child = NULL;
}

//=============Linklist
template <class TLinklist>
Linklist<TLinklist>::Linklist():LinkNode<TLinklist>::LinkNode(0)  //创建线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	this->Parent = NULL;
	this->Child = NULL;
}

template <class TLinklist>
Linklist<TLinklist>::~Linklist()  //销毁线性表  //O(1)
{
	LinkNode<TLinklist> *CurrentNode = this;
	LinkNode<TLinklist> *NextNode = this->NextNode;

	for(int tindex=0; tindex<Length; tindex++)
	{
		CurrentNode = NextNode;
		if(CurrentNode != NULL);
		{
			NextNode = CurrentNode->NextNode;
			delete(CurrentNode);
			CurrentNode = NULL;
		}
	}
	CurrentNode = NULL;
	NextNode = NULL;
	Length = 0;
}

template <class TLinklist>
int Linklist<TLinklist>::ClearLinklist()  //清空线性表 //O(1)
{
	while(Length > 0)
	{
		DeleteLinklist(0);
	}
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TLinklist>
TLinklist Linklist<TLinklist>::DeleteLinklist(unsigned int index) //删除线性表中的元素 //O(n)
{
	TLinklist ret = FALSE;
	
	if(index < Length)
	{
		LinkNode<TLinklist> *CurrentNode = this;
		for(int tindex=0; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		ret = CurrentNode->NextNode->data;
		LinkNode<TLinklist> *DeleteNode = CurrentNode->NextNode;
		CurrentNode->NextNode = DeleteNode->NextNode;
		if(DeleteNode != NULL)
		{
			delete(DeleteNode);
		}
		DeleteNode = NULL;
		Length--;
	}

	return ret;
}

template <class TLinklist>
TLinklist Linklist<TLinklist>::AddLinklist(LinkNode<TLinklist> *data, unsigned int index) //在线性表中的某个位置添加元素  //O(n)
{
	TLinklist ret = FALSE;
	if(data != NULL)
	{
		LinkNode<TLinklist> *N = data;
		if(index < Length)
		{
			LinkNode<TLinklist> *CurrentNode = this;
			for(int tindex=1; tindex<index; tindex++)
			{
				CurrentNode = CurrentNode->NextNode;
			}
			N->NextNode = CurrentNode->NextNode; 
			CurrentNode->NextNode = N;
		}
		else
		{
			LinkNode<TLinklist> *CurrentNode = this;
			for(int tindex=0; tindex<Length; tindex++)
			{
				CurrentNode = CurrentNode->NextNode;
			}
			CurrentNode->NextNode = N;
			N->NextNode = NULL;
		}
		Length++;
		ret = TRUE;
	}

	return ret;
}

template <class TLinklist>
LinkNode<TLinklist>* Linklist<TLinklist>::GetLinklist(unsigned int index) //获取线性表中某个位置的元素 //O(n)
{
	LinkNode<TLinklist>* ret = NULL;
	if(index < Length)
	{
		LinkNode<TLinklist> *CurrentNode = this->NextNode;
		for(int tindex=0; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		if(CurrentNode != NULL)
		{
			ret = CurrentNode;
		} 
	}
	
	return ret;
}

template <class TLinklist>
int Linklist<TLinklist>::GetLinklistLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TLinklist>
void Linklist<TLinklist>::ShowLinklist() //打印线性表中所有元素  //O(n)
{
	printf("\n\n Show Linklist ====>> \n\n");
	LinkNode<TLinklist> *CurrentNode = this;
	for(int tindex=0; tindex<Length; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
		printf(" Linklist[%d] = %d \n", tindex, (int)CurrentNode->data);
	}
}

#endif //_LINKLIST_CPP_
