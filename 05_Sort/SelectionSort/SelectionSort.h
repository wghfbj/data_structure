#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TSelectionSort;

template <class TSelectionSort>
class SelectionSort
{
public:
	SelectionSort(int Len);  //�������Ա� 
	~SelectionSort();   //�������Ա� 
	int ClearSelectionSort();  //������Ա�
	TSelectionSort DeleteSelectionSort(int index); //ɾ�����Ա��е�Ԫ��
	TSelectionSort AddSelectionSort(TSelectionSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TSelectionSort GetSelectionSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetSelectionSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetSelectionSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowSelectionSort(void); 
	void StartSort(void); //�������Ա�������Ԫ�ش�С˳��

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_SELECTIONSORT_H_
