#include "C:\Users\Кристина\source\repos\лр 11 оа\задача 2\Money.h"
#include <iostream>
#include <queue>
#include <vector>
typedef queue <Money> St;
typedef vector<Money>Vec;//вектор
using namespace std;
St make_stack(int n)
{
	St s;
	Money t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод переменной
		s.push(t);//добавление ее в стек
	}
	return s;//вернуть стек как результат функции
}
//копирует стек в вектор
Vec stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.front());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}
void print_stack(St P)
{
	while (!P.empty())
	{
		cout << P.front() << ' ';//вывести первый элемент
		P.pop();//удалить элемент из начала
	}
}
Money avarage(St q)//вычисление среднего арифметического
{
	Money s;
	Vec v = stack_to_vector(q);
	for (int i = 0; i < v.size(); i++)
		s = v[i] + s;
	int n = v.size();
	return s / n;
}
Money min(St q)//поиск минимального элемента
{
	Vec v = stack_to_vector(q);
	Money m = v[0];//минимальный элемент
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i]) {
			m = v[i];//минимальный элемент
		}
	return m;
}
void add_vector(St& s, int pos)//добавляем на место pos элемент el
{
	Money el = min(s);
	Vec v = stack_to_vector(s);
	v.insert(v.begin() + pos, el);
	s = vector_to_stack(v);
}
void del_vector(St& q)//удалить
{
	Vec v = stack_to_vector(q); int p = 0; Money a = avarage(q);
	while (p < v.size())
	{
		auto iter = v.cbegin();
		if (v[p] > a)
		{
			v.erase(iter + p);
		}
		else
		{
			p++;
		}
	}
	q = vector_to_stack(v);
}
Money max(St q)//поиск максимального элемента
{
	Vec v = stack_to_vector(q);
	Money m = v[0];
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
		}
	return m;
}
void multiplication(St& q)
{
	Vec v = stack_to_vector(q);
	Money m = max(q);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
	q = vector_to_stack(v);
}
void main()
{
	Money t;
	St s;
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);
	print_stack(s);
	cout << "\npos?";
	cin >> n;
	add_vector(s, n);
	print_stack(s); cout << "\n";
	del_vector(s);
	print_stack(s); cout << "\n";
	multiplication(s);
	print_stack(s); cout << "\n";
}