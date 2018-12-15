#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "Linklist.h"


class LinkQueue
{
public:
	LinkQueue(void);
	~LinkQueue(void);
	
	bool LinkQueue_Clear(void);
	int LinkQueue_Append(int *data);
	int LinkQueue_Retrieve(void);
	int LinkQueue_Header(void);
	int LinkQueue_GetLength(void);

private:
	Linklist<int> *L;
};



#endif //_LINKQUEUE_H_
