#include <iostream>
#include "BSTree.h"

#include "BSTree.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	BSTree<int> *BS = new BSTree<int>();
	
	int a = 3;
	int b = 4;
	int c = 1;
	int d = 2;
	int e = 7;
	BS->InsertBSTree(&a);
	BS->InsertBSTree(&b);
	BS->InsertBSTree(&c);
	BS->InsertBSTree(&d);
	BS->InsertBSTree(&e);
	/*
	                	A
	            B				C
	        D		E
	*/
	printf("\n ��ǰ���Ľڵ���Ϊ %d \n", BS->GetBSTreeCount());
	printf("\n ��ǰ���Ķ�Ϊ %d \n", BS->GetBSTreeDegree());
	printf("\n ��ǰ���ĸ߶�Ϊ %d \n", BS->GetBSTreeHeight());
	BS->ShowBSTree();
	//BS->DeleteBSTree(1);
	//BS->ShowBSTree();
	
	
	delete(BS); 
	printf("\n Func End ! \n\n");
	return 0;
}
