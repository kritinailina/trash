#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;
//������� ��� �������� ������� ��� ����������
Exam make_tovar()
{
	string s;
	string i;
	double d;
	cout << "Vvedite name: ";
	cin >> s;
	cout << "Vvedite subject: ";
	cin >> i;
	cout << "Vvedite mark: ";
	cin >> d;
	Exam t(s, i, d);
	return t;
}
//������� ��� �������� ������� ��� ���������
void print_tovar(Exam t)
{
	t.show();
}
void main()
{
	//����������� ��� ����������
	Exam t1;
	t1.show();
	//���������� � �����������
	Exam t2("Brazhnikova", "Philosophy", 5);
	t2.show();
	//����������� �����������
	Exam t3 = t2;
	t3.set_name_student("Ilina");
	t3.set_subject("Math");
	t3.set_mark(5);
	//����������� �����������
	print_tovar(t3);
	//����������� �����������
	t1 = make_tovar();
	t1.show();
}