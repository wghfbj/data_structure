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
Cyclelist<TCyclelist>::Cyclelist():LinkNode<TCyclelist>::LinkNode(0)  //�������Ա� //O(1)
{
	Length = 0;
	this->NextNode = NULL;
}

template <class TCyclelist>
Cyclelist<TCyclelist>::~Cyclelist()  //�������Ա�  //O(1)
{
}

template <class TCyclelist>
int Cyclelist<TCyclelist>::ClearCyclelist()  //������Ա� //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::DeleteCyclelist(unsigned int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TCyclelist ret = FALSE;
	
	LinkNode<TCyclelist> *CurrentNode = this;
	for(int tindex=1; tindex<index; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
	}
	ret = CurrentNode->NextNode->data;
	LinkNode<TCyclelist> *DeleteNode = CurrentNode->NextNode;
	CurrentNode->NextNode = DeleteNode->NextNode;
	
	if(index == 0)
	{
		CurrentNode = this; 
		for(int tindex=0; tindex<Length; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		CurrentNode->NextNode = this->NextNode;
	}
	
	if(DeleteNode != NULL)
	{
		delete(DeleteNode);
	}
	DeleteNode = NULL;
	Length--;

	return ret;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::AddCyclelist(TCyclelist *data, unsigned int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TCyclelist ret = FALSE;
	if(data != NULL)
	{
		LinkNode<TCyclelist> *N = new LinkNode<TCyclelist>(*data);
		if(N != NULL)
		{
			LinkNode<TCyclelist> *CurrentNode = this;
			if(index < Length)
			{
				
				for(int tindex=1; tindex<index; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				N->NextNode = CurrentNode->NextNode; 
				CurrentNode->NextNode = N;
			}
			else
			{
				for(int tindex=0; tindex<Length; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				CurrentNode->NextNode = N;
			}
			Length++;
			
			if(index == 0)
			{
				CurrentNode = this;
				for(int tindex=0; tindex<Length; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				CurrentNode->NextNode = this->NextNode; 
			}
			ret = TRUE;
		}
	}

	return ret;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::GetCyclelist(unsigned int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(n)
{
	TCyclelist ret = FALSE;

	LinkNode<TCyclelist> *CurrentNode = this;
	for(int tindex=0; tindex<index; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
	}
	if(CurrentNode != NULL)
	{
		ret = CurrentNode->data;
	} 
	
	return ret;
}

template <class TCyclelist>
int Cyclelist<TCyclelist>::GetCyclelistLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TCyclelist>
void Cyclelist<TCyclelist>::ShowCyclelist() //��ӡ���Ա�������Ԫ��  //O(n)
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
