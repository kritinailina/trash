#include "C:\Users\��������\source\repos\�� 11 ��\������ 2\Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
	Vector<Money>vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	Money s = vec.min();
	cout << "pos?";
	int p; cin >> p;
	vec.add_vector(s, p);//�������� ������� � ������
	vec.Print();//������ �������
	vec.avarage();//����� ������������ �������
	vec.del_vector();//��������
	vec.Print();//������
	vec.multiplication();
	vec.Print();//������
}
