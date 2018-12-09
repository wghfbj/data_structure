#ifndef _HANOI_H_
#define _HANOI_H_

#include <iostream>
#include <string>

#define FALSE  0
#define TRUE   1

/*
Hanoi:
将一串物体从A柱移动到C柱
	规则 1 可以借助B柱
	     2 必须是小的物体摆在大的物体之上 
*/
class Hanoi
{
public:
	bool Start(int Num, char a, char b, char c);
};




#endif //_HANOI_H_
