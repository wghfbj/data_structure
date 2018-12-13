#include "BackTrack.h"

static CheckP CP[] = 
{
{-1, -1},
{0, -1},
{1, -1},
};

static int CPSize = sizeof(CP)/sizeof(CP[0]);

BackTrack::BackTrack(int Num)
{
	Size = Num+2;
	P = new char*[Num+2];
	if(P != NULL)
	{
		for (int tindex = 0; tindex < Num+2; tindex++)
		{
		    P[tindex] = new char[Num];
		}
		for(int tindexy=0; tindexy<Num+2; tindexy++)
		{
			for(int tindexx=0; tindexx<Num+2; tindexx++)
			{
				if((tindexy==0 || tindexy==Num+1 || tindexx==0 || tindexx==Num+1))
				{
					P[tindexx][tindexy] = '#';
					//printf("#");
				}
				else
				{
					P[tindexx][tindexy] = ' ';
					//printf(" ");
				}
			}
		}

		//Display();
	}
}

bool BackTrack::Display(void)
{
	for(int tindexy=0; tindexy<Size; tindexy++)
	{
		for(int tindexx=0; tindexx<Size; tindexx++)
		{
			printf("%c", P[tindexx][tindexy]);
		}
		printf("\n");
	}
}

bool BackTrack::CheckValid(int x, int y)
{
	bool ret = TRUE;

	for(int tindex=0; tindex<CPSize; tindex++)
	{
		int Parm = 1;
		while(ret && P[x+CP[tindex].x*Parm][y+CP[tindex].y*Parm] != '#')
		{
			if(P[x+CP[tindex].x*Parm][y+CP[tindex].y*Parm] == '*')
			{
				ret = FALSE;
				break;
			}
			Parm++;
		}
	}
	
	return ret;
}

bool BackTrack::StartFinding(int Start)
{
	bool ret = TRUE;
	
	if(Start > Size)
	{
		Display();
	}
	else
	{
		for(int tindex=0; tindex<Size; tindex++)
		{
			ret = CheckValid(Start, tindex);
			
			if(ret)
			{
				P[Start][tindex] = '*';
				StartFinding(Start+1);
				P[Start][tindex] = ' ';
			}
		}		
	}
	
	return ret;
}

int BackTrack::Start(void)
{
	int ret = -1;
	
	ret = StartFinding(1);
	
	return ret; 
}

