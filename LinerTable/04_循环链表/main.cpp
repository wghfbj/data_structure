#include <iostream>
#include "Cyclelist.h"

#include "Cyclelist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Cyclelist<int> *L = new Cyclelist<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->AddCyclelist(&a, 0);
	L->AddCyclelist(&b, 0);
	L->AddCyclelist(&c, 0);
	L->AddCyclelist(&d, 0);
	L->AddCyclelist(&e, 0);
	printf("\n 11 Get Cyclelist length = %d \n", (int)L->GetCyclelistLength());
	L->ShowCyclelist();
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetCyclelist(4));
	printf("\n Delete Index[%d] value = %d \n", 3, (int)L->DeleteCyclelist(3));
	printf("\n 22 Get Cyclelist length = %d \n", (int)L->GetCyclelistLength());
	L->ShowCyclelist();
	printf("\n Func End ! \n\n");
	return 0;
}
