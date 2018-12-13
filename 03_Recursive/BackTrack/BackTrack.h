#ifndef _BACKTRACK_H_
#define _BACKTRACK_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
BackTrace
�����㷨 �˻ʺ�����
����  ��һ��8*8�Ĺ��������� ��8���ʺ� ÿ���ʺ�ռһ�� Ҫ��ʺ�֮�䲻����ֻ��๥�������� �������������ʺ���ͬһ�� ͬһ�л�ͬһ�Խ�����
*/

#define FALSE 0
#define TRUE 1

typedef struct
{
	int x;
	int y;
}CheckP;

class BackTrack
{
public:
	BackTrack(int Num);

public:
	int Start(void);
	bool Display(void);
	
private:
	bool CheckValid(int x, int y);
	bool StartFinding(int Start);

private:
	char **P;
	int Size;
};




#endif //_BACKTRACK_H_
