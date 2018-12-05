#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include "Linklist.h"

template <class TLinklist>
class LinkStack
{
public:
	LinkStack(void);
	~LinkStack(void);
	
	bool Clear_LinkStack(void);
	bool Push_LinkStack(TLinklist *data);
	TLinklist Pop_LinkStack(void);
	TLinklist GetTop_LinkStack(void);
	int GetLength_LinkStack(void);
	int GetMaxLength_LinkStack(void);

private:
	Linklist<TLinklist> *S;
};



#endif //_LINKSTACK_H_
