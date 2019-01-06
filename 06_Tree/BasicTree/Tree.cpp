#ifndef _Tree_CPP_
#define _Tree_CPP_

#include "Tree.h"



//=============LinkNode
template <class TTree>
LinkNode<TTree>::LinkNode(TTree data)
{
	this->data = data;
}


//=============Tree
template <class TTree>
Tree<TTree>::Tree():LinkNode<TTree>::LinkNode(0)  //������ //O(1)
{
	Length = 0;
	this->NextNode = NULL;
}

template <class TTree>
Tree<TTree>::~Tree()  //������  //O(1)
{
	LinkNode<TTree> *CurrentNode = this;
	LinkNode<TTree> *NextNode = this->NextNode;

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

template <class TTree>
int Tree<TTree>::ClearTree()  //����� //O(1)
{
	while(Length > 0)
	{
		DeleteTree(0);
	}
	Length = 0;
	this->NextNode = NULL;
	return TRUE;
}

template <class TTree>
TTree Tree<TTree>::DeleteTree(unsigned int index) //ɾ�����е�Ԫ�� //O(n)
{
	TTree ret = FALSE;
	
	if(index < Length)
	{
		LinkNode<TTree> *CurrentNode = this;
		for(int tindex=0; tindex<index; tindex++)
		{
			CurrentNode = CurrentNode->NextNode;
		}
		ret = CurrentNode->NextNode->data;
		LinkNode<TTree> *DeleteNode = CurrentNode->NextNode;
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

template <class TTree>
TTree Tree<TTree>::InsertTree(TTree *data, unsigned int index) //�����е�ĳ��λ�����Ԫ��  //O(n)
{
	TTree ret = FALSE;
	if(data != NULL)
	{
		LinkNode<TTree> *N = new LinkNode<TTree>(*data);
		if(N != NULL)
		{
			if(index < Length)
			{
				LinkNode<TTree> *CurrentNode = this;
				for(int tindex=1; tindex<index; tindex++)
				{
					CurrentNode = CurrentNode->NextNode;
				}
				N->NextNode = CurrentNode->NextNode; 
				CurrentNode->NextNode = N;
			}
			else
			{
				LinkNode<TTree> *CurrentNode = this;
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

template <class TTree>
TTree Tree<TTree>::GetTree(unsigned int index) //��ȡ����ĳ��λ�õ�Ԫ�� //O(n)
{
	TTree ret = FALSE;
	if(index < Length)
	{
		LinkNode<TTree> *CurrentNode = this->NextNode;
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

template <class TTree>
int Tree<TTree>::GetTreeHeight() //��ȡ����ǰ���ĸ߶�
{
	return Length;
}

template <class TTree>
TTree Tree<TTree>::GetRootTree(void) //��ȡ���и��ڵ�
{
	TTree ret = 0;
	return ret;
}

template <class TTree>
int Tree<TTree>::GetTreeCount(void) //��ȡ��ǰ���Ľڵ���
{
	int ret = 0;
	return ret;
}

template <class TTree>
int Tree<TTree>::GetTreeDegree(void) //��ȡ��ǰ���Ķ�
{
	int ret = 0;
	return ret;
}

template <class TTree>
void Tree<TTree>::ShowTree() //��ӡ��������Ԫ��  //O(n)
{
	printf("\n\n Show Tree ====>> \n\n");
	LinkNode<TTree> *CurrentNode = this;
	for(int tindex=0; tindex<Length; tindex++)
	{
		CurrentNode = CurrentNode->NextNode;
		printf(" Tree[%d] = %d \n", tindex, (int)CurrentNode->data);
	}
}

#endif //_Tree_CPP_
