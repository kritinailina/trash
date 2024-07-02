#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money& Money::operator=(const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}
bool Money::operator <(const Money& t)
{
	if (rub < t.rub) return true;
	if (rub == t.rub && kop < t.kop)return true;
	return false;
}
bool Money::operator ==(const Money& t)
{
	if (rub == t.rub && kop == t.kop)return true;
	return false;
}
bool Money::operator >(const Money& t)
{
	if (rub > t.rub) return true;
	if (rub == t.rub && kop > t.kop)return true;
	return false;
}
Money Money::operator+(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p;
}
//перегрузка бинарной операции деления
Money Money::operator*(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 * temp2) / 100;
	p.kop = (temp1 * temp2) % 100;
	return p;
}
Money Money::operator/(const int& t)
{
	int temp1 = rub * 100 + kop;
	Money p;
	p.rub = (temp1 / t) / 100;
	p.kop = (temp1 / t) % 100;
	return p;
}
//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "rubles?"; in >> t.rub;
	cout << "kopecks?"; in >> t.kop; cout << "\n";
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}
