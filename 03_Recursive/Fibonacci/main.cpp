#include <iostream>
#include "Fibonacci.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define Num   30

int main(int argc, char** argv) {
	
	Fibonacci *F = new Fibonacci();
	
	if(F != NULL)
	{
		for(int tindex = 0; tindex<Num; tindex++)
		{
			printf("\n F[%d] = %d \n", tindex, F->Start(tindex));
		}
		
		delete(F);
	}

	return 0;
}
