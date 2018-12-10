#include "BackTrack.h"

int BackTrack::Start(const char* C)
{
	int ret = -1;
	
	if(C == NULL)
	{
		ret = -1;
	}
	else if(*C == '\0')
	{
		ret = 0;
	}
	else
	{
		ret = Start(C+1) + 1;
	}
	
	return ret; 
}
