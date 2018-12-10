#include <iostream>
#include "BackTrack.h"

using std::string;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define Num   30

int main(int argc, char** argv) {
	
	BackTrack *S = new BackTrack();
	
	if(S != NULL)
	{
		delete(S);
	}

	return 0;
}
