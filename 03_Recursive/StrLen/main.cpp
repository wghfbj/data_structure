#include <iostream>
#include "StrLen.h"

using std::string;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define Num   30

int main(int argc, char** argv) {
	
	StrLen *S = new StrLen();
	
	if(S != NULL)
	{
		string Str = "11111sagasdlawjglaksdkaojgoafsfagw4448819922222222";
		printf("\n\n Str[%s] Lenght = %d \n", Str.c_str(), S->Start(Str.c_str()));
		delete(S);
	}

	return 0;
}
