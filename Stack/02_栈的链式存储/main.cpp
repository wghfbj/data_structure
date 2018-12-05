#include <iostream>
#include "LinkStack.h"

#include "LinkStack.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	LinkStack<int> *L = new LinkStack<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	
	L->Push_LinkStack(&a);
	L->Push_LinkStack(&b);
	L->Push_LinkStack(&c);
	L->Push_LinkStack(&d);
	L->Push_LinkStack(&e);
	
	printf("\n the Length of LinkStack is %d \n", L->GetLength_LinkStack());
	
	while(L->GetLength_LinkStack() > 0)
	{
		printf("\n Get top of LinkStack is %d \n", L->GetTop_LinkStack());
		printf("\n POP LinkStack is %d \n", L->Pop_LinkStack());
	}

	delete(L); 
	printf("\n Func End ! \n\n");
	return 0;
}
