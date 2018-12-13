#ifndef _BACKTRACK_H_
#define _BACKTRACK_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
BackTrace
回溯算法 八皇后问题
规则  在一个8*8的国际棋盘上 有8个皇后 每个皇后占一格 要求皇后之间不会出现互相攻击的现象 即不能有两个皇后处在同一行 同一列或同一对角线上
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
