#pragma once
#include "Object.h"
#include "Event.h"
class List
{
public:
	List(int);//����������� � �����������
public:
	~List(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	int operator()();//������ �������
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};
