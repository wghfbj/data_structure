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
DLinklist<TDLinklist>::DLinklist():LinkNode<TDLinklist>::LinkNode(0)  //�������Ա� //O(1)
{
	Length = 0;
	this->NextNode = NULL;
}

template <class TDLinklist>
DLinklist<TDLinklist>::~DLinklist()  //�������Ա�  //O(1)
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
int DLinklist<TDLinklist>::ClearDLinklist()  //������Ա� //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TDLinklist>
TDLinklist DLinklist<TDLinklist>::DeleteDLinklist(unsigned int index) //ɾ�����Ա��е�Ԫ�� //O(n)
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
TDLinklist DLinklist<TDLinklist>::AddDLinklist(TDLinklist *data, unsigned int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
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
TDLinklist DLinklist<TDLinklist>::GetDLinklist(unsigned int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(n)
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
int DLinklist<TDLinklist>::GetDLinklistLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TDLinklist>
void DLinklist<TDLinklist>::ShowDLinklist() //��ӡ���Ա�������Ԫ��  //O(n)
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
