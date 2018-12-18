#include <iostream>
#include "SelectionSort.h"
#include "SelectionSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	SelectionSort<int> *SS = new SelectionSort<int>(10);
	
	if(SS != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			SS->AddSelectionSort(&tmp, 0);
		}
		SS->ShowSelectionSort();
		SS->StartSort();
		SS->ShowSelectionSort();
		delete(SS);
	}

	return 0;
}
