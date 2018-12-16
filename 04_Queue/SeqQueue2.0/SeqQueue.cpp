#include "SeqQueue.h"
#include "SeqlistForQueue.cpp"


SeqQueue::SeqQueue(int MaxLength)  // O(1)
{
	S = new Seqlist<int>(MaxLength);
}


SeqQueue::~SeqQueue()  // O(1)
{
	if(S != NULL)
	{
		delete(S);
		S = NULL;
	}
}

bool SeqQueue::SeqQueue_Clear(void)  // O(1)
{
	return S->ClearSeqlist();
}

int SeqQueue::SeqQueue_Append(int *data)  // O(1)
{
	return S->AddSeqlist(data, S->GetSeqlistLength());
}

int SeqQueue::SeqQueue_Retrieve(void)  // O(1)
{
	return S->DeleteSeqlist(0);
}

int SeqQueue::SeqQueue_Header(void)  // O(1)
{
	return S->GetSeqlist(0);
}

int SeqQueue::SeqQueue_GetLength(void)  // O(1)
{
	return S->GetSeqlistLength();
}

int SeqQueue::SeqQueue_GetMaxLength(void)  // O(1)
{
	return S->GetSeqlistMaxLength();
}

