#pragma once
#include "Triad.h"
class Date :
	public Triad
{
public:
	Date(void);//конструктор без параметров
public:
	~Date(void);//деструктор
	Date(int, int, int);//конструктор с параметрами
	Date(const Date&);//конструктор копирования
	Date& operator+(int);
	Date& operator=(const Date&);//операция присваивания
	friend istream& operator>>(istream& in, Date& d);//операция ввода
	friend ostream& operator<<(ostream& out, const Date& l); //операция вывода
};
