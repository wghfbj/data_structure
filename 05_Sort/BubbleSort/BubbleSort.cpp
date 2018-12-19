#include "BubbleSort.h"


template <class TBubbleSort>
BubbleSort<TBubbleSort>::BubbleSort(int Len)  //�������Ա� //O(1)
{
	Node = new TBubbleSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TBubbleSort>
BubbleSort<TBubbleSort>::~BubbleSort()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TBubbleSort>
int BubbleSort<TBubbleSort>::ClearBubbleSort()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TBubbleSort>
TBubbleSort BubbleSort<TBubbleSort>::DeleteBubbleSort(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TBubbleSort ret = FALSE;
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

template <class TBubbleSort>
TBubbleSort BubbleSort<TBubbleSort>::AddBubbleSort(TBubbleSort *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TBubbleSort ret = FALSE;
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

template <class TBubbleSort>
TBubbleSort BubbleSort<TBubbleSort>::GetBubbleSort(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	TBubbleSort ret = 0;
	if(Node != NULL)
	{
		ret = (TBubbleSort)Node[index];
	}
	return ret;
}

template <class TBubbleSort>
int BubbleSort<TBubbleSort>::GetBubbleSortMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class TBubbleSort>
int BubbleSort<TBubbleSort>::GetBubbleSortLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TBubbleSort>
void BubbleSort<TBubbleSort>::ShowBubbleSort() //��ӡ���Ա�������Ԫ��  //O(n)
{
	if(Node != NULL)
	{
		printf("\n BubbleSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (TBubbleSort)Node[Start]);
		}
	}
}

template <class TBubbleSort>
void BubbleSort<TBubbleSort>::StartSort(void) //�������Ա�������Ԫ�ش�С˳��  //O(n2)
{
	if(Node != NULL)
	{
		for(int tindexx = 0; tindexx < Length; tindexx++)
		{
			int tMin = tindexx;
			for(int tindexy = tindexx; tindexy<Length; tindexy++)
			{
				if(Node[tindexy] < Node[tMin])
				{
					tMin = tindexy;
				}
			}
			Swap(tindexx, tMin);
		}
	}
}

template <class TBubbleSort>
bool BubbleSort<TBubbleSort>::Swap(int A, int B) //��������Ԫ��λ��  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TBubbleSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
