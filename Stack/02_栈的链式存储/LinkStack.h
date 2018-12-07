#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include "Linklist.h"

template <class TLinklist>
class LinkStack
{
public:
	LinkStack(void);   //����ջ 
	~LinkStack(void);  //����ջ 
	
	bool Clear_LinkStack(void);  //���ջ 
	bool Push_LinkStack(TLinklist *data);  //ѹ���ݽ�ջ 
	TLinklist Pop_LinkStack(void);  //����ջ������ 
	TLinklist GetTop_LinkStack(void);  //��ȡջ������ 
	int GetLength_LinkStack(void);  //��ȡ��ǰջ�ĳ��� 

private:
	Linklist<TLinklist> *S;
};



#endif //_LINKSTACK_H_
