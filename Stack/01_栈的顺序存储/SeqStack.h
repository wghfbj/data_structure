#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include "Seqlist.h"

template <class Tseqlist>
class SeqStack
{
public:
	SeqStack(int Length);  //创建栈
	~SeqStack(void);  //销毁栈
	
	bool Clear_SeqStack(void); //清空栈
	bool Push_SeqStack(Tseqlist *data); //压数据进栈
	Tseqlist Pop_SeqStack(void);    //弹出栈顶数据
	Tseqlist GetTop_SeqStack(void);   //获取栈顶数据
	int GetLength_SeqStack(void);   //获取栈的长度
	int GetMaxLength_SeqStack(void);   //获取栈能保存的最大长度

private:
	Seqlist<Tseqlist> *S;
};




#endif  //_SEQSTACK_H
