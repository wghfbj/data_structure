#ifndef __ANOTHERSEARCH_H__
#define __ANOTHERSEARCH_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SearchLength  20

class AnotherSearch
{
public:
	int Num[SearchLength+1];
	
public:
	AnotherSearch();
	~AnotherSearch();
	int StaticSearch(void);
	void SearchDisplay(void);
	
private:
	void InitSearch(void);
};

#endif //__ANOTHERSEARCH_H__
