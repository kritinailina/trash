#include "Print.h"
#include "Event.h"
#include <iostream>
using namespace std;
Print::Print(void)
{
	name = "";
	author = "";
}
Print::~Print(void)//����������
{
}
Print::Print(string N, string A)//���������� � �����������
{
	name = N;
	author = A;
}
Print::Print(const Print& print)//����������� �����������
{
	name = print.name;
	author = print.author;
}
void Print::Set_name(string N)//���������
{
	name = N;
}
void  Print::Set_author(string A)
{
	author = A;
}
Print& Print::operator=(const Print& p)//�������� ������������
{
	if (&p == this)return *this;
	name = p.name;
	author = p.author;
	return *this;
}
void Print::Show()//����� ��� ��������� ���������
{
	cout << "Name: " << name;
	cout << "\nAuthor: " << author;
	cout << "\n";
}
void Print::Input()//����� ��� ����� �������� ���������
{
	cout << "Name: "; cin >> name;
	cout << "Author: "; cin >> author;
}
void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//�������-���������
	{
		switch (e.command)
		{
		case cmGet:cout << "Name=" << Get_name() << endl;
			break;
		}
	}
}
