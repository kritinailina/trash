#pragma once
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
template<class T> //шаблон класса
class Vector
{
	queue <T> s;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	Vector(const Vector<T>&);//конструктор копирования
	void Print();//печать
	~Vector(void);//деструктор
	T min();
	T avarage();
	void add_vector(T el, int pos);
	T max();
	void del_vector();
	void multiplication();
};
//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(queue<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	queue<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = s.len;
	//копируем значения стека Vec.s в вектор v
	vector v = copy_stack_to_vector(Vec.s);
	//копируем вектор v в стек s
	s = copy_vector_to_stack(v);
}
//печать
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.front() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
template <class T>//деструктор
Vector<T>::~Vector(void)
{
}
template<class T>//вычислить среднее арифметическое
T Vector<T>::avarage()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//количество элементов в стеке
	T sum = s.top();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины стека
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавляем в сумму элемент из вершины стека
		s.pop();//удаляем элемент из вершины стека
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	return sum / n;
}
template<class T>//добавление элемента
void Vector<T>::add_vector(T el, int pos)
{
	vector <T>v;//вспомогательный вектор
	T t = s.min();
	int i = 1;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если номер элемента равен pos добавляем в вектор новый элемент
		if (i == pos)v.push_back(el);
		v.push_back(t);//добавляем t в вектор
		s.pop();//удаляем элемент из вершины стека
		i++;
	}
	s = copy_vector_to_stack(v);
}
template <class T>//поиск максимального элемента
T Vector<T>::max()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if (s.top() > m)m = s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}
template<class T>//удаление элемента из позиции pos
void Vector<T>::del_vector()
{
	T m = avarage();//поиск максимального
	vector<T> v;
	T t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если t не равен максимальному, то добавить его в вектор
		if (t != m)v.push_back(t);
		s.pop();//удалить элемент из стека
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
template<class T>//поиск минимального элемента
T Vector<T>::min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template<class T>//деление всех элементов вектора на минимальный элемент
void Vector<T>::multiplication()
{
	T m = s.max();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.front() * m;
		v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}