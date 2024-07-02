#include "Print.h"
#include "Event.h"
#include <iostream>
using namespace std;
Print::Print(void)
{
	name = "";
	author = "";
}
Print::~Print(void)//деструктор
{
}
Print::Print(string N, string A)//констрктор с параметрами
{
	name = N;
	author = A;
}
Print::Print(const Print& print)//конструктор копирования
{
	name = print.name;
	author = print.author;
}
void Print::Set_name(string N)//селекторы
{
	name = N;
}
void  Print::Set_author(string A)
{
	author = A;
}
Print& Print::operator=(const Print& p)//оператор присваивания
{
	if (&p == this)return *this;
	name = p.name;
	author = p.author;
	return *this;
}
void Print::Show()//метод для просмотра атрибутов
{
	cout << "Name: " << name;
	cout << "\nAuthor: " << author;
	cout << "\n";
}
void Print::Input()//метод для ввода значений атрибутов
{
	cout << "Name: "; cin >> name;
	cout << "Author: "; cin >> author;
}
void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "Name=" << Get_name() << endl;
			break;
		}
	}
}
