#include "Calculation.h"
#include "LinkStack.cpp"

#define DEBUG   //printf


Calculation::Calculation(void)
{
	L = new LinkStack<char>();
	Container = NULL;
	Length = 0;
}

Calculation::~Calculation(void)
{
	if(L != NULL)
	{
		delete(L);
		L = NULL;
	}
	if(Container != NULL)
	{
		delete(Container);
		Container = NULL;
	}
}


int Calculation::StartCalculate(void)
{
/*规则:
1,对于数字:进栈
2,对于符号:
   从栈中弹出右操作数
   从栈中弹出左操作数
   根据符号进行运算
   将结果压入栈中
3,遍历结束后 栈中的唯一数据为计算结果 
*/ 
	int ret = FALSE;
	if(L != NULL)
	{
		L->Clear_LinkStack();
	}

	if(Container != NULL)
	{
		int tindex = 0;
		while(Container[tindex] != '\0')
		{
			if(IsNumber(Container[tindex]))
			{
				L->Push_LinkStack((char *)&Container[tindex]);
			}
			else if(IsMark(Container[tindex])) 
			{
				char Mar = Container[tindex];
				int RightNum = ConvertChar2Num(L->Pop_LinkStack());
				int LeftNum = ConvertChar2Num(L->Pop_LinkStack());
				if((LeftNum != -1) && (RightNum != -1))
				{
					char result = ConvertNum2Char(Calculate(LeftNum, RightNum, Mar));
					L->Push_LinkStack((char *)&result);
				}
			}

			tindex++;
		} 
	}
	
	while(L->GetLength_LinkStack() > 0)
	{
		ret = L->Pop_LinkStack();
		printf("\n the calution result is %d \n", ConvertChar2Num(ret));
	}
	
	return ret;
}

bool Calculation::StartConvert(const char* Rule)
{
/*
规则:
1,对于数字 直接输出
2,对于符号
    左括号  进栈
	右括号  将栈顶符号弹出并输出 直到匹配到左括号
	符号 与栈顶符号优先级进行比较
		栈顶符号优先级低   此符号进栈
		栈顶符号优先级不低  将栈顶符号弹出并输出 之后此符号进栈
3,遍历结束后 将栈中的所有的符号弹出并输出· 
*/
	bool ret = FALSE;
	printf("\n StartConvert====>>   ");
	if(Rule != NULL)
	{
		int tindex = 0;
		while(Rule[tindex] != '\0')
		{
			DEBUG("Input=%c ", Rule[tindex]);
			if(IsNumber(Rule[tindex]))
			{
				Container[Length++] = Rule[tindex];
				DEBUG("%c", Rule[tindex]);
			}
			else if(IsMark(Rule[tindex]))
			{
				if(IsLeft(Rule[tindex]))
				{
					L->Push_LinkStack((char *)&Rule[tindex]);
				}
				else if(IsRight(Rule[tindex]))
				{
					while((!IsLeft(L->GetTop_LinkStack())) && (L->GetLength_LinkStack() > 0))
					{
						char tchar = 0;
						tchar = L->Pop_LinkStack();
						Container[Length++] = tchar;
						DEBUG("%c", tchar);
					}
					L->Pop_LinkStack();
				}
				else
				{
					if(IsLower(L->GetTop_LinkStack(), Rule[tindex]))
					{
						L->Push_LinkStack((char*)&Rule[tindex]);
					}
					else
					{
						char tchar = 0;
						if(L->GetLength_LinkStack() > 0)
						{
							tchar = L->Pop_LinkStack();
							Container[Length++] = tchar;
							DEBUG("%c", tchar);
						}
						L->Push_LinkStack((char*)&Rule[tindex]);
					}
				}
			}
			tindex++;
		}
		
		while(L->GetLength_LinkStack() > 0)
		{
			char tchar = 0;
			tchar = L->Pop_LinkStack();
			Container[Length++] = tchar;
			DEBUG("%c", tchar);
		}
		ret = TRUE;
	}
	DEBUG("\n\n");
	
	printf("%s\n\n", Container);
	
	return ret;
}

bool Calculation::Start(const char* Rule)
{
	bool ret = FALSE;
	if(Rule != NULL)
	{
		printf("\n the Rule is =======>>>  %s \n", (char*)Rule);
		while(Rule[Length] != '\0')
		{
			Length++;
		}
	}
	else
	{
		goto exit;
	}

	Container = new char[Length]();
	if(Container != NULL)
	{
		memset(Container, 0, Length);
		Length = 0;
		
		ret = StartConvert(Rule);
		if(ret == TRUE)
		{
			StartCalculate();
		}
	}

exit:
	
	if(Container != NULL)
	{
		delete(Container);
		Container = NULL;
	}
	return ret;
}

bool Calculation::IsNumber(char Num)
{
	bool ret = FALSE;
	if((Num >= '0') && (Num <= '9'))
	{
		ret = TRUE;
	}
	return ret;
}

bool Calculation::IsLeft(char Lef)
{
	bool ret = FALSE;
	if(Lef == '(')
	{
		ret = TRUE;
	}
	return ret;
}

bool Calculation::IsRight(char Rig)
{
	bool ret = FALSE;
	if(Rig == ')')
	{
		ret = TRUE;
	}
	return ret;
}

bool Calculation::IsMark(char Mar)
{
	bool ret = FALSE;
	
	switch(Mar)
	{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
			ret = TRUE;
			break;
		default:
			ret = FALSE;
			break;
	}

	return ret;
}

bool Calculation::IsLower(char L, char R)
{
	bool ret = TRUE;
	switch(R)
	{
		case '+':
		case '-':
			if((L == '*') || (L == '/'))
			{
				ret = FALSE;
			}
			break;
		case '*':
		case '/':
			break;
		default:
			break;
	}

	return ret;
}

int Calculation::ConvertChar2Num(char Mar)
{
	int ret = -1;
	if(IsNumber(Mar))
	{
		ret = Mar - '0';
	}

	return ret;
}

char Calculation::ConvertNum2Char(int Num)
{
	char ret = 0;
	ret = Num + '0';
	return ret;
}

int Calculation::Calculate(int Left, int Right, char Mar)
{
	int ret = 0;
	
	switch(Mar)
	{
		case '+':
			ret = Left + Right;
			break;
		case '-':
			ret = Left - Right;
			break;
		case '*':
			ret = Left * Right;
			break;
		case '/':
			if(Right != 0)
			{
				ret = Left / Right;
			}
			else
			{
				printf("\n[ERROR_%s] Right is zero \n", __FUNCTION__);
			}
			break;
		default:
			printf("\n[ERROR_%s] Invalid Mar\n", __FUNCTION__);
			ret = -1;
			break;
	}
	
	return ret;
}

