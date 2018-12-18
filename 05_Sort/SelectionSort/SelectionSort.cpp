#include "SelectionSort.h"


template <class TSelectionSort>
SelectionSort<TSelectionSort>::SelectionSort(int Len)  //�������Ա� //O(1)
{
	Node = new TSelectionSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TSelectionSort>
SelectionSort<TSelectionSort>::~SelectionSort()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TSelectionSort>
int SelectionSort<TSelectionSort>::ClearSelectionSort()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TSelectionSort>
TSelectionSort SelectionSort<TSelectionSort>::DeleteSelectionSort(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TSelectionSort ret = FALSE;
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

template <class TSelectionSort>
TSelectionSort SelectionSort<TSelectionSort>::AddSelectionSort(TSelectionSort *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TSelectionSort ret = FALSE;
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

template <class TSelectionSort>
TSelectionSort SelectionSort<TSelectionSort>::GetSelectionSort(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	TSelectionSort ret = 0;
	if(Node != NULL)
	{
		ret = (TSelectionSort)Node[index];
	}
	return ret;
}

template <class TSelectionSort>
int SelectionSort<TSelectionSort>::GetSelectionSortMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class TSelectionSort>
int SelectionSort<TSelectionSort>::GetSelectionSortLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TSelectionSort>
void SelectionSort<TSelectionSort>::ShowSelectionSort() //��ӡ���Ա�������Ԫ��  //O(n)
{
	if(Node != NULL)
	{
		printf("\n SelectionSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (TSelectionSort)Node[Start]);
		}
	}
}

template <class TSelectionSort>
void SelectionSort<TSelectionSort>::StartSort(void) //�������Ա�������Ԫ�ش�С˳��  //O(n2)
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

template <class TSelectionSort>
bool SelectionSort<TSelectionSort>::Swap(int A, int B) //��������Ԫ��λ��  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TSelectionSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
