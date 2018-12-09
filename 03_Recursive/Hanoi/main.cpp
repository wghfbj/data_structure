#include <iostream>
#include "Hanoi.h"

using std::string;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define Num   1000

int main(int argc, char** argv) {
	
	Hanoi *S = new Hanoi();
	
	if(S != NULL)
	{
		S->Start(Num, 'a', 'b', 'c');
		delete(S);
	}

	return 0;
}
