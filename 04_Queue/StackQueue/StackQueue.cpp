#include "StackQueue.h"
#include "LinkStack.cpp"

StackQueue::StackQueue(void)
{
	InStack = new LinkStack<int>();
	OutStack = new LinkStack<int>();
	if(InStack == NULL || OutStack == NULL)
	{
		if(InStack == NULL)
		{
			delete(InStack);
			InStack = NULL;
		}
		if(OutStack == NULL)
		{
			delete(OutStack);
			OutStack = NULL;
		}
	}
}

StackQueue::~StackQueue(void)
{
	if(InStack != NULL)
	{
		delete(InStack);
		InStack = NULL;
	}
	
	if(OutStack != NULL)
	{
		delete(OutStack);
		OutStack = NULL;
	}
}

bool StackQueue::StackQueue_Clear(void)
{
	bool ret = FALSE;
	if(InStack != NULL && OutStack != NULL)
	{
		InStack->Clear_LinkStack();
		OutStack->Clear_LinkStack();
		ret = TRUE;
	}
	return ret;
}

int StackQueue::StackQueue_Append(int *data)
{
	if(InStack != NULL)
	{
		InStack->Push_LinkStack(data);
	}
}

int StackQueue::StackQueue_Retrieve(void)
{
	int ret = 0;
	if(InStack != NULL && OutStack != NULL)
	{
		if(OutStack->GetLength_LinkStack() == 0)
		{
			while(InStack->GetLength_LinkStack() > 0)
			{
				int tret = InStack->Pop_LinkStack();
				OutStack->Push_LinkStack(&tret);
			}
		}
		ret = OutStack->Pop_LinkStack();
	}
	return ret;
}

int StackQueue::StackQueue_Header(void)
{
	int ret = 0;
	if(InStack != NULL && OutStack != NULL)
	{
		if(OutStack->GetLength_LinkStack() == 0)
		{
			while(InStack->GetLength_LinkStack() > 0)
			{
				int tret = InStack->Pop_LinkStack();
				OutStack->Push_LinkStack(&tret);
			}
		}
		ret = OutStack->GetTop_LinkStack();
	}
	return ret;
}

int StackQueue::StackQueue_GetLength(void)
{
	int ret = 0;
	if(InStack != NULL && OutStack != NULL)
	{
		ret = InStack->GetLength_LinkStack() + OutStack->GetLength_LinkStack();
	}
	return ret;
}

