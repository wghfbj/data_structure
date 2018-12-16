#ifndef _SEQLISTFORQUEUE_H_
#define _SEQLISTFORQUEUE_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;
#define TRUE 1
#define FALSE 0

//typedef int Tseqlist;

template <class Tseqlist>
class Seqlist
{
public:
	Seqlist(int Len);  //创建线性表 
	~Seqlist();   //销毁线性表 
	int ClearSeqlist();  //清空线性表
	Tseqlist DeleteSeqlist(int index); //删除线性表中的元素
	Tseqlist AddSeqlist(Tseqlist *data, int index); //在线性表中的某个位置添加元素 
	Tseqlist GetSeqlist(int index); //获取线性表中某个位置的元素
	int GetSeqlistMaxLength(void); //获取线性表所能承受的最大长度
	int GetSeqlistLength(void); //获取线性表当前的数据长度
	void ShowSeqlist(void);

private:
	int Length;
	int MaxLength;
	int *Node;
};


#endif //_SEQLISTFORQUEUE_H_
