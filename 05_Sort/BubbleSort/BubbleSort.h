#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int TBubbleSort;

template <class TBubbleSort>
class BubbleSort
{
public:
	BubbleSort(int Len);  //�������Ա� 
	~BubbleSort();   //�������Ա� 
	int ClearBubbleSort();  //������Ա�
	TBubbleSort DeleteBubbleSort(int index); //ɾ�����Ա��е�Ԫ��
	TBubbleSort AddBubbleSort(TBubbleSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TBubbleSort GetBubbleSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetBubbleSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetBubbleSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowBubbleSort(void); 
	void StartSort(void); //�������Ա�������Ԫ�ش�С˳��

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_BUBBLESORT_H_
