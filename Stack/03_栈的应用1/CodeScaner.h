#ifndef _CODE_SCANER_H_
#define _CODE_SCANER_H_

#include "LinkStack.h"

typedef struct
{
	char L;
	char R;

} MatchPair;

class CodeScaner
{
public:
	CodeScaner(void);
	~CodeScaner(void);
	
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


#endif  //_CODE_SCANER_H_
