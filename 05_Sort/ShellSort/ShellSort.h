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
	ShellSort(int Len);  //�������Ա� 
	~ShellSort();   //�������Ա� 
	int ClearShellSort();  //������Ա�
	TShellSort DeleteShellSort(int index); //ɾ�����Ա��е�Ԫ��
	TShellSort AddShellSort(TShellSort *data, int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TShellSort GetShellSort(int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetShellSortMaxLength(void); //��ȡ���Ա����ܳ��ܵ���󳤶�
	int GetShellSortLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowShellSort(void); 
	void StartSort(void); //�������Ա�������Ԫ�ش�С˳��

private:
	bool Swap(int A, int B); //��������Ԫ��λ��
	int Length;
	int MaxLength;
	int *Node;
};

#endif //_SHELLSORT_H_
