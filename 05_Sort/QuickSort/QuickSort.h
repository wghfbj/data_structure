#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>
#include <iostream>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TQuickSort;

template <class TQuickSort>
class QuickSort
{
public:
	QuickSort(int Len);  //创建线性表 
	~QuickSort();   //销毁线性表 
	int ClearQuickSort();  //清空线性表
	TQuickSort DeleteQuickSort(int index); //删除线性表中的元素
	TQuickSort AddQuickSort(TQuickSort *data, int index); //在线性表中的某个位置添加元素 
	TQuickSort GetQuickSort(int index); //获取线性表中某个位置的元素
	int GetQuickSortMaxLength(void); //获取线性表所能承受的最大长度
	int GetQuickSortLength(void); //获取线性表当前的数据长度
	void ShowQuickSort(void); 
	void StartSort(void); //排序线性表中所有元素大小顺序
	int Part(int low, int high); //给线性表中数据进行左右分组
	void QuickS(int low, int high); //给线性表中数据进行左右分组分组后的递归排序

private:
	bool Swap(int A, int B); //交换两个元素位置
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_QUICKSORT_H_
