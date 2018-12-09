#ifndef _HANOI_H_
#define _HANOI_H_

#include <iostream>
#include <string>

#define FALSE  0
#define TRUE   1

/*
Hanoi:
��һ�������A���ƶ���C��
	���� 1 ���Խ���B��
	     2 ������С��������ڴ������֮�� 
*/
class Hanoi
{
public:
	bool Start(int Num, char a, char b, char c);
};




#endif //_HANOI_H_
