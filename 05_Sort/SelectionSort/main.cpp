#include <iostream>
#include "SelectionSort.h"
#include "SelectionSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	SelectionSort<int> *SS = new SelectionSort<int>(10);
	
	if(SS != NULL)
	{
		delete(SS);
	}

	return 0;
}
