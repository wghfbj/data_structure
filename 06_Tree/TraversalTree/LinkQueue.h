#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "Linklist.h"


class LinkQueue
{
public:
	LinkQueue(void);
	~LinkQueue(void);
	
	bool LinkQueue_Clear(void);
	char LinkQueue_Append(char *data);
	char* LinkQueue_Retrieve(void);
	char* LinkQueue_Header(void);
	int LinkQueue_GetLength(void);

private:
	Linklist<char> *L;
};



#endif //_LINKQUEUE_H_
