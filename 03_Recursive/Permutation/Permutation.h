#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include <iostream>
#include <string>

#define FALSE  0
#define TRUE   1

/*
Permutation:
ȫ����
	����: ��ȫ���ַ�������˳������һ��
	���� a b c �����ַ�����ȫ���о���
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
