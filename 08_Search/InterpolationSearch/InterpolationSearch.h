#ifndef __INTERPOLATIONSEARCH_H__
#define __INTERPOLATIONSEARCH_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "InsertionSort.h"

#define SearchLength  20

class InterpolationSearch : public InsertionSort<int>
{
public:
	InterpolationSearch(void);
	~InterpolationSearch();
	int StaticSearch(void);
	void SearchDisplay(void);
	
private:
	void InitSearch(void);
	
};

#endif //__INTERPOLATIONSEARCH_H__
