#ifndef _SEQLIST_CPP_
#define _SEQLIST_CPP_

#include "Seqlist.h"

template <class Tseqlist>
Seqlist<Tseqlist>::Seqlist(int Len)  //�������Ա� //O(1)
{
	Node = new Tseqlist[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class Tseqlist>
Seqlist<Tseqlist>::~Seqlist()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::ClearSeqlist()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::DeleteSeqlist(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	Tseqlist ret = FALSE;
	if(Node != NULL)
	{
		if((index >= 0) && (index <= Length))
		{
			ret = Node[index];
			for(int start = index; start<Length-1; start++)
			{
				Node[start] = Node[start+1];
			}
			Node[Length-1] = 0;
			Length--;
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::AddSeqlist(Tseqlist *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	Tseqlist ret = FALSE;
	if((Node != NULL) && (data != NULL))
	{
		if((index >= 0) && (index <= Length) && (Length < MaxLength))
		{
			for(int start = Length; start>index; start--)
			{
				Node[start] = Node[start-1];
			}
			Node[index] = *data;
			Length++;
			ret = TRUE;
		}
		else if((index >= Length) && (index < MaxLength))
		{
			Node[Length] = *data;
			Length++;
			ret = TRUE;
		}
	}
	return ret;
}

template <class Tseqlist>
Tseqlist Seqlist<Tseqlist>::GetSeqlist(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	Tseqlist ret = 0;
	if(Node != NULL)
	{
		ret = (Tseqlist)Node[index];
	}
	return ret;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::GetSeqlistMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class Tseqlist>
int Seqlist<Tseqlist>::GetSeqlistLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class Tseqlist>
void Seqlist<Tseqlist>::ShowSeqlist() //��ӡ���Ա�������Ԫ��  //O(n)
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
