#ifndef _CALCULATION_H_
#define _CALCULATION_H_

#include "LinkStack.h"

class Calculation
{
public:
	Calculation(void);
	~Calculation(void);
	
	int StartCalculate(void);
	bool StartConvert(const char* Rule);
	bool Start(const char* Rule);
	
private:
	bool IsNumber(char Num);
	bool IsMark(char Mar);
	bool IsLeft(char Lef);
	bool IsRight(char Rig);
	bool IsLower(char L, char R);
	int ConvertChar2Num(char Mar);
	char ConvertNum2Char(int Num);
	int Calculate(int Left, int Right, char Mar);
	
private:
	LinkStack<char> *L;
	char* Container;
	int Length;
};


#endif  //_CALCULATION_H_
