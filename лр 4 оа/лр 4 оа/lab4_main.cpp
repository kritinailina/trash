#include <iostream>
#include "Triad.h"
#include "Date.h"
using namespace std;

//функция принимает объект базового класса как параметр
void f1(Triad& c)
{
	c.Set_first(789);
	cout << c;
}
//функция возвращает объект базового класса как результат
Triad f2()
{
	Date l(13, 5, 2004);
	return l;
}

void main()
{
	Triad a;
	cin >> a;
	cout << a;
	Triad b(163, 4, 115);
	cout << b;
	a = b;
	++b;
	cout << a;
	cout << b;
	Date c;//создать объект
	cin >> c;//ввести значения атрибутов
	c + 4;
	cout << c;//вывести значения атрибутов	f1(c);//передаем объект класса Lorry
	a = f2();//создаем в функции объект класса Lorry
	cout << a;
}