#include "InsertionSort.h"


template <class TInsertionSort>
InsertionSort<TInsertionSort>::InsertionSort(int Len)  //创建线性表 //O(1)
{
	Node = new TInsertionSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TInsertionSort>
InsertionSort<TInsertionSort>::~InsertionSort()  //销毁线性表  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::ClearInsertionSort()  //清空线性表 //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TInsertionSort>
TInsertionSort InsertionSort<TInsertionSort>::DeleteInsertionSort(int index) //删除线性表中的元素 //O(n)
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
TInsertionSort InsertionSort<TInsertionSort>::AddInsertionSort(TInsertionSort *data, int index) //在线性表中的某个位置添加元素  //O(n)
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
TInsertionSort InsertionSort<TInsertionSort>::GetInsertionSort(int index) //获取线性表中某个位置的元素 //O(1)
{
	TInsertionSort ret = 0;
	if(Node != NULL)
	{
		ret = (TInsertionSort)Node[index];
	}
	return ret;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::GetInsertionSortMaxLength() //获取线性表所能承受的最大长度 //O(1)
{
	return MaxLength;
}

template <class TInsertionSort>
int InsertionSort<TInsertionSort>::GetInsertionSortLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TInsertionSort>
void InsertionSort<TInsertionSort>::ShowInsertionSort() //打印线性表中所有元素  //O(n)
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
void InsertionSort<TInsertionSort>::StartSort(void) //排序线性表中所有元素大小顺序  //O(n2)
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
bool InsertionSort<TInsertionSort>::Swap(int A, int B) //交换两个元素位置  //O(1)
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
