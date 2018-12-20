#ifndef _SHELLSORT_H_
#define _SHELLSORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TShellSort;

template <class TShellSort>
class ShellSort
{
public:
	ShellSort(int Len);  //创建线性表 
	~ShellSort();   //销毁线性表 
	int ClearShellSort();  //清空线性表
	TShellSort DeleteShellSort(int index); //删除线性表中的元素
	TShellSort AddShellSort(TShellSort *data, int index); //在线性表中的某个位置添加元素 
	TShellSort GetShellSort(int index); //获取线性表中某个位置的元素
	int GetShellSortMaxLength(void); //获取线性表所能承受的最大长度
	int GetShellSortLength(void); //获取线性表当前的数据长度
	void ShowShellSort(void); 
	void StartSort(void); //排序线性表中所有元素大小顺序

private:
	bool Swap(int A, int B); //交换两个元素位置
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_SHELLSORT_H_
