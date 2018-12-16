#include <iostream>
#include "LinkQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	LinkQueue *LQ = new LinkQueue();
	
	if(LQ != NULL)
	{
		for(int tindex=0; tindex<10; tindex++)
		{
			int Num = tindex;
			LQ->LinkQueue_Append(&Num);
		}

		printf("\n Length is %d \n", LQ->LinkQueue_GetLength());
		printf("\n Header is %d \n", LQ->LinkQueue_Header());
		printf("\n Out is %d \n", LQ->LinkQueue_Retrieve());
		printf("\n Out is %d \n", LQ->LinkQueue_Retrieve());
		printf("\n Out is %d \n", LQ->LinkQueue_Retrieve());
		printf("\n Length is %d \n", LQ->LinkQueue_GetLength());
		printf("\n Header is %d \n", LQ->LinkQueue_Header());
		delete(LQ);
	}

	return 0;
}
