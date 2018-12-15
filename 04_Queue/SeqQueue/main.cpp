#include <iostream>
#include "SeqQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	SeqQueue *SQ = new SeqQueue(20);
	
	if(SQ != NULL)
	{
		for(int tindex=0; tindex<10; tindex++)
		{
			int Num = tindex;
			SQ->SeqQueue_Append(&Num);
		}
		
		printf("\n MaxLength is %d \n", SQ->SeqQueue_GetMaxLength());
		printf("\n Length is %d \n", SQ->SeqQueue_GetLength());
		printf("\n Header is %d \n", SQ->SeqQueue_Header());
		printf("\n Out is %d \n", SQ->SeqQueue_Retrieve());
		printf("\n Out is %d \n", SQ->SeqQueue_Retrieve());
		printf("\n Out is %d \n", SQ->SeqQueue_Retrieve());
		printf("\n Length is %d \n", SQ->SeqQueue_GetLength());
		printf("\n Header is %d \n", SQ->SeqQueue_Header());
		
		delete(SQ);
		SQ = NULL;
	}
	return 0;
}
