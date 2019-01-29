#include "SearchDemo.h"


SearchDemo::SearchDemo(void)
{
	InitSearch();
}

SearchDemo::~SearchDemo()
{
	for(int tindex; tindex<SearchLength; tindex++)
	{
		Num[tindex] = 0;
	}
}

void SearchDemo::InitSearch()
{
	srand((unsigned int)time(NULL));
	for(int tindex=0; tindex<SearchLength; tindex++)
	{
		Num[tindex] = rand() % 100;
	}
}

void SearchDemo::SearchDisplay()
{
	printf("\n SearchDisplay ===>   ");
	for(int tindex=0; tindex<SearchLength; tindex++)
	{
		printf("%d ", Num[tindex]);
	}
	printf("\n");
}

int SearchDemo::StaticSearch(void)
{
	int ret = rand() % 100;
	SearchDisplay();
	for(int tindex=0; tindex<SearchLength; tindex++)
	{
		if(ret == Num[tindex])
		{
			printf("\n Search succeed! ret = %d index = %d\n", ret, tindex);
			return ret;
		}
	}
	printf("\n Search Faild! ret = %d \n", ret);
	return ret;
}


