#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include <iostream>
using namespace std;
List::~List(void)//����������
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
List::List(int n)//����������� � �����������
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void List::Add()//���������� �������, �� ������� ��������� ��������� p � ������
{
	Object* p;
	cout << "1.Print" << endl; //����� �� �������� ���� ��������� �������
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ Car
	{
		Print* a = new (Print);
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Lorry
		{
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void List::Show()//�������� �������
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
}

int List::operator ()()//��������, ������� ���������� ������ �������
{
	return cur;
}
void List::Del()
{
	if (cur == 0)return;//������
	cur--;
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//����� ������ (������� ����������)
			p++;//����������� ��������� �� ��������� ������
		}
	}
}