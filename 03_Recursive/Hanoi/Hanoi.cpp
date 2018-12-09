#include "Hanoi.h"

bool Hanoi::Start(int Num, char a, char b, char c)  // Num�ƶ�������   a ��ʼ�ƶ�λ��  b �м���Խ���������  c Ŀ��λ�� 
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
