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
	MergeSort(int Len);  //�������Ա� 
	~MergeSort();   //�������Ա� 
	int ClearMergeSort();  //������Ա�
	TMergeSort DeleteMergeSort(int index); //ɾ�����Ա��е�Ԫ��
	TMergeSort AddMergeSort(TMergeSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TMergeSort GetMergeSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetMergeSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetMergeSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowMergeSort(void); 
	void StartSort(void); //�������Ա�������Ԫ�ش�С˳��
	void Merge(int low, int mid, int high); //�����·���й鲢
	void MSort(int low, int high); //�����Ա������ݽ��еݹ���� 

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	TMergeSort *Node;
};

#endif //_MERGESORT_H_
