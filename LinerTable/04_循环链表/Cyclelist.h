#ifndef _CYCLELIST_H_
#define _CYCLELIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TCyclelist;


//=============LinkNode
template <class TCyclelist>
class LinkNode
{
public:
	LinkNode(TCyclelist data);
	TCyclelist data;
	LinkNode *NextNode;
};


//=============Cyclelist
template <class TCyclelist>
class Cyclelist : public LinkNode<TCyclelist>
{
public:
	Cyclelist(void);  //创建线性表 
	~Cyclelist();   //销毁线性表 
	int ClearCyclelist();  //清空线性表
	TCyclelist DeleteCyclelist(unsigned int index); //删除线性表中的元素
	TCyclelist AddCyclelist(TCyclelist *data, unsigned int index); //在线性表中的某个位置添加元素 
	TCyclelist GetCyclelist(unsigned int index); //获取线性表中某个位置的元素
	int GetCyclelistLength(void); //获取线性表当前的数据长度
	void ShowCyclelist(void);
	
	//游标新增方法
	LinkNode<TCyclelist> *GetSlider_Currnt(void);
	LinkNode<TCyclelist> *SetSlider_Next(void);
	bool SetSlider_Reset(void);
	LinkNode<TCyclelist> *DeleteNode(LinkNode<TCyclelist>* data);

private:
	int Length;
	LinkNode<TCyclelist> *Slider;
};


#endif //_CYCLELIST_H_
