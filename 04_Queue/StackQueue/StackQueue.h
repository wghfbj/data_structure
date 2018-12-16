#ifndef _STACKQUEUE_H_
#define _STACKQUEUE_H_

#include "LinkStack.h"

class StackQueue
{
public:
	StackQueue(void);
	~StackQueue(void);

	bool StackQueue_Clear(void);
	int StackQueue_Append(int *data);
	int StackQueue_Retrieve(void);
	int StackQueue_Header(void);
	int StackQueue_GetLength(void);
	
private:
	LinkStack<int> *InStack;
	LinkStack<int> *OutStack;
};



#endif //_STACKQUEUE_H_
