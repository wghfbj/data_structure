#ifndef _INSERTTIONSORT_H_
#define _INSERTTIONSORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TInsertionSort;

template <class TInsertionSort>
class InsertionSort
{
public:
	InsertionSort(int Len);  //创建线性表 
	~InsertionSort();   //销毁线性表 
	int ClearInsertionSort();  //清空线性表
	TInsertionSort DeleteInsertionSort(int index); //删除线性表中的元素
	TInsertionSort AddInsertionSort(TInsertionSort *data, int index); //在线性表中的某个位置添加元素 
	TInsertionSort GetInsertionSort(int index); //获取线性表中某个位置的元素
	int GetInsertionSortMaxLength(void); //获取线性表所能承受的最大长度
	int GetInsertionSortLength(void); //获取线性表当前的数据长度
	void ShowInsertionSort(void); 
	void StartSort(void); //排序线性表中所有元素大小顺序

private:
	bool Swap(int A, int B); //交换两个元素位置
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_INSERTTIONSORT_H_
