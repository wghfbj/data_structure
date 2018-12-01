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
	//========Show Cyclelist
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetCyclelist(4));
	printf("\n Get Index[%d] value = %d \n", 5, (int)L->GetCyclelist(5));
	printf("\n Get Index[%d] value = %d \n", 6, (int)L->GetCyclelist(6));
	printf("\n Get Index[%d] value = %d \n", 7, (int)L->GetCyclelist(7));
	printf("\n Get Index[%d] value = %d \n", 8, (int)L->GetCyclelist(8));
	printf("\n Get Index[%d] value = %d \n", 9, (int)L->GetCyclelist(9));
	printf("\n Get Index[%d] value = %d \n", 10, (int)L->GetCyclelist(10));
	printf("\n Get Index[%d] value = %d \n", 11, (int)L->GetCyclelist(11));
	printf("\n Get Index[%d] value = %d \n", 12, (int)L->GetCyclelist(12));
	printf("\n Get Index[%d] value = %d \n", 13, (int)L->GetCyclelist(13));
	//========Show Cyclelist end
	printf("\n Delete Index[%d] value = %d \n", 3, (int)L->DeleteCyclelist(3));
	printf("\n 22 Get Cyclelist length = %d \n", (int)L->GetCyclelistLength());
	//========Show Cyclelist
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetCyclelist(4));
	printf("\n Get Index[%d] value = %d \n", 5, (int)L->GetCyclelist(5));
	printf("\n Get Index[%d] value = %d \n", 6, (int)L->GetCyclelist(6));
	printf("\n Get Index[%d] value = %d \n", 7, (int)L->GetCyclelist(7));
	printf("\n Get Index[%d] value = %d \n", 8, (int)L->GetCyclelist(8));
	printf("\n Get Index[%d] value = %d \n", 9, (int)L->GetCyclelist(9));
	printf("\n Get Index[%d] value = %d \n", 10, (int)L->GetCyclelist(10));
	printf("\n Get Index[%d] value = %d \n", 11, (int)L->GetCyclelist(11));
	printf("\n Get Index[%d] value = %d \n", 12, (int)L->GetCyclelist(12));
	printf("\n Get Index[%d] value = %d \n", 13, (int)L->GetCyclelist(13));
	//========Show Cyclelist end
	L->ShowCyclelist();
	printf("\n Func End ! \n\n");
	return 0;
}
