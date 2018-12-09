#include <iostream>
#include "Permutation.h"

using std::string;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define Num   50

int main(int argc, char** argv) {
	
	Permutation *P = new Permutation();
	
	if(P != NULL)
	{
		string S = "abcde";
		P->Start((char *)S.c_str(), 0, 4);
		delete(P);
	}

	return 0;
}
