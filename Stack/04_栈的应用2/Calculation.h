#ifndef _CALCULATION_H_
#define _CALCULATION_H_

#include "LinkStack.h"

typedef struct
{
	char L;
	char R;

} MatchPair;

class Calculation
{
public:
	Calculation(void);
	~Calculation(void);
	
	bool IsLeft(char L);
	bool IsRight(char R);
	bool IsMatch(char L, char R);
	bool StarScan(const char* code);
	
	static MatchPair MP[];
	static char LC[];
	static char RC[];
	
private:
	LinkStack<char> *L;
};


#endif  //_CALCULATION_H_
