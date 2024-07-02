#include "Date.h"
Date::Date(void) :Triad() //����������� ��� ����������
{
}
Date::~Date(void) //���������
{
}
Date::Date(int D, int M, int Y) :Triad(D, M, Y) //����������� � �����������
{
	first = D;
	second = M;
	third = Y;
}
Date::Date(const Date& d) //����������� �����������
{
	first = d.first;
	second = d.second;
	third = d.third;
}
Date& Date::operator+(int n)
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Date t(first, second, third);
	if (first + n > days[second-1]) {
		second++;
		first = first + n - days[second];
	}
	else {
		first = first + n;
	}
	if (second > 12) {
		second++;
		third++;
	}
 	return t;
}
Date& Date::operator=(const Date& d) //������� ������������
{
	if (&d == this)return *this;
	first = d.first;
	second = d.second;
	third = d.third;
	return *this;
}
istream& operator>>(istream& in, Date& d) //�������� �����
{
	cout << "Day:"; in >> d.first;
	cout << "Month:"; in >> d.second;
	cout << "Year:"; in >> d.third;
	return in;
}
ostream& operator<<(ostream& out, const Date& d) //�������� ������
{
	out << "Date: " << d.first << "." << d.second << "." << d.third;
	out << "\n";
	return out;
}
