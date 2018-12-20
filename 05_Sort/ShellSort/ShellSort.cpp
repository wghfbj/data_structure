#include "ShellSort.h"


template <class TShellSort>
ShellSort<TShellSort>::ShellSort(int Len)  //创建线性表 //O(1)
{
	Node = new TShellSort[Len];
	memset(Node, 0 ,MaxLength);
	MaxLength = Len;
	Length = 0;
}

template <class TShellSort>
ShellSort<TShellSort>::~ShellSort()  //销毁线性表  //O(1)
{
	if(Node != NULL)
	{
		delete Node;
	}
	Node = NULL;
}

template <class TShellSort>
int ShellSort<TShellSort>::ClearShellSort()  //清空线性表 //O(1)
{
	Length = 0;
	memset(Node, 0 ,MaxLength);
	return TRUE;
}

template <class TShellSort>
TShellSort ShellSort<TShellSort>::DeleteShellSort(int index) //删除线性表中的元素 //O(n)
{
	TShellSort ret = FALSE;
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

template <class TShellSort>
TShellSort ShellSort<TShellSort>::AddShellSort(TShellSort *data, int index) //在线性表中的某个位置添加元素  //O(n)
{
	TShellSort ret = FALSE;
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

template <class TShellSort>
TShellSort ShellSort<TShellSort>::GetShellSort(int index) //获取线性表中某个位置的元素 //O(1)
{
	TShellSort ret = 0;
	if(Node != NULL)
	{
		ret = (TShellSort)Node[index];
	}
	return ret;
}

template <class TShellSort>
int ShellSort<TShellSort>::GetShellSortMaxLength() //获取线性表所能承受的最大长度 //O(1)
{
	return MaxLength;
}

template <class TShellSort>
int ShellSort<TShellSort>::GetShellSortLength() //获取线性表当前的数据长度  //O(1)
{
	return Length;
}

template <class TShellSort>
void ShellSort<TShellSort>::ShowShellSort() //打印线性表中所有元素  //O(n)
{
	if(Node != NULL)
	{
		printf("\n ShellSort === >> \n");
		for(int Start = 0; Start<Length; Start++)
		{
			printf("\n Node[%d] = %d \n", Start, (TShellSort)Node[Start]);
		}
	}
}

template <class TShellSort>
void ShellSort<TShellSort>::StartSort(void) //排序线性表中所有元素大小顺序  //O(n2)
{
	if(Node != NULL)
	{
		bool exchange = TRUE;
		for(int tindexx = 0; tindexx<Length && exchange; tindexx++)
		{
			exchange = FALSE;
			for(int tindexy=Length-1; tindexy>0; tindexy--)
			{
				if(Node[tindexy] <= Node[tindexy-1])
				{
					exchange = TRUE;
					Swap(tindexy, tindexy-1);
				}
			}
		} 
	}
}

template <class TShellSort>
bool ShellSort<TShellSort>::Swap(int A, int B) //交换两个元素位置  //O(1)
{
	bool ret = FALSE;
	
	if((A <= Length) && (B <= Length))
	{
		TShellSort tmp = Node[A];
		Node[A] = Node[B];
		Node[B] = tmp;
		ret = TRUE;
	}

	return ret;
}
