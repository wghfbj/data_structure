#ifndef _TREE_CPP_
#define _TREE_CPP_

#include "Tree.h"
#include "Linklist.cpp"


//=============Tree
template <class TLinklist>
Tree<TLinklist>::Tree()  //������ //O(1)
{
	strL = new Linklist<TLinklist>();
}

template <class TLinklist>
Tree<TLinklist>::~Tree()  //������  //O(1)
{
	ClearTree();
	if(strL != NULL)
	{
		delete(strL);
		strL = NULL;
	}
}

template <class TLinklist>
int Tree<TLinklist>::ClearTree()  //����� //O(1)
{
	if(strL != NULL)
	{

	} 
	return TRUE;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::RecursiveDeleteChild(Linklist<TLinklist>* ChiList) //����ɾ���ӽڵ�
{
	TLinklist ret = FALSE;
	if(ChiList != NULL)
	{printf("\n line is %d \n", __LINE__);
		int tmpLength = ChiList->GetLinklistLength();
		for(int tindex=0; tindex<tmpLength; tindex++)
		{printf("\n line is %d tindex is %d \n", __LINE__, tindex);
			LinkNode<TLinklist>* tChild = ChiList->GetLinklist(tindex);
			printf("\n line is %d \n", __LINE__);
			RecursiveDeleteChild(tChild->Child);
			printf("\n line is %d \n", __LINE__);
			ChiList->DeleteLinklist(tindex);
			printf("\n line is %d \n", __LINE__);
		}
		delete(ChiList);
	}
	return ret;
}
 
template <class TLinklist>
TLinklist Tree<TLinklist>::DeleteTree(unsigned int pPos) //ɾ�����е�Ԫ�� //O(n)
{
	TLinklist ret = FALSE;
	if(strL != NULL)
	{printf("\n line is %d \n", __LINE__);
		LinkNode<TLinklist>* ParNode = GetTree(pPos);
		if(ParNode != NULL)
		{printf("\n line is %d \n", __LINE__);
			RecursiveDeleteChild(ParNode->Child);
			delete(ParNode);
			ParNode = NULL;
		}
	}
	return ret;
}

template <class TLinklist>
TLinklist Tree<TLinklist>::InsertTree(TLinklist *data, unsigned int pPos) //�����е�ĳ��λ�����Ԫ��  //O(n)
{
	TLinklist ret = FALSE;
	if((strL != NULL) && (data != NULL))
	{
		LinkNode<TLinklist>* Node = new LinkNode<TLinklist>(*data);
		Linklist<TLinklist>* ChList = new Linklist<TLinklist>();
		LinkNode<TLinklist>* ParNode = strL->GetLinklist(pPos);
		if((Node != NULL) && (ChList != NULL))
		{
			Node->Child = ChList;
			strL->AddLinklist(Node, strL->GetLinklistLength());
			if(ParNode != NULL)
			{
				ParNode->Child->AddLinklist(Node, ParNode->Child->GetLinklistLength());
			}
		}
		else
		{
			delete(Node);
			delete(ChList);
			Node = NULL;
			ChList = NULL;
			ret = FALSE; //Error
		}
	}

	return ret;
}

template <class TLinklist>
LinkNode<TLinklist>* Tree<TLinklist>::GetTree(unsigned int pPos) //��ȡ����ĳ��λ�õ�Ԫ�� //O(n)
{
	LinkNode<TLinklist>* ret = NULL;
	if(strL != NULL)
	{
		ret = strL->GetLinklist(pPos);
	}
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeHeight() //��ȡ����ǰ���ĸ߶�
{

}

template <class TLinklist>
LinkNode<TLinklist>* Tree<TLinklist>::GetRootTree(void) //��ȡ���и��ڵ�
{
	LinkNode<TLinklist>* ret = GetTree(0);
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeCount(void) //��ȡ��ǰ���Ľڵ���
{
	int ret = 0;
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeDegree(void) //��ȡ��ǰ���Ķ�
{
	int ret = 0;
	return ret;
}

template <class TLinklist>
void Tree<TLinklist>::ShowTree() //��ӡ��������Ԫ��  //O(n)
{
	
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeSerch(TLinklist Des)   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·��
{
	int ret = 0;
	
	return ret;
}

#endif //_TREE_CPP_
