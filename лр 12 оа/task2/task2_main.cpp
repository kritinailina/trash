#include <iostream>
#include <map>
#include "C:\Users\��������\source\repos\�� 11 ��\������ 2\Money.h"
using namespace std;
typedef multimap<int, Money>TMap;
typedef TMap::iterator it;
//������� ��� ������������ �������
TMap make_map(int n)
{
	TMap m;//������ �������
	int a; Money b;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		cin >> b;
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(a, b));
	}
	return m;//���������� ������� ��� ��������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	TMap m1 = m;
	for (it m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
	{
		cout << m1_Iter->first << " . " << m1_Iter->second << endl;
	}
}
//���������� �������� ���������������
Money srednee(TMap v)
{
	Money s;
	for (it m1_Iter = v.begin(); m1_Iter != v.end(); m1_Iter++)
	{
		s = s + m1_Iter->second;
	}
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
void Min(TMap& v)
{
	it i = v.begin(); it res = v.begin();
	Money m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			res = i;
		}
		i++;//��������
	}
	cout << "pos?";
	int a; cin >> a;
	v.insert(make_pair(a, res->second));
}
void multiplication(TMap& v)
{
	it i = v.begin(); it res = v.begin();
	Money m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			res = i;
		}
		i++;//��������
	}
	for (it m1_Iter = v.begin(); m1_Iter != v.end(); m1_Iter++)
	{
		m1_Iter->second = m1_Iter->second * res->second;
	}
}
void delete_map(TMap& v)
{
	Money a = srednee(v); it i = v.begin();
	while (i != v.end())
	{
		if (a < (*i).second)
		{
			v.erase(i);
			i = v.begin();
		}
		else
		{
			i++;//��������
		}
	}
}
//�������� �������
int main()
{
	int n;
	cout << "N?"; cin >> n;//���������� ���������
	TMap m = make_map(n); cout << "\n";//������� �������
	print_map(m);//���������� �������
	Min(m); print_map(m); cout << "\n";
	delete_map(m); print_map(m); cout << "\n";
	multiplication(m); print_map(m);
}