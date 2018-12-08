#include <iostream>
#include "Calculation.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Calculation *C = new Calculation();
	char Demo[100] = "2+(3-1)*3";
	C->Start(Demo);
	delete(C);
	printf("\n Func End ! \n\n");
	return 0;
}
