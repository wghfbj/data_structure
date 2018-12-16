#include <iostream>
#include "StackQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	StackQueue *SQ = new StackQueue();
	
	if(SQ != NULL)
	{
		for(int tindex=0; tindex<10; tindex++)
		{
			int Num = tindex;
			SQ->StackQueue_Append(&Num);
		}

		printf("\n Length is %d \n", SQ->StackQueue_GetLength());
		printf("\n Header is %d \n", SQ->StackQueue_Header());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Length is %d \n", SQ->StackQueue_GetLength());
		printf("\n Header is %d \n", SQ->StackQueue_Header());
		
		for(int tindex=15; tindex<25; tindex++)
		{
			int Num = tindex;
			SQ->StackQueue_Append(&Num);
		}
		
		printf("\n Length is %d \n", SQ->StackQueue_GetLength());
		printf("\n Header is %d \n", SQ->StackQueue_Header());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Out is %d \n", SQ->StackQueue_Retrieve());
		printf("\n Length is %d \n", SQ->StackQueue_GetLength());
		printf("\n Header is %d \n", SQ->StackQueue_Header());
		
		delete(SQ);
		SQ = NULL;
	}
	return 0;
}
