#include <iostream>
#include "SeqStack.h"

#include "SeqStack.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	SeqStack<int> *S = new SeqStack<int>(10);
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	
	S->Push_SeqStack(&a);
	S->Push_SeqStack(&b);
	S->Push_SeqStack(&c);
	S->Push_SeqStack(&d);
	S->Push_SeqStack(&e);
	S->Push_SeqStack(&f);
	
	printf("\n the MaxLength is %d \n", S->GetMaxLength_SeqStack()); 
	
	while(S->GetLength_SeqStack() > 0)
	{
		printf("\n Get Top Stack is %d \n", (int)S->GetTop_SeqStack());
		printf("\n Pop_SeqStack = %d Length = %d \n", (int)S->Pop_SeqStack(), S->GetLength_SeqStack());
	}

	delete(S);
	return 0;
}
