#include <iostream>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>Vec;//определяем тип для работы с вектором
Vec make_vector(int n)//функция для формирования вектора
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++) {
		Money a(rand() % 60, rand() % 60);
		v.push_back(a);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
void print_vector(Vec v)//функция для печати вектора
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
Money avarage(Vec v)//вычисление среднего арифметического
{
	Money s;
	for (int i = 0; i < v.size(); i++)
		s = v[i] + s;
	int n = v.size();
	return s / n;
}
Money min(Vec v)//поиск минимального элемента
{
	Money m = v[0];//минимальный элемент
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i]) {
			m = v[i];//минимальный элемент
		}
	return m;
}
void add_vector(Vec& v, Money el, int pos)//добавляем на место pos элемент el
{
	v.insert(v.begin() + pos, el);
}
void del_vector(Vec& v)//удалить
{
	int p = 0; Money a = avarage(v);
	while (p < v.size())
	{
		auto iter = v.cbegin();
		if (v[p] > a)
		{
			v.erase(iter+p);
		}
		else
		{
			p++;
		}
	}
}
int max(Vec v)//поиск максимального элемента
{
	Money m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
			n = i;
		}
	return n;
}
void multiplication(Vec& v)
{
	int m = max(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * v[m];
}
int main()
{
	try
	{
		vector<Money> v;//вектор
		vector<Money>::iterator vi = v.begin();//итератор
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);//формирование вектора
		print_vector(v);//печать вектора
		Money el = min(v);
		cout << "pos?"; //позиция для вставки
		int pos;
		cin >> pos;
		if (pos > v.size())throw 1;
		add_vector(v, el, pos); //вызов функции для добавления
		print_vector(v); //печать вектора
		del_vector(v);//удалить
		print_vector(v);
		multiplication(v);//
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}