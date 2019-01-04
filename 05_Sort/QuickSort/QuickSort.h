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
	QuickSort(int Len);  //�������Ա� 
	~QuickSort();   //�������Ա� 
	int ClearQuickSort();  //������Ա�
	TQuickSort DeleteQuickSort(int index); //ɾ�����Ա��е�Ԫ��
	TQuickSort AddQuickSort(TQuickSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TQuickSort GetQuickSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetQuickSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetQuickSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowQuickSort(void); 
	void StartSort(int index); //�������Ա�������Ԫ�ش�С˳��

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_QUICKSORT_H_
