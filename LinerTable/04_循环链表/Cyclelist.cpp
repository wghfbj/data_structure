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
	this->Slider = NULL;
}

template <class TCyclelist>
Cyclelist<TCyclelist>::~Cyclelist()  //销毁线性表  //O(1)
{
	LinkNode<TCyclelist> *CurrentNode = this;
	LinkNode<TCyclelist> *NextNode = this->NextNode;

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

template <class TCyclelist>
int Cyclelist<TCyclelist>::ClearCyclelist()  //清空线性表 //O(1)
{
	Length = 0;
	this->NextNode = NULL;
	Slider = NULL;
	return TRUE;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::DeleteCyclelist(unsigned int index) //删除线性表中的元素 //O(n)
{
	TCyclelist ret = FALSE;
	
	LinkNode<TCyclelist> *CurrentNode = this;
	for(int tindex=0; tindex<index; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
	}
	LinkNode<TCyclelist> *DeleteNode = CurrentNode->NextNode;
	ret = DeleteNode->data;
	CurrentNode->NextNode = DeleteNode->NextNode;
	
	if(index == 0)
	{
		CurrentNode = this; 
		for(int tindex=1; tindex<Length; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		CurrentNode->NextNode = DeleteNode->NextNode;
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
	
	if(Length == 0)
	{
		Slider = NULL;
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
			if(Length == 0)
			{
				Slider = N; 
			} 
			Length++;

			CurrentNode = this;
			for(int tindex=0; tindex<Length; tindex++)
			{
				CurrentNode = CurrentNode->NextNode;
			}
			CurrentNode->NextNode = this->NextNode; 

			ret = TRUE;
		}
	}

	return ret;
}

template <class TCyclelist>
TCyclelist Cyclelist<TCyclelist>::GetCyclelist(unsigned int index) //获取线性表中某个位置的元素 //O(n)
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
		printf(" Cyclelist[%d] = %d \n", tindex, CurrentNode->data);
	}
}


//游标新增方法
template <class TCyclelist>
LinkNode<TCyclelist> *Cyclelist<TCyclelist>::GetSlider_Currnt(void)
{
	if(Slider != NULL)
	{
		return Slider;
	}
}

template <class TCyclelist>
LinkNode<TCyclelist> *Cyclelist<TCyclelist>::SetSlider_Next(void)
{
	LinkNode<TCyclelist> *ret = NULL;
	if(Slider != NULL)
	{
		Slider = Slider->NextNode;
		ret = Slider; 
	}

	return ret;
}

template <class TCyclelist>
bool Cyclelist<TCyclelist>::SetSlider_Reset(void)
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

template <class TCyclelist>
LinkNode<TCyclelist> *Cyclelist<TCyclelist>::DeleteNode(LinkNode<TCyclelist>* data)
{
	LinkNode<TCyclelist> *ret = NULL;
	
	if(data != NULL)
	{
		unsigned int tindex = 0;
		LinkNode<TCyclelist> *CurrentNode = this->NextNode;
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
			DeleteCyclelist(tindex);
		}
	}
	
	return ret;
}

#endif //_CYCLELIST_CPP_
