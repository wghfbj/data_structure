#include <iostream>
#include "BubbleSort.h"
#include "BubbleSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	BubbleSort<int> *SS = new BubbleSort<int>(10);
	
	if(SS != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			SS->AddBubbleSort(&tmp, 0);
		}
		SS->ShowBubbleSort();
		SS->StartSort();
		SS->ShowBubbleSort();
		delete(SS);
	}

	return 0;
}
