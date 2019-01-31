#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SearchLength  20

class BinarySearch
{
public:
	int Num[SearchLength+1];
	
public:
	BinarySearch();
	~BinarySearch();
	int StaticSearch(void);
	void SearchDisplay(void);
	
private:
	void InitSearch(void);
};

#endif //__BINARYSEARCH_H__
