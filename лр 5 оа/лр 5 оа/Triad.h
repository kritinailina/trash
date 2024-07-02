#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;
class Triad :
	public Object
{
public:
	Triad(void); //конструктор без параметров
public:
	virtual ~Triad(void); //деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	Triad(int, int, int); //констрктор с параметрами
	Triad(const Triad&); //конструктор копирования
	//селекторы
	int Get_first() { return first; }
	int Get_second() { return second; }
	int Get_third() { return third; }
	//модификаторы
	void Set_first(int);
	void Set_second(int);
	void Set_third(int);
	Triad& operator++();
	Triad& operator=(const Triad&); //перегрузка операции присваивания
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Triad& t);
	friend ostream& operator<<(ostream& out, const Triad& t);
	//атрибуты
protected:
	int first;
	int second;
	int third;
};
