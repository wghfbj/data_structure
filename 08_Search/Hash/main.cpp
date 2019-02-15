#include "Hash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Hash * HS = new Hash();
	if(HS != NULL)
	{
		int a = 1;
		int b = 2;
		int c = 3;
		HS->InsertHash(a, &a);
		HS->InsertHash(b, &b);
		HS->InsertHash(c, &c);
		HS->ShowBSTree();
		int *Ret = (HS->GetHash(2));
		if(Ret != NULL)
		{
			printf("\n Get Hash is %d \n", *Ret);
		}
	}
	delete(HS);
	HS = NULL;
	return 0;
}
