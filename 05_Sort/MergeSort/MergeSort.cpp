#include "MergeSort.h"


template <class TMergeSort>
MergeSort<TMergeSort>::MergeSort(int Len)  //�������Ա� //O(1)
{
	Node = new TMergeSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TMergeSort>
MergeSort<TMergeSort>::~MergeSort()  //�������Ա�  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::ClearMergeSort()  //������Ա� //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TMergeSort>
TMergeSort MergeSort<TMergeSort>::DeleteMergeSort(int index) //ɾ�����Ա��е�Ԫ�� //O(n)
{
	TMergeSort ret = FALSE;
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

template <class TMergeSort>
TMergeSort MergeSort<TMergeSort>::AddMergeSort(TMergeSort *data, int index) //�����Ա��е�ĳ��λ�����Ԫ��  //O(n)
{
	TMergeSort ret = FALSE;
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

template <class TMergeSort>
TMergeSort MergeSort<TMergeSort>::GetMergeSort(int index) //��ȡ���Ա���ĳ��λ�õ�Ԫ�� //O(1)
{
	TMergeSort ret = 0;
	if(Node != NULL)
	{
		ret = (TMergeSort)Node[index];
	}
	return ret;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::GetMergeSortMaxLength() //��ȡ���Ա����ܳ��ܵ���󳤶� //O(1)
{
	return MaxLength;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::GetMergeSortLength() //��ȡ���Ա�ǰ�����ݳ���  //O(1)
{
	return Length;
}

template <class TMergeSort>
void MergeSort<TMergeSort>::ShowMergeSort() //��ӡ���Ա�������Ԫ��  //O(n)
{
	if(Node != NULL)
	{
		printf("\n MergeSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (TMergeSort)Node[Start]);
		}
	}
}

template <class TMergeSort>
void MergeSort<TMergeSort>::StartSort(void) //�������Ա�������Ԫ�ش�С˳��  //O(n2)
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

template <class TMergeSort>
bool MergeSort<TMergeSort>::Swap(int A, int B) //��������Ԫ��λ��  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TMergeSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
