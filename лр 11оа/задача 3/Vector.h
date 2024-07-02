#pragma once
#include <vector>
#include <iostream>
using namespace std;
template<class T> //������ ������
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	void Print();//������
	~Vector(void);//����������
	T min();
	T avarage();
	void add_vector(T el, int pos);
	T max();
	void del_vector();
	void multiplication();
};
template <class T> //����������� ��� ���������
Vector<T>::Vector()
{
	len = 0;
}
template <class T>//����������
Vector<T>::~Vector(void)
{
}
template <class T>//����������� � ����������
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
template <class T>//������
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
template<class T>//��������� ������� ��������������
T Vector<T>::avarage()
{
	T s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}
template<class T>//���������� ��������
void Vector<T>::add_vector(T el, int pos)
{
	v.insert(v.begin() + pos, el);
}
template <class T>//����� ������������� ��������
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
template<class T>//�������� �������� �� ������� pos
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
template<class T>//����� ������������ ��������
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
template<class T>//������� ���� ��������� ������� �� ����������� �������
void Vector<T>::multiplication()
{
	Money m = max();
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}