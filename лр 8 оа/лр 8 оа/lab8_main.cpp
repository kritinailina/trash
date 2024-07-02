#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include "DIalog.h"
#include <iostream>
using namespace std;
int main()
{
	List v(10);//Создаем вектор
	v.Add();//добавляем объект в вектор
	v.Add(); //добавляем объект в вектор
	v.Show();//вывод вектора
	v.Del();//удаление элемента
	cout << "\nVector size=" << v();
	Dialog D;
	D.Execute();
}
