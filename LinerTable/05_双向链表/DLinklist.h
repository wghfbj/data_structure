#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TDLinklist;


//=============LinkNode
template <class TDLinklist>
class LinkNode
{
public:
	LinkNode(TDLinklist data);
	TDLinklist data;
	LinkNode *NextNode;
	LinkNode *PreNode;
};


//=============DLinklist
template <class TDLinklist>
class DLinklist : public LinkNode<TDLinklist>
{
public:
	DLinklist(void);  //创建线性表 
	~DLinklist();   //销毁线性表 
	int ClearDLinklist();  //清空线性表
	TDLinklist DeleteDLinklist(unsigned int index); //删除线性表中的元素
	TDLinklist AddDLinklist(TDLinklist *data, unsigned int index); //在线性表中的某个位置添加元素 
	TDLinklist GetDLinklist(unsigned int index); //获取线性表中某个位置的元素
	int GetDLinklistLength(void); //获取线性表当前的数据长度
	void ShowDLinklist(void);
	
	//游标新增操作
	LinkNode<TDLinklist> *GetSlider_Currnt(void);
	LinkNode<TDLinklist> *SetSlider_Next(void);
	LinkNode<TDLinklist> *SetSlider_Pre(void);
	bool SetSlider_Reset(void);
	LinkNode<TDLinklist> *DeleteNode(LinkNode<TDLinklist>* data); 

private:
	int Length;
	LinkNode<TDLinklist> *Slider;
};


#endif //_DLINKLIST_H_
