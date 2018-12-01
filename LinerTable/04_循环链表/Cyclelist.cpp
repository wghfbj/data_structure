#ifndef _CYCLELIST_CPP_
#define _CYCLELIST_CPP_

#include "Cyclelist.h"



//=============LinkNode
template <class TCyclelist>
LinkNode<TCyclelist>::LinkNode(TCyclelist data)
{
	this->data = data;
}


//=============Cyclelist
template <class TCyclelist>
Cyclelist<TCyclelist>::Cyclelist():LinkNode<TCyclelist>::LinkNode(0)  //创建线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
}

template <class TCyclelist>
Cyclelist<TCyclelist>::~Cyclelist()  //销毁线性表  //O(1)
{
}

template <class TCyclelist>
int Cyclelist<TCyclelist>::ClearCyclelist()  //清空线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::DeleteCyclelist(int index) //删除线性表中的元素 //O(n)
{
	TCyclelist ret = FALSE;
	
	if(index < Length)
	{
		LinkNode<TCyclelist> *CurrentNode = this;
		for(int tindex=1; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		ret = CurrentNode->NextNode->data;
		LinkNode<TCyclelist> *DeleteNode = CurrentNode->NextNode;
		CurrentNode->NextNode = DeleteNode->NextNode;
		if(CurrentNode != NULL)
		{
			delete(DeleteNode);
		}
		DeleteNode = NULL;
		Length--;
	}

	return ret;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::AddCyclelist(TCyclelist *data, unsigned int index) //在线性表中的某个位置添加元素  //O(n)
{
	TCyclelist ret = FALSE;
	if(data != NULL)
	{
		LinkNode<TCyclelist> *N = new LinkNode<TCyclelist>(*data);
		if(N != NULL)
		{
			if(index < Length)
			{
				LinkNode<TCyclelist> *CurrentNode = this;
				for(int tindex=1; tindex<index; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				N->NextNode = CurrentNode->NextNode; 
				CurrentNode->NextNode = N;
			}
			else
			{
				LinkNode<TCyclelist> *CurrentNode = this;
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

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::GetCyclelist(int index) //获取线性表中某个位置的元素 //O(n)
{
	TCyclelist ret = FALSE;
	if(index < Length)
	{
		LinkNode<TCyclelist> *CurrentNode = this;
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

template <class TCyclelist>
int Cyclelist<TCyclelist>::GetCyclelistLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TCyclelist>
void Cyclelist<TCyclelist>::ShowCyclelist() //打印线性表中所有元素  //O(n)
{
	printf("\n\n Show Cyclelist ====>> \n\n");
	LinkNode<TCyclelist> *CurrentNode = this;
	for(int tindex=0; tindex<Length; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
		printf(" Cyclelist[%d] = %d \n", tindex, (int)CurrentNode->data);
	}
}

#endif //_CYCLELIST_CPP_
