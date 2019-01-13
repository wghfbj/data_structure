#include <iostream>
#include "Tree.h"

#include "Tree.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Tree<char> *T = new Tree<char>();
	char a = 'A';
	char b = 'B';
	char c = 'C';
	char d = 'D';
	char e = 'E';
	T->InsertTree(&a, 0);
	T->InsertTree(&b, 0);
	T->InsertTree(&c, 0);
	T->InsertTree(&d, 1);
	T->InsertTree(&e, 3);
	printf("\n 当前树的节点数为 %d \n", T->GetTreeCount());
	printf("\n 当前树的度为 %d \n", T->GetTreeDegree());
	printf("\n 当前树的高度为 %d \n", T->GetTreeHeight());
	T->ShowTree();
	T->DeleteTree(1);
	T->ShowTree();
	
	delete(T); 
	printf("\n Func End ! \n\n");
	return 0;
}
