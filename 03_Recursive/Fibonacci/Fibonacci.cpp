#include "Fibonacci.h"

int Fibonacci::Start(int Num)
{
	int ret = 0;
	if(Num > 1)
	{
		ret = Start(Num - 1) + Start(Num - 2);
	}
	else if(Num == 1)
	{
		ret = 1;
	}
	else if(Num = 0)
	{
		ret = 0;
	}
	
	return ret; 
}
