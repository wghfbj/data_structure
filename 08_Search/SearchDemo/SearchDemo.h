#ifndef __SEARCHDEMO_H__
#define __SEARCHDEMO_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SearchLength  20

class SearchDemo
{
public:
	int Num[SearchLength];
	
public:
	SearchDemo();
	~SearchDemo();
	int StaticSearch(void);
	void SearchDisplay(void);
	
private:
	void InitSearch(void);
};

#endif //__SEARCHDEMO_H__
