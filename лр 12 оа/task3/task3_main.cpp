#include "C:\Users\��������\source\repos\�� 11 ��\������ 2\Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "N?"; cin >> n;//���������� ���������
	Vector<multimap<int, Money>> m(n);
	m.Print();//���������� �������
	m.Min(); m.Print(); cout << "\n";
	m.Del(); m.Print(); cout << "\n";
	m.multiplication(); m.Print();
}
