#include "Object.h"
#include "Triad.h"
#include "Date.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;
void main()
{
	Vector v(5);//������ �� 5 ���������
	Triad a;//������ ������ Car
	cin >> a;
	Date b;// ������ ������ Lorry
	cin >> b;
	Object* p = &a;//������ ��������� �� ������ ������ Triad
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Date
	v.Add(p); //��������� ������ � ������
	cout << v;//����� �������
}
