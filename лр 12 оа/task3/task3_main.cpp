#include "C:\Users\Кристина\source\repos\лр 11 оа\задача 2\Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "N?"; cin >> n;//количество элементов
	Vector<multimap<int, Money>> m(n);
	m.Print();//напечатать словарь
	m.Min(); m.Print(); cout << "\n";
	m.Del(); m.Print(); cout << "\n";
	m.multiplication(); m.Print();
}
