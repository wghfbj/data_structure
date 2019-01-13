#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

template <class TLinklist>
class Linklist;
//typedef int TLinklist;


//=============LinkNode
template <class TLinklist>
class LinkNode
{
public:
	LinkNode(TLinklist data);
	TLinklist data;
	int Index;
	LinkNode *NextNode;
	LinkNode *Parent;
	Linklist<TLinklist> *Child;
};


//=============Linklist
template <class TLinklist>
class Linklist : public LinkNode<TLinklist>
{
public:
	Linklist(void);  //创建线性表 
	~Linklist();   //销毁线性表 
	int ClearLinklist();  //清空线性表
	TLinklist DeleteLinklist(unsigned int index); //删除线性表中的元素
	TLinklist AddLinklist(LinkNode<TLinklist> *data, unsigned int index); //在线性表中的某个位置添加元素 
	LinkNode<TLinklist>* GetLinklist(unsigned int index); //获取线性表中某个位置的元素
	int GetLinklistLength(void); //获取线性表当前的数据长度
	void ShowLinklist(void);
	TLinklist DeleteChild(LinkNode<TLinklist> *Node);

private:
	int Length;
};


#endif //_LINKLIST_H_
