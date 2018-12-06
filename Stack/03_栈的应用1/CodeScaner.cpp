#include "CodeScaner.h"
#include "LinkStack.cpp"


MatchPair CodeScaner::MP[] = 
{
	{'(', ')'},
	{'[', ']'},
	{'{', '}'},
	{'<', '>'},
	{'\'', '\''},
	{'\"', '\"'},
};

char CodeScaner::LC[] = 
{
	'(',
	'[',
	'{',
	'<',
	'\'',
	'\"',
};

char CodeScaner::RC[] = 
{
	')',
	']',
	'}',
	'>',
	'\'',
	'\"',
};

CodeScaner::CodeScaner(void)
{
	L = new LinkStack<char>();
}

CodeScaner::~CodeScaner(void)
{
	if(L != NULL)
	{
		delete(L);
		L = NULL;
	}
}

bool CodeScaner::IsLeft(char L)
{
	
}

bool CodeScaner::IsRight(char R)
{

}

bool CodeScaner::IsMatch(char L, char R)
{
	
}

bool CodeScaner::StarScan(const char* code)
{

}


