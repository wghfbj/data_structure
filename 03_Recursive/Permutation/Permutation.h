#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include <iostream>
#include <string>

#define FALSE  0
#define TRUE   1

/*
Permutation:
全排列
	规则: 将全部字符串按照顺序排列一次
	举例 a b c 三个字符串的全排列就是
	abc
	acb
	bac
	bca
	cab
	cba 
*/
class Permutation
{
public:
	bool Start(char *C, int Begin, int End);
};




#endif //_PERMUTATION_H_
