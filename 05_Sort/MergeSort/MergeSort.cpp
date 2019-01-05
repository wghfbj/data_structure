#include "MergeSort.h"


template <class TMergeSort>
MergeSort<TMergeSort>::MergeSort(int Len)  //创建线性表 //O(1)
{
	Node = new TMergeSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TMergeSort>
MergeSort<TMergeSort>::~MergeSort()  //销毁线性表  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::ClearMergeSort()  //清空线性表 //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TMergeSort>
TMergeSort MergeSort<TMergeSort>::DeleteMergeSort(int index) //删除线性表中的元素 //O(n)
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
TMergeSort MergeSort<TMergeSort>::AddMergeSort(TMergeSort *data, int index) //在线性表中的某个位置添加元素  //O(n)
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
TMergeSort MergeSort<TMergeSort>::GetMergeSort(int index) //获取线性表中某个位置的元素 //O(1)
{
	TMergeSort ret = 0;
	if(Node != NULL)
	{
		ret = (TMergeSort)Node[index];
	}
	return ret;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::GetMergeSortMaxLength() //获取线性表所能承受的最大长度 //O(1)
{
	return MaxLength;
}

template <class TMergeSort>
int MergeSort<TMergeSort>::GetMergeSortLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TMergeSort>
void MergeSort<TMergeSort>::ShowMergeSort() //打印线性表中所有元素  //O(n)
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
void MergeSort<TMergeSort>::StartSort(void) //排序线性表中所有元素大小顺序  //O(n2)
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
bool MergeSort<TMergeSort>::Swap(int A, int B) //交换两个元素位置  //O(1)
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
