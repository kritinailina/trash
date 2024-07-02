#pragma once
#include <iostream>
#include <map> //словарь
using namespace std;
//параметризированный класс
template<class T>
class Vector
{
	multimap<int, T> v; //контейнер словарь
	int len; //длина словаря
public:
	Vector(void); //конструктор без параметров
	Vector(int n); //конструктор с параметрами
	void Print(); //печать
	~Vector(void); //деструктор
	void multiplication();
	int Min();
	T Srednee();
	int Max();
	void Del();
	void Add(int n, T el);
};
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
template <class T>
Vector<T>::~Vector(void)
{
}
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;//записать а в словарь
	}
	len = v.size();
}
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << i << " - " << v[i] << " " << endl;
	cout << endl;
}
template<class T>
T Vector<T>::Srednee()
{
	Money s = v[0]; //начальное значение суммы – первый элемент словаря
	//перебор словаря
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//количество элементов в словаре
	return s / n;
}
//добавление
template<class T>
void Vector<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));//формируем пару и добавляем ее в словарь
}
template <class T>
int Vector<T>::Max()
{
	multimap<int, T>::iterator i = v.begin();//итератор поставили на первый элемент
	int nom = 0, k = 0;
	Money m = (*i).second;//значение первого элемента
	while (i != v.end()) //пока нет конца контейнера
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
template<class T>
void Vector<T>::Del()
{
	int max = Max();
	cout << "max=" << v[max] << " nom=" << max << endl;
	v.erase(max);//удалить максимальный элемент
}
template<class T>
int Vector<T>::Min()
{
	map<int, T>::iterator i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if ((*i).second.get_min() != 0 && (*i).second.get_sec() != 0)
			if (m > (*i).second)
			{
				m = (*i).second;
				nom = k;
			}
		i++;
		k++;
	}
	return nom;
}
template<class T>
void Vector<T>::multiplication()
{
	T m = v[Min()];
	cout << "Min= " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / m;
}