#include "CodeScaner.h"
#include "LinkStack.cpp"


MatchPair CodeScaner::MP[] = 
{
	{'(', ')'},
	{'[', ']'},
	{'{', '}'},
	{'<', '>'},
	{0, 0},
};

char CodeScaner::LC[] = 
{
	'(',
	'[',
	'{',
	'<',
	0,
};

char CodeScaner::RC[] = 
{
	')',
	']',
	'}',
	'>',
	0, 
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
	bool ret = FALSE;
	int tindex = 0;
	while(LC[tindex] != 0)
	{
		if(L == LC[tindex])
		{
			ret = TRUE;
			break;
		}
		tindex++;
	}
	return ret;
}

bool CodeScaner::IsRight(char R)
{
	bool ret = FALSE;
	int tindex = 0;
	while(RC[tindex] != 0)
	{
		if(R == RC[tindex])
		{
			ret = TRUE;
			break;
		}
		tindex++;
	}
	return ret;
}

bool CodeScaner::IsMatch(char L, char R)
{
	bool ret = FALSE;
	int tindex = 0;
	while(MP[tindex].L != 0)
	{
		if((L == MP[tindex].L) && (R == MP[tindex].R))
		{
			ret = TRUE;
			break;
		}
		tindex++;
	}
	return ret;
}

bool CodeScaner::StarScan(const char* code)
{
	bool ret = FALSE;
	int tindex = 0;
	
	printf("\n Start build ====> %s \n", code);
	
	while(code[tindex] != '\0')
	{
		if(IsLeft(code[tindex]))
		{
			L->Push_LinkStack((char *)&code[tindex]);
		}
		else if(IsRight(code[tindex]))
		{
			char tmp = L->Pop_LinkStack();
			if((tmp == FALSE) || (!IsMatch(tmp, code[tindex])))
			{
				printf("\n[ERROR] compile error1 \n");
				ret = FALSE;
				goto exit;
			}
		}
		tindex++;
	}
	
	if(L->GetLength_LinkStack() != 0)
	{
		printf("\n[ERROR] compile error2 \n");
		ret = FALSE;
	}
	else
	{
		ret = TRUE;
		printf("\n compile Succeed \n");
	}
	
exit:
	return ret;
}


