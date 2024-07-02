#include "C:\Users\Кристина\source\repos\лр 11 оа\задача 2\Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
	Vector<Money>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	Money s = vec.min();
	cout << "pos?";
	int p; cin >> p;
	vec.add_vector(s, p);//добавить элемент в вектор
	vec.Print();//печать вектора
	vec.avarage();//найти максимальный элемент
	vec.del_vector();//удаление
	vec.Print();//печать
	vec.multiplication();
	vec.Print();//печать
}
