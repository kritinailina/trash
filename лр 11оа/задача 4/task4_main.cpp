#include "C:\Users\��������\source\repos\�� 11 ��\������ 2\Money.h"
#include <iostream>
#include <queue>
#include <vector>
typedef queue <Money> St;
typedef vector<Money>Vec;//������
using namespace std;
St make_stack(int n)
{
	St s;
	Money t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//���� ����������
		s.push(t);//���������� �� � ����
	}
	return s;//������� ���� ��� ��������� �������
}
//�������� ���� � ������
Vec stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������ ������� �� ������ �����
		v.push_back(s.front());
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
}
//�������� ������ � ����
St vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}
void print_stack(St P)
{
	while (!P.empty())
	{
		cout << P.front() << ' ';//������� ������ �������
		P.pop();//������� ������� �� ������
	}
}
Money avarage(St q)//���������� �������� ���������������
{
	Money s;
	Vec v = stack_to_vector(q);
	for (int i = 0; i < v.size(); i++)
		s = v[i] + s;
	int n = v.size();
	return s / n;
}
Money min(St q)//����� ������������ ��������
{
	Vec v = stack_to_vector(q);
	Money m = v[0];//����������� �������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i]) {
			m = v[i];//����������� �������
		}
	return m;
}
void add_vector(St& s, int pos)//��������� �� ����� pos ������� el
{
	Money el = min(s);
	Vec v = stack_to_vector(s);
	v.insert(v.begin() + pos, el);
	s = vector_to_stack(v);
}
void del_vector(St& q)//�������
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
Money max(St q)//����� ������������� ��������
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