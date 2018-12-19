#include <iostream>
#include "InsertionSort.h"
#include "InsertionSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	InsertionSort<int> *SS = new InsertionSort<int>(10);
	
	if(SS != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			SS->AddInsertionSort(&tmp, 0);
		}
		SS->ShowInsertionSort();
		SS->StartSort();
		SS->ShowInsertionSort();
		delete(SS);
	}

	return 0;
}
