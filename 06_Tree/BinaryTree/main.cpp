#include <iostream>
#include "BTree.h"

#include "BTree.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	BTree<char> *B = new BTree<char>();
	char a = 'A';
	char b = 'B';
	char c = 'C';
	char d = 'D';
	char e = 'E';
	B->InsertBTree(&a, 0);
	B->InsertBTree(&b, 0);
	B->InsertBTree(&c, 0);
	B->InsertBTree(&d, 1);
	B->InsertBTree(&e, 3);
	printf("\n 当前树的节点数为 %d \n", B->GetBTreeCount());
	printf("\n 当前树的度为 %d \n", B->GetBTreeDegree());
	printf("\n 当前树的高度为 %d \n", B->GetBTreeHeight());
	B->ShowBTree();
	B->DeleteBTree(1);
	B->ShowBTree();
	
	delete(B); 
	printf("\n Func End ! \n\n");
	return 0;
}
