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
	B->InsertBTree(&a, 0x0, 0);
	B->InsertBTree(&b, 0x0, 0);
	B->InsertBTree(&c, 0x1, 0);
	B->InsertBTree(&d, 0x0, 1);
	B->InsertBTree(&e, 0x2, 1);
	/*
	                	A
	            B				C
	        D		E
	*/
	printf("\n 当前树的节点数为 %d \n", B->GetBTreeCount());
	printf("\n 当前树的度为 %d \n", B->GetBTreeDegree());
	printf("\n 当前树的高度为 %d \n", B->GetBTreeHeight());
	B->ShowBTree();
	printf("\n 当前树的前序遍历为  \n");
	B->Pre_Traversal();
	printf("\n 当前树的中序遍历为  \n");
	B->Mid_Traversal() ;
	printf("\n 当前树的后序遍历为  \n");
	B->Post_Traversal();
	printf("\n 线索化方式2后的结果:  \n");
	B->Thread2_Tree();
	B->ShowThread2_Tree();
	printf("\n 线索化方式1后的结果:  \n");
	B->Thread1_Tree(B->GetRootBTree());
	TreeNode<char>* tmp = B->GetRootBTree();
	printf("\n");
	while(tmp != NULL)
	{
		printf("%c ", tmp->data);
		tmp = tmp->bLeft;
	}
	printf("\n");
//	B->DeleteBTree(0x0, 1);
//	B->ShowBTree();
	
	delete(B); 
	printf("\n Func End ! \n\n");
	return 0;
}
