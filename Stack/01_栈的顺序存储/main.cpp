#include <iostream>
#include "SeqStack.h"

#include "SeqStack.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	SeqStack<int> *S = new SeqStack<int>(10);
	int a = 1;
	int b = 2;
	int c = 3;

	delete(S);
	return 0;
}
