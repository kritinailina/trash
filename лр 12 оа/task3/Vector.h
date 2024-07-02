#pragma once
#include <iostream>
#include <map> //�������
using namespace std;
//������������������� �����
template<class T>
class Vector
{
	multimap<int, T> v; //��������� �������
	int len; //����� �������
public:
	Vector(void); //����������� ��� ����������
	Vector(int n); //����������� � �����������
	void Print(); //������
	~Vector(void); //����������
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
		v[i] = a;//�������� � � �������
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
	Money s = v[0]; //��������� �������� ����� � ������ ������� �������
	//������� �������
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
//����������
template<class T>
void Vector<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));//��������� ���� � ��������� �� � �������
}
template <class T>
int Vector<T>::Max()
{
	multimap<int, T>::iterator i = v.begin();//�������� ��������� �� ������ �������
	int nom = 0, k = 0;
	Money m = (*i).second;//�������� ������� ��������
	while (i != v.end()) //���� ��� ����� ����������
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� max
}
template<class T>
void Vector<T>::Del()
{
	int max = Max();
	cout << "max=" << v[max] << " nom=" << max << endl;
	v.erase(max);//������� ������������ �������
}
template<class T>
int Vector<T>::Min()
{
	map<int, T>::iterator i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;//�������� ������� ��������
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