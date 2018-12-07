#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include "Linklist.h"

template <class TLinklist>
class LinkStack
{
public:
	LinkStack(void);   //创建栈 
	~LinkStack(void);  //销毁栈 
	
	bool Clear_LinkStack(void);  //清空栈 
	bool Push_LinkStack(TLinklist *data);  //压数据进栈 
	TLinklist Pop_LinkStack(void);  //弹出栈顶数据 
	TLinklist GetTop_LinkStack(void);  //获取栈顶数据 
	int GetLength_LinkStack(void);  //获取当前栈的长度 

private:
	Linklist<TLinklist> *S;
};



#endif //_LINKSTACK_H_
