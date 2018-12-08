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
	this->PreNode = NULL;
	this->Slider = NULL; 
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
	while(Length > 0)
	{
		DeleteDLinklist(0);
	}
	Length = 0;
	this->NextNode = NULL;
	this->PreNode = NULL;
	this->Slider = NULL;
	return TRUE;
}

template <class TDLinklist>
TDLinklist DLinklist<TDLinklist>::DeleteDLinklist(unsigned int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TDLinklist ret = FALSE;
	
	if(index < Length)
	{
		LinkNode<TDLinklist> *CurrentNode = this;
		LinkNode<TDLinklist> *NextNode = this;
		for(int tindex=0; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		ret = CurrentNode->NextNode->data;
		LinkNode<TDLinklist> *DeleteNode = CurrentNode->NextNode;
		NextNode = DeleteNode->NextNode;
		CurrentNode->NextNode = NextNode;
		if(NextNode != NULL)
		{
			NextNode->PreNode = CurrentNode;
			if(index == 0)
			{
				NextNode->PreNode = NULL;
			}
		}
		
		if(Slider == DeleteNode)
		{
			Slider = DeleteNode->NextNode;
		}

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
				LinkNode<TDLinklist> *NextNode = this;
				for(int tindex=1; tindex<index; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				NextNode = CurrentNode->NextNode;
				N->NextNode = NextNode; 
				CurrentNode->NextNode = N;
				NextNode->PreNode = N;
				N->PreNode = CurrentNode;
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
				if(Length == 0)
				{
					N->PreNode = NULL;
					Slider = N;
				}
				else
				{
					N->PreNode = CurrentNode;
				}
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


//�α�������������
template <class TDLinklist>
LinkNode<TDLinklist> *DLinklist<TDLinklist>::GetSlider_Currnt(void)   //��ȡ��ǰ�α�ڵ�  //O(1)
{
	if(Slider != NULL)
	{
		return Slider;
	}
}

template <class TDLinklist>
LinkNode<TDLinklist> *DLinklist<TDLinklist>::SetSlider_Next(void)  //����ǰ�α�ڵ�ָ����һ���ڵ�  //O(1)
{
	LinkNode<TDLinklist> *ret = NULL;
	if(Slider != NULL)
	{
		Slider = Slider->NextNode;
		ret = Slider; 
	}

	return ret;
}

template <class TDLinklist>
LinkNode<TDLinklist> *DLinklist<TDLinklist>::SetSlider_Pre(void)  //����ǰ�α�ڵ�ָ����һ���ڵ�  //O(1)
{
	LinkNode<TDLinklist> *ret = NULL;
	if(Slider != NULL)
	{
		Slider = Slider->PreNode;
		ret = Slider;
	}

	return ret;
}

template <class TDLinklist>
bool DLinklist<TDLinklist>::SetSlider_Reset(void)  //��λ�α�ڵ� 
{
	bool ret = FALSE;
	if(Length != 0)
	{
		Slider = this->Next;
		ret = TRUE;
	}
	else
	{
		Slider = NULL;
	}
	
	return ret;
}

template <class TDLinklist>
LinkNode<TDLinklist> *DLinklist<TDLinklist>::DeleteNode(LinkNode<TDLinklist>* data)  //���ݽڵ�ɾ�������еĽڵ�  //O(3n)
{
	LinkNode<TDLinklist> *ret = NULL;
	
	if(data != NULL)
	{
		unsigned int tindex = 0;
		LinkNode<TDLinklist> *CurrentNode = this->NextNode;
		for(tindex=0; tindex<Length; tindex++)
		{
			if(data == CurrentNode)
			{
				ret = CurrentNode->NextNode;
				break;
			}
			CurrentNode = CurrentNode->NextNode;
		}
		
		
		if(CurrentNode != NULL)
		{
			DeleteDLinklist(tindex);
		}
	}
	
	return ret;
} 

#endif //_DLINKLIST_CPP_
