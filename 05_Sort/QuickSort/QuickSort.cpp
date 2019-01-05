#include "QuickSort.h"


template <class TQuickSort>
QuickSort<TQuickSort>::QuickSort(int Len)  //�������Ա� //O(1)
{
	Node = new TQuickSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TQuickSort>
QuickSort<TQuickSort>::~QuickSort()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TQuickSort>
int QuickSort<TQuickSort>::ClearQuickSort()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TQuickSort>
TQuickSort QuickSort<TQuickSort>::DeleteQuickSort(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TQuickSort ret = FALSE;
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

template <class TQuickSort>
TQuickSort QuickSort<TQuickSort>::AddQuickSort(TQuickSort *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TQuickSort ret = FALSE;
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

template <class TQuickSort>
TQuickSort QuickSort<TQuickSort>::GetQuickSort(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	TQuickSort ret = 0;
	if(Node != NULL)
	{
		ret = (TQuickSort)Node[index];
	}
	return ret;
}

template <class TQuickSort>
int QuickSort<TQuickSort>::GetQuickSortMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class TQuickSort>
int QuickSort<TQuickSort>::GetQuickSortLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TQuickSort>
void QuickSort<TQuickSort>::ShowQuickSort() //��ӡ���Ա�������Ԫ��  //O(n)
{
	if(Node != NULL)
	{
		printf("\nQuickSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("Node[%d] = %d \n", Start, (TQuickSort)Node[Start]);
		}
	}
}

template <class TQuickSort>
int QuickSort<TQuickSort>::Part(int low, int high) //�����Ա������ݽ������ҷ���
{
	int ret = -1;
	if(Node != NULL)
	{
		int tmp = Node[low];
		while(low < high)
		{
			while((low < high) && (tmp <= Node[high]))
			{
				high--;
			}

			Swap(low, high);

			while((low < high) && (tmp >= Node[low]))
			{
				low++;
			}

			Swap(low, high);
		}
		ret = low;
	}
	return ret;
}

template <class TQuickSort>
void QuickSort<TQuickSort>::QuickS(int low, int high) //�����Ա������ݽ������ҷ�������ĵݹ�����
{
	if(Node != NULL)
	{
		if(low < high)
		{
			int tmp = Part(low, high);
			if(tmp != -1)
			{
				QuickS(low, tmp-1);
				QuickS(tmp+1, high);
			}
		}
	}
} 

template <class TQuickSort>
void QuickSort<TQuickSort>::StartSort() //�������Ա�������Ԫ�ش�С˳��
{
	if(Node != NULL)
	{
		QuickS(0, Length);
	}
}

template <class TQuickSort>
bool QuickSort<TQuickSort>::Swap(int A, int B) //��������Ԫ��λ��  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TQuickSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
