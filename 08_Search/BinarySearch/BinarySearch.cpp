#include "BinarySearch.h"
#include "InsertionSort.cpp"


BinarySearch::BinarySearch(void):InsertionSort<int>::InsertionSort(SearchLength)
{
	InitSearch();
}

BinarySearch::~BinarySearch()
{
	ClearInsertionSort();
}

void BinarySearch::InitSearch()
{
	srand((unsigned int)time(NULL));
	for(int tindex=0; tindex<SearchLength; tindex++)
	{
		int tmp = rand() % 100;
		AddInsertionSort(&tmp, 0);
	}
}

void BinarySearch::SearchDisplay()
{
	printf("\n SearchDisplay ===>   ");
	ShowInsertionSort();
	printf("\n");
}

int BinarySearch::RecursiveSearch(int Start, int End, int target)
{
	int ret = -1;
	
	if(Start <= End)
	{
		int mid = (Start + End) / 2;
		if(this->GetInsertionSort(mid) == target)
		{
			ret = mid;
		}
		else if(this->GetInsertionSort(mid) < target)
		{
			ret = RecursiveSearch(mid+1, End, target);
		}
		else if(this->GetInsertionSort(mid) > target)
		{
			ret = RecursiveSearch(Start, mid-1, target);
		}
	}
	
	return ret;
}

int BinarySearch::StaticSearch(void)
{
	int ret = -1;
	int target = rand() % 100;
	StartSort();
	#if 0  //使用递归的方式 
	ret = RecursiveSearch(0, SearchLength, target);
	#else  //使用while循环的方式 
	int Start = 0;
	int End = SearchLength;
	while(Start < End)
	{
		int mid = (Start + End) / 2;
		if(this->GetInsertionSort(mid) == target)
		{
			ret = mid;
			break; 
		}
		else if(this->GetInsertionSort(mid) < target)
		{
			Start = mid+1;
		}
		else if(this->GetInsertionSort(mid) > target)
		{
			End = mid-1;
		}
	}
	#endif
	
	SearchDisplay();
	if(ret != -1)
	{
		printf("\n Search Succeed ! target = %d index = %d \n" ,target, ret);
	}
	else
	{
		printf("\n Search Fail target = %d \n" ,target);
	}
	return ret;
}


