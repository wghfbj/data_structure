#ifndef _DLINKLIST_CPP_
#define _DLINKLIST_CPP_

#include "DLinklist.h"



//=============LinkNode
template <class TDLinklist>
LinkNode<TDLinklist>::LinkNode(TDLinklist data)
{
	this->data = data;
}


//=============DLinklist
template <class TDLinklist>
DLinklist<TDLinklist>::DLinklist():LinkNode<TDLinklist>::LinkNode(0)  //创建线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
}

template <class TDLinklist>
DLinklist<TDLinklist>::~DLinklist()  //销毁线性表  //O(1)
{
	LinkNode<TDLinklist> *CurrentNode = this;
	LinkNode<TDLinklist> *NextNode = this->NextNode;

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

template <class TDLinklist>
int DLinklist<TDLinklist>::ClearDLinklist()  //清空线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TDLinklist>
TDLinklist DLinklist<TDLinklist>::DeleteDLinklist(unsigned int index) //删除线性表中的元素 //O(n)
{
	TDLinklist ret = FALSE;
	
	if(index < Length)
	{
		LinkNode<TDLinklist> *CurrentNode = this;
		for(int tindex=1; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		ret = CurrentNode->NextNode->data;
		LinkNode<TDLinklist> *DeleteNode = CurrentNode->NextNode;
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

template <class TDLinklist>
TDLinklist DLinklist<TDLinklist>::AddDLinklist(TDLinklist *data, unsigned int index) //在线性表中的某个位置添加元素  //O(n)
{
	TDLinklist ret = FALSE;
	if(data != NULL)
	{
		LinkNode<TDLinklist> *N = new LinkNode<TDLinklist>(*data);
		if(N != NULL)
		{
			if(index < Length)
			{
				LinkNode<TDLinklist> *CurrentNode = this;
				for(int tindex=1; tindex<index; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				N->NextNode = CurrentNode->NextNode; 
				CurrentNode->NextNode = N;
			}
			else
			{
				LinkNode<TDLinklist> *CurrentNode = this;
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
	}

	return ret;
}

template <class TDLinklist>
TDLinklist DLinklist<TDLinklist>::GetDLinklist(unsigned int index) //获取线性表中某个位置的元素 //O(n)
{
	TDLinklist ret = FALSE;
	if(index < Length)
	{
		LinkNode<TDLinklist> *CurrentNode = this;
		for(int tindex=0; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		if(CurrentNode != NULL)
		{
			ret = CurrentNode->data;
		} 
	}
	
	return ret;
}

template <class TDLinklist>
int DLinklist<TDLinklist>::GetDLinklistLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TDLinklist>
void DLinklist<TDLinklist>::ShowDLinklist() //打印线性表中所有元素  //O(n)
{
	printf("\n\n Show DLinklist ====>> \n\n");
	LinkNode<TDLinklist> *CurrentNode = this;
	for(int tindex=0; tindex<Length; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
		printf(" DLinklist[%d] = %d \n", tindex, (int)CurrentNode->data);
	}
}

#endif //_DLINKLIST_CPP_
