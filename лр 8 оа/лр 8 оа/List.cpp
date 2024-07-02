#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include <iostream>
using namespace std;
List::~List(void)//деструктор
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
List::List(int n)//конструктор с параметрами
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void List::Add()//добавление объекта, на который указывает указатель p в вектор
{
	Object* p;
	cout << "1.Print" << endl; //выбор из объектов двух возможных классов
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Car
	{
		Print* a = new (Print);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void List::Show()//просмотр вектора
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
}

int List::operator ()()//операция, которая возвращает размер вектора
{
	return cur;
}
void List::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}