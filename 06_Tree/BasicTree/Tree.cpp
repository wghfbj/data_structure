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
	{
		int tmpLength = ChiList->GetLinklistLength();
		for(int tindex=0; tindex<tmpLength; tindex++)
		{
			int tChildIndex = 0;
			LinkNode<TLinklist>* tChild = ChiList->GetLinklist(tindex);
			tChildIndex = tChild->Index;
			RecursiveDeleteChild(tChild->Child);
			ChiList->DeleteLinklist(tindex);
			strL->DeleteLinklist(tChildIndex);
		}
		delete(ChiList);
		ChiList = NULL;
	}
	return ret;
}
 
template <class TLinklist>
TLinklist Tree<TLinklist>::DeleteTree(unsigned int pPos) //ɾ�����е�Ԫ�� //O(n)
{
	TLinklist ret = FALSE;
	if(strL != NULL)
	{
		LinkNode<TLinklist>* DeleteNode = GetTree(pPos);
		if(DeleteNode != NULL)
		{
			LinkNode<TLinklist> *ParNode = DeleteNode->Parent;
			RecursiveDeleteChild(DeleteNode->Child);
			strL->DeleteLinklist(pPos);
			if(ParNode != NULL)
			{
				Linklist<TLinklist> *tChiList = ParNode->Child;
				if(tChiList != NULL)
				{
					tChiList->DeleteChild(DeleteNode);
				}
			}
			DeleteNode = NULL;
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
			Node->Parent = ParNode;
			strL->AddLinklist(Node, strL->GetLinklistLength());
			Node->Index = strL->GetLinklistLength();
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
int Tree<TLinklist>::RecursiveNodeHeight(LinkNode<TLinklist>* ChiNode, int index) //���ݻ�ȡ��ǰ���ĸ߶�
{
	int ret = 0;
	if(ChiNode != NULL)
	{
		ret = index;
		int tindexx = 0;
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildLength = tChildLinkList->GetLinklistLength();
			for(int tindexy = 0; tindexy<tChildLength; tindexy++)
			{
				tindexx = RecursiveNodeHeight(tChildLinkList->GetLinklist(tindexy), index+1);
				if(tindexx > ret)
				{
					ret = tindexx;
				}
			}
		}
	}
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeHeight() //��ȡ����ǰ���ĸ߶�
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeHeight(rootNode, 1);
		}
	} 
	return ret; 
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
	if(strL != NULL)
	{
		ret = strL->GetLinklistLength();
	} 
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::RecursiveNodeDegree(LinkNode<TLinklist>* ChiNode) //���ݲ����ӽڵ�Ķ� 
{
	int ret = 0;
	if(strL != NULL)
	{
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildDegree = tChildLinkList->GetLinklistLength();
			ret = tChildDegree;
			for(int tindex = 0; tindex<tChildDegree; tindex++)
			{
				int tmp = RecursiveNodeDegree(tChildLinkList->GetLinklist(tindex));
				if(tmp > tChildDegree)
				{
					ret = tmp;
				}
				else
				{
					ret = tChildDegree;
				}
			}
		}
	}
	return ret;
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeDegree(void) //��ȡ��ǰ���Ķ�
{
	int ret = 0;
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			ret = RecursiveNodeDegree(rootNode);
		}
	}
	return ret;
}

template <class TLinklist>
void Tree<TLinklist>::RecursiveShowChild(LinkNode<TLinklist>* ChiNode, unsigned int Blank) //���ݴ�ӡ�ӽڵ�
{
	if(ChiNode != NULL)
	{
		for(unsigned int tindexx = 0; tindexx< Blank*4; tindexx++)
		{
			printf("-");
		}
		printf("%c\n", ChiNode->data);
		Linklist<TLinklist>* tChildLinkList = ChiNode->Child;
		if(tChildLinkList != NULL)
		{
			int tChildLength = tChildLinkList->GetLinklistLength();
			for(int tindexy = 0; tindexy<tChildLength; tindexy++)
			{
				RecursiveShowChild(tChildLinkList->GetLinklist(tindexy), Blank+1);
			}
		}
	}
} 

template <class TLinklist>
void Tree<TLinklist>::ShowTree() //��ӡ��������Ԫ��  //O(n)
{
	if(strL != NULL)
	{
		LinkNode<TLinklist> * rootNode = GetTree(0);
		if(rootNode != NULL)
		{
			printf("\n");
			RecursiveShowChild(rootNode, 1);
			printf("\n");
		}
	} 
}

template <class TLinklist>
int Tree<TLinklist>::GetTreeSerch(TLinklist Des)   //��ȡDes��������֯�����е�λ�ò���ӡ��Ӧ·��
{
	int ret = 0;
	
	return ret;
}

#endif //_TREE_CPP_
