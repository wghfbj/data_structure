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
/*����:
1,��������:��ջ
2,���ڷ���:
   ��ջ�е����Ҳ�����
   ��ջ�е����������
   ���ݷ��Ž�������
   �����ѹ��ջ��
3,���������� ջ�е�Ψһ����Ϊ������ 
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
����:
1,�������� ֱ�����
2,���ڷ���
    ������  ��ջ
	������  ��ջ�����ŵ�������� ֱ��ƥ�䵽������
	���� ��ջ���������ȼ����бȽ�
		ջ���������ȼ���   �˷��Ž�ջ
		ջ���������ȼ�����  ��ջ�����ŵ�������� ֮��˷��Ž�ջ
3,���������� ��ջ�е����еķ��ŵ���������� 
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

