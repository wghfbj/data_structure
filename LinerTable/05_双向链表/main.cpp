#include <iostream>
#include "DLinklist.h"

#include "DLinklist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	DLinklist<int> *L = new DLinklist<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->AddDLinklist(&a, 0);
	L->AddDLinklist(&b, 0);
	L->AddDLinklist(&c, 0);
	L->AddDLinklist(&d, 0);
	L->AddDLinklist(&e, 0);
	printf("\n 11 Get DLinklist length = %d \n", (int)L->GetDLinklistLength());
	L->ShowDLinklist();
	printf("\n 11 Get Current Slider = %d \n", (int)L->GetSlider_Currnt()->data);
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetDLinklist(4));
	printf("\n Delete Index[%d] value = %d \n", 3, (int)L->DeleteDLinklist(3));
	printf("\n 22 Get DLinklist length = %d \n", (int)L->GetDLinklistLength());
	L->ShowDLinklist();
	L->DeleteNode(L->SetSlider_Pre());
	printf("\n Delete Slider Pre Node \n");
	L->ShowDLinklist();
	delete(L); 
	printf("\n Func End ! \n\n");
	return 0;
}
