#include <iostream>
#include "CodeScaner.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	CodeScaner *C = new CodeScaner();
	char abc[] = "int main(int argc, char** argv)() {CodeScaner *C = new CodeScaner();char abc[] = ""delete(C); printf(\"\\n Func End ! \\n\\n\");return 0;}";
	C->StarScan(abc);
	delete(C);
	printf("\n Func End ! \n\n");
	return 0;
}
