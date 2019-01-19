#include "LinkQueue.h"
#include "Linklist.cpp"


LinkQueue::LinkQueue(void)   //O(1)
{
	L = new Linklist<char>();
}


LinkQueue::~LinkQueue(void)   //O(1)
{
	if(L != NULL)
	{
		delete(L);
		L = NULL;
	}
}


bool LinkQueue::LinkQueue_Clear(void)   //O(n)
{
	return L->ClearLinklist();
}

char LinkQueue::LinkQueue_Append(char *data)   //O(n)
{
	return L->AddLinklist(data, L->GetLinklistLength());
}

char* LinkQueue::LinkQueue_Retrieve(void)   //O(1)
{
	return L->DeleteLinklist(0);
}

char* LinkQueue::LinkQueue_Header(void)   //O(1)
{
	return L->GetLinklist(0);
}

int LinkQueue::LinkQueue_GetLength(void)   //O(1)
{
	return L->GetLinklistLength();
}


