#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<float>Vec;//���������� ��� ��� ������ � ��������
Vec make_vector(int n)//������� ��� ������������ �������
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		float r = rand() / static_cast<float>(RAND_MAX);
		v.push_back(r);
	}
	return v;
}
void print_vector(Vec v)//������� ��� ������ �������
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int min(Vec v)//����� ������������ ��������
{
	float m = v[0];//����������� �������
	int n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i])
		{
			m = v[i];//����������� �������
			n = i;//����� ������������
		}
	return n;
}
float avarage(Vec v)//���������� �������� ���������������
{
	float s = 0;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	return s / n;
}
void add_vector(Vec& v, float el, int pos)//��������� �� ����� pos ������� el
{
	v.insert(v.begin() + pos, el);
}
int max(Vec v)//����� ������������� ��������
{
	float m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
			n = i;
		}
	return n;
}
void del_vector(Vec& v)//�������
{
	int p = 0; float a = avarage(v);
	auto iter = v.cbegin();
	while (p < v.size())
	{
		if (v[p] > a) 
		{
			v.erase(iter + p);
		}
		else
		{
			p++;
		}
	}
	vector<float> res; 
	for (int i = 0; i < v.size(); i++)
	{
		if (a > v[i]) res.push_back(v[i]);
	}
	v = res;
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
		vector<float> v;
		vector<float>::iterator vi = v.begin();
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		float el = v[min(v)];
		cout << "pos?";
		int pos;
		cin >> pos;
		if (pos > v.size())throw 1;
		add_vector(v, el, pos);
		print_vector(v);
		del_vector(v);//�������
		print_vector(v);
		multiplication(v);
		print_vector(v);
	}
	catch (int)//���� ��������� ������
	{
		cout << "error!";
	}
}