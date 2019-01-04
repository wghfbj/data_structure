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
		printf("\n QuickSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (TQuickSort)Node[Start]);
		}
	}
}

template <class TQuickSort>
void QuickSort<TQuickSort>::StartSort(int index) //�������Ա�������Ԫ�ش�С˳��  //O(n2)
{
	if(Node != NULL)
	{
		int ShellStep = index;
		do
		{
			ShellStep = ShellStep/3+1;
			for(int tindexx=ShellStep; tindexx!=0; tindexx=(ShellStep+tindexx)%Length)
			{
				int tmp = tindexx;
				for(int tindexy = tindexx-ShellStep; tindexy>=0; tindexy-=ShellStep)
				{
					if(Node[tmp] < Node[tindexy])
					{
						Swap(tmp, tindexy);
						tmp = tindexy;
					}
				}
			}
		}while(ShellStep > 1);
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
