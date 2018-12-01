#include <iostream>
#include "Staticlist.h"

#include "Staticlist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	//Insert interface index start at 0!
	Staticlist<int> *L = new Staticlist<int>(10);
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->AddStaticlist(&a, 0);
	L->AddStaticlist(&b, 0);
	L->AddStaticlist(&c, 0);
	L->AddStaticlist(&d, 0);
	L->AddStaticlist(&e, 0);
	printf("\n\n  111 GetMaxLength = %d \n\n", L->GetStaticlistMaxLength());
	printf("\n\n  222 GetLength = %d \n\n", L->GetStaticlistLength());
	L->ShowStaticlist();
	L->DeleteStaticlist(2);
	printf("\n\n  333 GetLength = %d \n\n", L->GetStaticlistLength());
	L->ShowStaticlist();
	printf("\n Func End ! \n\n");
	return 0;
}
