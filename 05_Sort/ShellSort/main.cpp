#include <iostream>
#include "ShellSort.h"
#include "ShellSort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ShellSort<int> *SS = new ShellSort<int>(10);
	
	if(SS != NULL)
	{
		for(int tindex = 0; tindex<10; tindex++)
		{
			int tmp = tindex;
			SS->AddShellSort(&tmp, 0);
		}
		SS->ShowShellSort();
		SS->StartSort();
		SS->ShowShellSort();
		delete(SS);
	}

	return 0;
}
