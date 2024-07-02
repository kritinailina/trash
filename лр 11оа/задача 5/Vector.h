#pragma once
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
template<class T> //������ ������
class Vector
{
	queue <T> s;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	Vector(const Vector<T>&);//����������� �����������
	void Print();//������
	~Vector(void);//����������
	T min();
	T avarage();
	void add_vector(T el, int pos);
	T max();
	void del_vector();
	void multiplication();
};
//����������� ����� � ������
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
//����������� ������� � ����
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
//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ���� ������� �
	}
	len = s.size();
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = s.len;
	//�������� �������� ����� Vec.s � ������ v
	vector v = copy_stack_to_vector(Vec.s);
	//�������� ������ v � ���� s
	s = copy_vector_to_stack(v);
}
//������
template <class T>
void Vector<T>::Print()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.front() << endl;//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}
template <class T>//����������
Vector<T>::~Vector(void)
{
}
template<class T>//��������� ������� ��������������
T Vector<T>::avarage()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//���������� ��������� � �����
	T sum = s.top();//��������� �������� ��� �����
	s.pop();//������� ������� �� ������� �����
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//��������� � ����� ������� �� ������� �����
		s.pop();//������� ������� �� ������� �����
		n++;//����������� ���������� ���������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
	return sum / n;
}
template<class T>//���������� ��������
void Vector<T>::add_vector(T el, int pos)
{
	vector <T>v;//��������������� ������
	T t = s.min();
	int i = 1;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� ������� �����
		//���� ����� �������� ����� pos ��������� � ������ ����� �������
		if (i == pos)v.push_back(el);
		v.push_back(t);//��������� t � ������
		s.pop();//������� ������� �� ������� �����
		i++;
	}
	s = copy_vector_to_stack(v);
}
template <class T>//����� ������������� ��������
T Vector<T>::max()
{
	T m = s.top();//m ��������� �������� �� ������� �����
	//� ������ ����������� �������� �����
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		//���������� m � ������� � ������� �����
		if (s.top() > m)m = s.top();
		s.pop();//������� ������� �� ������� �����
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
	return m;
}
template<class T>//�������� �������� �� ������� pos
void Vector<T>::del_vector()
{
	T m = avarage();//����� �������������
	vector<T> v;
	T t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� ������� �����
		//���� t �� ����� �������������, �� �������� ��� � ������
		if (t != m)v.push_back(t);
		s.pop();//������� ������� �� �����
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}
template<class T>//����� ������������ ��������
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
template<class T>//������� ���� ��������� ������� �� ����������� �������
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