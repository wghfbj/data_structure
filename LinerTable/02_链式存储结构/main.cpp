#include <iostream>
#include "Linklist.h"

#include "Linklist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Linklist<int> *L = new Linklist<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->AddLinklist(&a, 0);
	L->AddLinklist(&b, 0);
	L->AddLinklist(&c, 0);
	L->AddLinklist(&d, 0);
	L->AddLinklist(&e, 0);
	printf("\n 11 Get Linklist length = %d \n", (int)L->GetLinklistLength());
	L->ShowLinklist();
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetLinklist(4));
	printf("\n Delete Index[%d] value = %d \n", 2, (int)L->DeleteLinklist(2));
	printf("\n 22 Get Linklist length = %d \n", (int)L->GetLinklistLength());
	L->ShowLinklist();
	printf("\n\n Clear LinkList \n");
	L->ClearLinklist(); 
	L->ShowLinklist();
	delete(L); 
	printf("\n Func End ! \n\n");
	return 0;
}
