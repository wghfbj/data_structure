#include "Hanoi.h"

bool Hanoi::Start(int Num, char a, char b, char c)  // Num移动的数量   a 起始移动位置  b 中间可以借助的柱子  c 目的位置 
{
	bool ret = FALSE;
	
	if(Num > 0)
	{
		if(Num == 1)
		{
			printf("\n Move %c -> %c \n", a, c);
		}
		else if(Num > 1)
		{
			Start(Num-1, a, c, b);
			printf("\n Move %c -> %c \n", a, c);
			Start(Num-1, b, a, c);
		}
		ret = TRUE;
	}
	
	return ret; 
}
