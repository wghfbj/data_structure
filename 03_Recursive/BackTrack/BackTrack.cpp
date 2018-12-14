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
		    P[tindex] = new char[Num+2];
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

	for(int tindex=0; tindex<CPSize && ret == TRUE; tindex++)
	{//printf("\n line is %d x = %d y = %d \n", __LINE__, x, y);
		int Parm = 0;
		do
		{
			Parm++;
			//printf("\n line is %d \n", __LINE__);
			if(P[x+CP[tindex].x*Parm][y+CP[tindex].y*Parm] == '*')
			{//printf("\n line is %d \n", __LINE__);
				ret = FALSE;
				break;
			}
		}while(ret && P[x+CP[tindex].x*Parm][y+CP[tindex].y*Parm] != '#');
	}
	
	return ret;
}

bool BackTrack::StartFinding(int Start)
{
	bool ret = TRUE;
	//printf("\n Start is %d \n", Start);
	if(Start >= Size-1)
	{
		Display();
	}
	else
	{//printf("\n line is %d Start is %d \n", __LINE__, Start);
		for(int tindex=1; tindex<Size-1; tindex++)
		{//printf("\n line is %d \n", __LINE__);
			ret = CheckValid(tindex, Start);
			
			if(ret)
			{//printf("\n line is %d \n", __LINE__);
				P[tindex][Start] = '*';
				//Display();
				StartFinding(Start+1);
				P[tindex][Start] = ' ';
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

