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

	delete(L); 
	printf("\n Func End ! \n\n");
	return 0;
}
