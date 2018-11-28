#include <iostream>
#include "Seqlist.h"

#include "Seqlist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Seqlist<int> *S = new Seqlist<int>(10);
	int a = 1;
	int b = 2;
	int c = 3;
	S->AddSeqlist(&a, 0);
	S->AddSeqlist(&b, 0);
	S->AddSeqlist(&c, 0);
	S->ShowSeqlist();
	S->DeleteSeqlist(0);
	S->ShowSeqlist();
	delete(S);
	return 0;
}
