#ifndef _STATICLIST_CPP_
#define _STATICLIST_CPP_

#include "Staticlist.h"

#define AVAILIABLE   -1

//=============StaticNode
template <class TStaticlist>
StaticNode<TStaticlist>::StaticNode(TStaticlist data)
{
	this->data = data;
}


//=============Staticlist
//Staticlist<TStaticlist>::Staticlist(int MaxLength):StaticNode<TStaticlist>::StaticNode(0)  //创建线性表 //O(1)
template <class TStaticlist>
Staticlist<TStaticlist>::Staticlist(int MaxLength)
{
	this->MaxLength = MaxLength;
	SN = new StaticNode<TStaticlist> *[MaxLength+1];
	for(int tindex=0; tindex<MaxLength+1; tindex++)
	{
		SN[tindex] = new StaticNode<TStaticlist>(0);
	}
	SN[0]->data = 0;
	SN[0]->NextNode = 0;
	for(int index=1; index<MaxLength+1; index++)
	{
		SN[index]->NextNode = AVAILIABLE;
	}
}

template <class TStaticlist>
Staticlist<TStaticlist>::~Staticlist()  //销毁线性表  //O(1)
{
	if(SN != NULL)
	{
		delete SN;
	}
	SN = NULL;
}

template <class TStaticlist>
int Staticlist<TStaticlist>::ClearStaticlist()  //清空线性表 //O(1)
{
	SN[0]->data = 0;
	SN[0]->NextNode = 0;
	for(int index=1; index<MaxLength+1; index++)
	{
		SN[index]->NextNode = AVAILIABLE;
	}
	return TRUE;
}

template <class TStaticlist>
TStaticlist Staticlist<TStaticlist>::DeleteStaticlist(int index) //删除线性表中的元素 //O(n)
{
	TStaticlist ret = FALSE;
	int Length = SN[0]->data;
	if(index < Length)
	{
		int PreP = 0;
		int CurrP = 0;
		int NextP = 0;
		for(int tindex = 0; tindex < index; tindex++)
		{
			PreP = SN[PreP]->NextNode;
		}
		CurrP = SN[PreP]->NextNode;
		NextP = SN[CurrP]->NextNode;
		SN[PreP]->NextNode = NextP;
		SN[CurrP]->NextNode = AVAILIABLE;
		SN[0]->data--;
	}

	return ret;
}

template <class TStaticlist>
TStaticlist Staticlist<TStaticlist>::AddStaticlist(TStaticlist *data, unsigned int index) //在线性表中的某个位置添加元素  //O(2n)
{
	TStaticlist ret = FALSE;
	int Length = SN[0]->data;
	if(data != NULL)
	{
		int BlankP = 0;
		int CurrP = 0; 
		int NextP = 0;
		for(int tindex = 1; tindex < MaxLength; tindex++)
		{
			if(SN[tindex]->NextNode == AVAILIABLE)
			{
				BlankP = tindex;
				break;
			}
		}
		for(int tindex = 0; tindex < Length; tindex++)
		{
			CurrP = SN[CurrP]->NextNode;
		}
		if(index+1 < Length)
		{
			SN[BlankP]->data = (TStaticlist)*data;
			NextP = SN[CurrP]->NextNode;
			SN[CurrP]->NextNode = BlankP;
			SN[BlankP]->NextNode = NextP;
			SN[0]->data++;
			ret = (TStaticlist)*data;
		}
		else if((index+1 >= Length) && (index+1 < MaxLength))
		{
			SN[BlankP]->data = (TStaticlist)*data;
			SN[CurrP]->NextNode = BlankP;
			SN[BlankP]->NextNode = 0;
			SN[0]->data++;
			ret = (TStaticlist)*data;
		}
		
	}

	return ret;
}

template <class TStaticlist>

TStaticlist Staticlist<TStaticlist>::GetStaticlist(int index) //获取线性表中某个位置的元素 //O(n)
{
	TStaticlist ret = FALSE;
	int Length = SN[0]->data;
	if(index < Length)
	{
		int NextP = 0;
		for(int tindex = 0; tindex < index+1; tindex++)
		{
			NextP = SN[NextP]->NextNode;
			//printf("\n\n NextP = %d \n\n", NextP);
		}
		ret = SN[NextP]->data;
	}

	return ret;
}

template <class TStaticlist>
int Staticlist<TStaticlist>::GetStaticlistLength() //获取线性表当前的数据长度  //O(1)
{
	return SN[0]->data;
}

template <class TStaticlist>
int Staticlist<TStaticlist>::GetStaticlistMaxLength() //获取线性表最长的数据长度  //O(1)
{
	return MaxLength;
}

template <class TStaticlist>
void Staticlist<TStaticlist>::ShowStaticlist() //打印线性表中所有元素  //O(n)
{
	printf("\n\n Show Staticlist ====>> \n\n");
	int Position = SN[0]->NextNode;
	int Length = SN[0]->data;
	for(int tindex=0; tindex<Length; tindex++)
	{
		printf(" Staticlist[%d] = %d \n", tindex, (int)GetStaticlist(tindex));
	}
}

#endif //_STATICLIST_CPP_
