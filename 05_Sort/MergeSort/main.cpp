#include <iostream>
#include "MergeSort.h"
#include "MergeSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	MergeSort<int> *SS = new MergeSort<int>(10);
	
	if(SS != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			SS->AddMergeSort(&tmp, 0);
		}
		SS->ShowMergeSort();
		SS->StartSort();
		SS->ShowMergeSort();
		delete(SS);
	}

	return 0;
}
