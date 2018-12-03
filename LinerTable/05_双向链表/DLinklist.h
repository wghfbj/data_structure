#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include <stdio.h>
#include <memory.h>
#include <stddef.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//typedef int TDLinklist;


//=============LinkNode
template <class TDLinklist>
class LinkNode
{
public:
	LinkNode(TDLinklist data);
	TDLinklist data;
	LinkNode *NextNode;
	LinkNode *PreNode;
};


//=============DLinklist
template <class TDLinklist>
class DLinklist : public LinkNode<TDLinklist>
{
public:
	DLinklist(void);  //�������Ա� 
	~DLinklist();   //�������Ա� 
	int ClearDLinklist();  //������Ա�
	TDLinklist DeleteDLinklist(unsigned int index); //ɾ�����Ա��е�Ԫ��
	TDLinklist AddDLinklist(TDLinklist *data, unsigned int index); //�����Ա��е�ĳ��λ�����Ԫ�� 
	TDLinklist GetDLinklist(unsigned int index); //��ȡ���Ա���ĳ��λ�õ�Ԫ��
	int GetDLinklistLength(void); //��ȡ���Ա�ǰ�����ݳ���
	void ShowDLinklist(void);
	
	//�α���������
	LinkNode<TDLinklist> *GetSlider_Currnt(void);
	LinkNode<TDLinklist> *SetSlider_Next(void);
	LinkNode<TDLinklist> *SetSlider_Pre(void);
	bool SetSlider_Reset(void);
	LinkNode<TDLinklist> *DeleteNode(LinkNode<TDLinklist>* data); 

private:
	int Length;
	LinkNode<TDLinklist> *Slider;
};


#endif //_DLINKLIST_H_
