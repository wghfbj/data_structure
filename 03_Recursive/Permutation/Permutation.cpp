#include "Permutation.h"

bool Permutation::Start(char *C, int Begin, int End)
{
	bool ret = FALSE;

	if((C != NULL) && (Begin >= 0) && (Begin <= End))
	{
		if(Begin == End)
		{
			printf("%s\n", C);	
		}
		else
		{
			int tindex = 0;
			for(tindex=Begin; tindex<= End; tindex++)
			{
				char tmpC = C[Begin];
				C[Begin] = C[tindex];
				C[tindex] = tmpC;
				Start(C, Begin+1, End);
				
				//Reset position
				tmpC = C[Begin];
				C[Begin] = C[tindex];
				C[tindex] = tmpC;
			}
		}
		ret = TRUE;
	}
	
	return ret; 
}
