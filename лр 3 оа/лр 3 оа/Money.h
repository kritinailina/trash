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
	int get_min() { return rub; }
	int get_sec() { return kop; }
	void set_min(int r) { rub = r; }
	void set_sec(int k) { kop = k; }
	//перегруженные операции
	Money& operator=(const Money&);
	Money& operator--();
	Money operator--(int);//постфиксная операция
	bool operator==(const Money&);
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};
