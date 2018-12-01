#ifndef _STATICLIST_H_
#define _STATICLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TStaticlist;


//=============StaticNode
template <class TStaticlist>
class StaticNode
{
public:
	StaticNode(TStaticlist data);
	TStaticlist data;
	int NextNode;
};


//=============Staticlist
template <class TStaticlist>
class Staticlist
{
public:
	Staticlist(int MaxLength);  //创建线性表 
	~Staticlist();   //销毁线性表 
	int ClearStaticlist();  //清空线性表
	TStaticlist DeleteStaticlist(int index); //删除线性表中的元素
	TStaticlist AddStaticlist(TStaticlist *data, unsigned int index); //在线性表中的某个位置添加元素 
	TStaticlist GetStaticlist(int index); //获取线性表中某个位置的元素
	int GetStaticlistLength(void); //获取线性表当前的数据长度
	int GetStaticlistMaxLength(void); //获取线性表最大的数据长度
	void ShowStaticlist(void);

private:
	int MaxLength;
	StaticNode<TStaticlist> **SN;
};


#endif //_STATICLIST_H_
