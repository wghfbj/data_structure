#include <iostream>
#include "QuickSort.h"
#include "QuickSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	QuickSort<int> *QQ = new QuickSort<int>(10);
	
	if(QQ != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			QQ->AddQuickSort(&tmp, 0);
		}
		QQ->ShowQuickSort();
		QQ->StartSort();
		QQ->ShowQuickSort();
		delete(QQ);
	}

	return 0;
}
