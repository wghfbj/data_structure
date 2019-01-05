#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TMergeSort;

template <class TMergeSort>
class MergeSort
{
public:
	MergeSort(int Len);  //创建线性表 
	~MergeSort();   //销毁线性表 
	int ClearMergeSort();  //清空线性表
	TMergeSort DeleteMergeSort(int index); //删除线性表中的元素
	TMergeSort AddMergeSort(TMergeSort *data, int index); //在线性表中的某个位置添加元素 
	TMergeSort GetMergeSort(int index); //获取线性表中某个位置的元素
	int GetMergeSortMaxLength(void); //获取线性表所能承受的最大长度
	int GetMergeSortLength(void); //获取线性表当前的数据长度
	void ShowMergeSort(void); 
	void StartSort(void); //排序线性表中所有元素大小顺序
	void Merge(int low, int mid, int high); //针对两路进行归并
	void MSort(int low, int high); //将线性表中数据进行递归分组 

private:
	bool Swap(int A, int B); //交换两个元素位置
	int Length;
	int MaxLength;
	TMergeSort *Node;
};

#endif //_MERGESORT_H_
