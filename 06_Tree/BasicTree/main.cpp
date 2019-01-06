#include <iostream>
#include "Tree.h"

#include "Tree.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Tree<int> *L = new Tree<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->InsertTree(&a, 0);
	L->InsertTree(&b, 0);
	L->InsertTree(&c, 0);
	L->InsertTree(&d, 0);
	L->InsertTree(&e, 0);
	printf("\n 11 Get Tree Height = %d \n", (int)L->GetTreeHeight());
	L->ShowTree();
	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetTree(4));
	printf("\n Delete Index[%d] value = %d \n", 2, (int)L->DeleteTree(2));
	printf("\n 22 Get Tree Height = %d \n", (int)L->GetTreeHeight());
	L->ShowTree();
	printf("\n\n Clear Tree \n");
	L->ClearTree(); 
	L->ShowTree();
	delete(L); 
	printf("\n Func End ! \n\n");
	return 0;
}
