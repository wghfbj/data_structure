#ifndef _SEQLIST_CPP_
#define _SEQLIST_CPP_

#include "SeqlistForQueue.h"

template <class Tseqlist>
Seqlist<Tseqlist>::Seqlist(int Len)  //创建线性表 //O(1)
{
	Node = new Tseqlist[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
	Front = 0;
	Rear = 0;
}

template <class Tseqlist>
Seqlist<Tseqlist>::~Seqlist()  //销毁线性表  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::ClearSeqlist()  //清空线性表 //O(1)
{
	Length = 0;
	Front = 0;
	Rear = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::DeleteSeqlist(int index) //删除线性表中的元素 //O(1)
{
	Tseqlist ret = FALSE;
	if(Node != NULL)
	{
		if((index == 0))
		{
			ret = Node[Front];
			Node[Front] = 0;
			Length--;
			Front++;
			Front = Front%MaxLength;
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::AddSeqlist(Tseqlist *data, int index) //在线性表中的某个位置添加元素  //O(1)
{
	Tseqlist ret = FALSE;
	if((Node != NULL) && (data != NULL))
	{
		if((index >= Length) && (index < MaxLength))
		{
			Node[Length] = *data;
			Length++;
			Rear++;
			Rear = Rear%MaxLength;
			ret = TRUE;
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::GetSeqlist(int index) //获取线性表中某个位置的元素 //O(1)
{
	Tseqlist ret = 0;
	if(Node != NULL)
	{
		if(index == 0)
		{
			ret = (Tseqlist)Node[Front];
		}
	}
	return ret;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::GetSeqlistMaxLength() //获取线性表所能承受的最大长度 //O(1)
{
	return MaxLength;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::GetSeqlistLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class Tseqlist>
void Seqlist<Tseqlist>::ShowSeqlist() //打印线性表中所有元素  //O(n)
{
	if(Node != NULL)
	{
		printf("\n Seqlist === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (Tseqlist)Node[Start]);
		}
	}
}

#endif //_SEQLIST_CPP_
