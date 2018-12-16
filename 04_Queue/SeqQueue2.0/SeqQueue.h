#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

#include "SeqlistForQueue.h"

class SeqQueue
{
public:
	SeqQueue(int MaxLength);
	~SeqQueue();
	
	bool SeqQueue_Clear(void);
	int SeqQueue_Append(int *data);
	int SeqQueue_Retrieve(void);
	int SeqQueue_Header(void);
	int SeqQueue_GetLength(void);
	int SeqQueue_GetMaxLength(void);
	
private:
	Seqlist<int> *S;
};




#endif //_SEQQUEUE_H_
