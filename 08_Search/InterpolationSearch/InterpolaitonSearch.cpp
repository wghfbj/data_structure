#include "InterpolationSearch.h"
#include "InsertionSort.cpp"


InterpolationSearch::InterpolationSearch(void):InsertionSort<int>::InsertionSort(SearchLength)
{
	InitSearch();
}

InterpolationSearch::~InterpolationSearch()
{
	ClearInsertionSort();
}

void InterpolationSearch::InitSearch()
{
	srand((unsigned int)time(NULL));
	for(int tindex=0; tindex<SearchLength; tindex++)
	{
		int tmp = rand() % 100;
		AddInsertionSort(&tmp, 0);
	}
}

void InterpolationSearch::SearchDisplay()
{
	printf("\n SearchDisplay ===>   ");
	ShowInsertionSort();
	printf("\n");
}

int InterpolationSearch::StaticSearch(void)
{
	int ret = -1;
	int target = rand() % 100;
	StartSort();
	int Start = 0;
	int End = SearchLength-1; 
	while((Start <= End) && (this->GetInsertionSort(Start) <= target) && (this->GetInsertionSort(End) >= target))
	{
		float fx = 1.0f * (target - this->GetInsertionSort(Start)) / (this->GetInsertionSort(End) - this->GetInsertionSort(Start));
		int mid = Start + fx * (End - Start);
		printf("\n mid is %d %d %d \n", Start, mid, End);
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


