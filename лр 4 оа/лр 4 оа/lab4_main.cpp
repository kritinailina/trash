#include <iostream>
#include "Triad.h"
#include "Date.h"
using namespace std;

//������� ��������� ������ �������� ������ ��� ��������
void f1(Triad& c)
{
	c.Set_first(789);
	cout << c;
}
//������� ���������� ������ �������� ������ ��� ���������
Triad f2()
{
	Date l(13, 5, 2004);
	return l;
}

void main()
{
	Triad a;
	cin >> a;
	cout << a;
	Triad b(163, 4, 115);
	cout << b;
	a = b;
	++b;
	cout << a;
	cout << b;
	Date c;//������� ������
	cin >> c;//������ �������� ���������
	c + 4;
	cout << c;//������� �������� ���������	f1(c);//�������� ������ ������ Lorry
	a = f2();//������� � ������� ������ ������ Lorry
	cout << a;
}