#include "InsertionSort.h"


template <class TInsertionSort>
InsertionSort<TInsertionSort>::InsertionSort(int Len)  //�������Ա� //O(1)
{
	Node = new TInsertionSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TInsertionSort>
InsertionSort<TInsertionSort>::~InsertionSort()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::ClearInsertionSort()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TInsertionSort>
TInsertionSort InsertionSort<TInsertionSort>::DeleteInsertionSort(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TInsertionSort ret = FALSE;
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

template <class TInsertionSort>
TInsertionSort InsertionSort<TInsertionSort>::AddInsertionSort(TInsertionSort *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TInsertionSort ret = FALSE;
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

template <class TInsertionSort>
TInsertionSort InsertionSort<TInsertionSort>::GetInsertionSort(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	TInsertionSort ret = 0;
	if(Node != NULL)
	{
		ret = (TInsertionSort)Node[index];
	}
	return ret;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::GetInsertionSortMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::GetInsertionSortLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TInsertionSort>
void InsertionSort<TInsertionSort>::ShowInsertionSort() //��ӡ���Ա�������Ԫ��  //O(n)
{
	if(Node != NULL)
	{
		printf("\n InsertionSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("  Node[%d] = %d  \n", Start, (TInsertionSort)Node[Start]);
		}
	}
}

template <class TInsertionSort>
void InsertionSort<TInsertionSort>::StartSort(void) //�������Ա�������Ԫ�ش�С˳��  //O(n2)
{
	if(Node != NULL)
	{
		for(int tindexx = 1; tindexx < Length; tindexx++)
		{
			int tmp = tindexx;
			for(int tindexy = tindexx-1; tindexy>=0; tindexy--)
			{
				if(Node[tmp] < Node[tindexy])
				{
					Swap(tmp, tindexy);
					tmp = tindexy;
				}
			}
		}
	}
}

template <class TInsertionSort>
bool InsertionSort<TInsertionSort>::Swap(int A, int B) //��������Ԫ��λ��  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TInsertionSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
