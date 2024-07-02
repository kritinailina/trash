#include "Money.h"
#include <iostream>
using namespace std;
//���������� �������� ������������
Money& Money::operator=(const Money& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}
//���������� ���������� �������� ���������
Money& Money::operator--()
{
	int temp = rub * 100 + kop;
	temp--;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}
//���������� ����������� �������� ���������
Money Money::operator--(int)
{
	int temp = rub * 100 + kop;
	temp--;
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
}
//���������� �������� �������� ���������
bool Money::operator==(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	bool p = false;
	if (temp1 == temp2) p = true;
	return p;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& t)
{
	cout << "rubles?"; in >> t.rub;
	cout << "kopecks?"; in >> t.kop; cout << "\n";
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}