#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include "DIalog.h"
#include <iostream>
using namespace std;
int main()
{
	List v(10);//������� ������
	v.Add();//��������� ������ � ������
	v.Add(); //��������� ������ � ������
	v.Show();//����� �������
	v.Del();//�������� ��������
	cout << "\nVector size=" << v();
	Dialog D;
	D.Execute();
}
