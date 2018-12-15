#include "SeqQueue.h"
#include "Seqlist.cpp"


SeqQueue::SeqQueue(int MaxLength)
{
	S = new Seqlist<int>(MaxLength);
}


SeqQueue::~SeqQueue()
{
	if(S != NULL)
	{
		delete(S);
		S = NULL;
	}
}

bool SeqQueue::SeqQueue_Clear(void)
{
	return S->ClearSeqlist();
}

int SeqQueue::SeqQueue_Append(int *data)
{
	return S->AddSeqlist(data, S->GetSeqlistLength());
}

int SeqQueue::SeqQueue_Retrieve(void)
{
	return S->DeleteSeqlist(0);
}

int SeqQueue::SeqQueue_Header(void)
{
	return S->GetSeqlist(0);
}

int SeqQueue::SeqQueue_GetLength(void)
{
	return S->GetSeqlistLength();
}

int SeqQueue::SeqQueue_GetMaxLength(void)
{
	return S->GetSeqlistMaxLength();
}

