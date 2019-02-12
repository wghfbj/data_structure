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
	InsertionSort(int Len);  //�������Ա� 
	~InsertionSort();   //�������Ա� 
	int ClearInsertionSort();  //������Ա�
	TInsertionSort DeleteInsertionSort(int index); //ɾ�����Ա��е�Ԫ��
	TInsertionSort AddInsertionSort(TInsertionSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TInsertionSort GetInsertionSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetInsertionSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetInsertionSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowInsertionSort(void); 
	void StartSort(void); //�������Ա�������Ԫ�ش�С˳��

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_INSERTTIONSORT_H_
