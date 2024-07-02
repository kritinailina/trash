#include <iostream>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>Vec;//���������� ��� ��� ������ � ��������
Vec make_vector(int n)//������� ��� ������������ �������
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++) {
		Money a(rand() % 60, rand() % 60);
		v.push_back(a);//��������� � � ����� �������
	}
	return v;//���������� ������ ��� �������� ������ �������
}
void print_vector(Vec v)//������� ��� ������ �������
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
Money avarage(Vec v)//���������� �������� ���������������
{
	Money s;
	for (int i = 0; i < v.size(); i++)
		s = v[i] + s;
	int n = v.size();
	return s / n;
}
Money min(Vec v)//����� ������������ ��������
{
	Money m = v[0];//����������� �������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i]) {
			m = v[i];//����������� �������
		}
	return m;
}
void add_vector(Vec& v, Money el, int pos)//��������� �� ����� pos ������� el
{
	v.insert(v.begin() + pos, el);
}
void del_vector(Vec& v)//�������
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
int max(Vec v)//����� ������������� ��������
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
		vector<Money> v;//������
		vector<Money>::iterator vi = v.begin();//��������
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);//������������ �������
		print_vector(v);//������ �������
		Money el = min(v);
		cout << "pos?"; //������� ��� �������
		int pos;
		cin >> pos;
		if (pos > v.size())throw 1;
		add_vector(v, el, pos); //����� ������� ��� ����������
		print_vector(v); //������ �������
		del_vector(v);//�������
		print_vector(v);
		multiplication(v);//
		print_vector(v);
	}
	catch (int)//���� ��������� ������
	{
		cout << "error!";
	}
}