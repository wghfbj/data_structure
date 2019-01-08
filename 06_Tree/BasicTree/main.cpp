#include <iostream>
#include "Tree.h"

#include "Tree.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Tree<char> *T = new Tree<char>();
//	int a = 0;
//	int b = 1;
//	int c = 2;
//	int d = 3;
//	int e = 4;
//	T->InsertTree(&a, 0);
//	T->InsertTree(&b, 0);
//	T->InsertTree(&c, 0);
//	T->InsertTree(&d, 0);
//	T->InsertTree(&e, 0);
//	printf("\n 11 Get Tree Height = %d \n", (int)T->GetTreeHeight());
//	T->ShowTree();
//	printf("\n Get Index[%d] value = %d \n", 4, (int)T->GetTree(4));
//	printf("\n Delete Index[%d] value = %d \n", 2, (int)T->DeleteTree(2));
//	printf("\n 22 Get Tree Height = %d \n", (int)T->GetTreeHeight());
//	T->ShowTree();
//	printf("\n\n Clear Tree \n");
//	T->ClearTree(); 
//	T->ShowTree();
	delete(T); 
	printf("\n Func End ! \n\n");
	return 0;
}
