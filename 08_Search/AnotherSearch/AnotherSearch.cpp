#include "AnotherSearch.h"


AnotherSearch::AnotherSearch(void)
{
	InitSearch();
}

AnotherSearch::~AnotherSearch()
{
	for(int tindex=0; tindex<SearchLength+1; tindex++)
	{
		Num[tindex] = 0;
	}
}

void AnotherSearch::InitSearch()
{
	srand((unsigned int)time(NULL));
	for(int tindex=1; tindex<SearchLength; tindex++)
	{
		Num[tindex] = rand() % 100;
	}
}

void AnotherSearch::SearchDisplay()
{
	printf("\n SearchDisplay ===>   ");
	for(int tindex=1; tindex<SearchLength; tindex++)
	{
		printf("%d ", Num[tindex]);
	}
	printf("\n");
}

int AnotherSearch::StaticSearch(void) //对比SearchDemo来说,这个算法的比较步骤少了一半 
{
	int ret = SearchLength+1;
	Num[0] = rand() % 100;
	SearchDisplay();
	
	while(Num[0] != Num[ret])
	{
		ret--;
	}
	
	if(ret == 0)
	{
		printf("\n Search Faild! ret = %d \n", ret);
	}
	else
	{
		printf("\n Search succeed! ret = %d index = %d\n", Num[0], ret);
	}

	return ret;
}


