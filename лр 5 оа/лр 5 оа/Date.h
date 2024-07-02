#pragma once
#include "Triad.h"
class Date :
	public Triad
{
public:
	Date(void);//����������� ��� ����������
public:
	~Date(void);//����������
	void Show();
	Date(int, int, int);//����������� � �����������
	Date(const Date&);//����������� �����������
	Date& operator+(int);
	Date& operator=(const Date&);//�������� ������������
	friend istream& operator>>(istream& in, Date& d);//�������� �����
	friend ostream& operator<<(ostream& out, const Date& l); //�������� ������
};
