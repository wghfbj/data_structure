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
	printf("\n ��ǰ���Ľڵ���Ϊ %d \n", B->GetBTreeCount());
	printf("\n ��ǰ���Ķ�Ϊ %d \n", B->GetBTreeDegree());
	printf("\n ��ǰ���ĸ߶�Ϊ %d \n", B->GetBTreeHeight());
	B->ShowBTree();
	printf("\n ��ǰ����ǰ�����Ϊ  \n");
	B->Pre_Traversal();
	printf("\n ��ǰ�����������Ϊ  \n");
	B->Mid_Traversal() ;
	printf("\n ��ǰ���ĺ������Ϊ  \n");
	B->Post_Traversal();
	printf("\n ��������ʽ2��Ľ��:  \n");
	B->Thread2_Tree();
	B->ShowThread2_Tree();
	printf("\n ��������ʽ1��Ľ��:  \n");
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
