#pragma once
#include <iostream>
using namespace std;
class Money
{
	long rub;
	int kop;
public:
	Money() { rub = 0; kop = 0; };
	Money(long r, int k) { rub = r; kop = k; }
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(int r) { rub = r; }
	void set_kop(int k) { kop = k; }
	//������������� ��������
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator*(const Money&);
	Money operator/(const int&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	bool operator ==(const Money&);
	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};
