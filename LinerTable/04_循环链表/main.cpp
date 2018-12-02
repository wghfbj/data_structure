#include <iostream>
#include "Cyclelist.h"

#include "Cyclelist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Cyclelist<int> *L = new Cyclelist<int>();
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	L->AddCyclelist(&a, 0);
	L->AddCyclelist(&b, 0);
	L->AddCyclelist(&c, 0);
	L->AddCyclelist(&d, 0);
	L->AddCyclelist(&e, 0);
	printf("\n 11 Get Cyclelist length = %d \n", (int)L->GetCyclelistLength());
	//L->ShowCyclelist();
	//========Show Cyclelist
//	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetCyclelist(4));
//	printf("\n Get Index[%d] value = %d \n", 5, (int)L->GetCyclelist(5));
//	printf("\n Get Index[%d] value = %d \n", 6, (int)L->GetCyclelist(6));
//	printf("\n Get Index[%d] value = %d \n", 7, (int)L->GetCyclelist(7));
//	printf("\n Get Index[%d] value = %d \n", 8, (int)L->GetCyclelist(8));
//	printf("\n Get Index[%d] value = %d \n", 9, (int)L->GetCyclelist(9));
//	printf("\n Get Index[%d] value = %d \n", 10, (int)L->GetCyclelist(10));
//	printf("\n Get Index[%d] value = %d \n", 11, (int)L->GetCyclelist(11));
//	printf("\n Get Index[%d] value = %d \n", 12, (int)L->GetCyclelist(12));
//	printf("\n Get Index[%d] value = %d \n", 13, (int)L->GetCyclelist(13));
	//========Show Cyclelist end
	printf("\n Delete Index[%d] value = %d \n", 3, (int)L->DeleteCyclelist(3));
	printf("\n 22 Get Cyclelist length = %d \n", (int)L->GetCyclelistLength());
	//========Show Cyclelist
//	printf("\n Get Index[%d] value = %d \n", 4, (int)L->GetCyclelist(4));
//	printf("\n Get Index[%d] value = %d \n", 5, (int)L->GetCyclelist(5));
//	printf("\n Get Index[%d] value = %d \n", 6, (int)L->GetCyclelist(6));
//	printf("\n Get Index[%d] value = %d \n", 7, (int)L->GetCyclelist(7));
//	printf("\n Get Index[%d] value = %d \n", 8, (int)L->GetCyclelist(8));
//	printf("\n Get Index[%d] value = %d \n", 9, (int)L->GetCyclelist(9));
//	printf("\n Get Index[%d] value = %d \n", 10, (int)L->GetCyclelist(10));
//	printf("\n Get Index[%d] value = %d \n", 11, (int)L->GetCyclelist(11));
//	printf("\n Get Index[%d] value = %d \n", 12, (int)L->GetCyclelist(12));
//	printf("\n Get Index[%d] value = %d \n", 13, (int)L->GetCyclelist(13));
	//========Show Cyclelist end
	L->ShowCyclelist();
	delete(L); 
	
	
	//Demo解决约瑟夫问题
	printf("\n\n Start 约瑟夫问题 Demo \n\n");
	Cyclelist<int> *L1 = new Cyclelist<int>();
	int a1 = 1;
	int b1 = 2;
	int c1 = 3;
	int d1 = 4;
	int e1 = 5;
	int f1 = 6;
	int g1 = 7;
	int h1 = 8;
	L1->AddCyclelist(&a1, 0);
	L1->AddCyclelist(&b1, 1);
	L1->AddCyclelist(&c1, 2);
	L1->AddCyclelist(&d1, 3);
	L1->AddCyclelist(&e1, 4);
	L1->AddCyclelist(&f1, 5);
	L1->AddCyclelist(&g1, 6);
	L1->AddCyclelist(&h1, 7);
	printf("\n 11 Get Cyclelist length = %d \n", (int)L1->GetCyclelistLength());
	L1->ShowCyclelist();

	LinkNode<int> *tNode = L1->GetSlider_Currnt();

	while(L1->GetCyclelistLength() != 0)
	{
		for(int tindex=0; tindex<3; tindex++)
		{
			tNode = L1->SetSlider_Next();
		}

		printf("\n Get tNode = %d  \n", tNode->data);
		L1->DeleteNode(tNode);
		L1->ShowCyclelist();
	}
	
	
	delete(L1); 
	printf("\n Func End ! \n\n");
	return 0;
}
