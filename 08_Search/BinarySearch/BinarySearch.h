#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "InsertionSort.h"

#define SearchLength  20

class BinarySearch : public InsertionSort<int>
{
public:
	BinarySearch(void);
	~BinarySearch();
	int StaticSearch(void);
	void SearchDisplay(void);
	int RecursiveSearch(int Start, int End, int target);
	
private:
	void InitSearch(void);
	
};

#endif //__BINARYSEARCH_H__
