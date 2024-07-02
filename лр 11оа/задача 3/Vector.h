#pragma once
#include <vector>
#include <iostream>
using namespace std;
template<class T> //шаблон класса
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	void Print();//печать
	~Vector(void);//деструктор
	T min();
	T avarage();
	void add_vector(T el, int pos);
	T max();
	void del_vector();
	void multiplication();
};
template <class T> //конструктор без параметра
Vector<T>::Vector()
{
	len = 0;
}
template <class T>//деструктор
Vector<T>::~Vector(void)
{
}
template <class T>//конструктор с параметром
Vector<T>::Vector(int n)
{
	T a{};
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}
template <class T>//печать
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
template<class T>//вычислить среднее арифметическое
T Vector<T>::avarage()
{
	T s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}
template<class T>//добавление элемента
void Vector<T>::add_vector(T el, int pos)
{
	v.insert(v.begin() + pos, el);
}
template <class T>//поиск максимального элемента
T Vector<T>::max()
{
	T m = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] > m)
		{
			m = v[i];
		}
	return m;
}
template<class T>//удаление элемента из позиции pos
void Vector<T>::del_vector()
{
	int p = 0; T a = avarage();
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
}
template<class T>//поиск минимального элемента
T Vector<T>::min()
{
	T m = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] < m)
		{
			m = v[i];
		}
	return m;
}
template<class T>//деление всех элементов вектора на минимальный элемент
void Vector<T>::multiplication()
{
	Money m = max();
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}