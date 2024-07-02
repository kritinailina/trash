#include "Money.h"
Money::Money(void)
{
	rub = kop = 0;
}
Money::Money(int R, int K)
{
	rub = R; kop = K;
}
Money::Money(const Money& t)
{
	rub = t.rub;
	kop = t.kop;
}
Money& Money::operator =(const Money& t)
{
	rub = t.rub;
	kop = t.kop;
	return*this;
}
Money Money::operator-(Money k)
{
	long sum = rub * 100 + kop;
	long sum1 = k.rub * 100 + k.kop;
	Money temp((sum - sum1) / 100, (sum-sum1) % 100);
	return temp;
}
ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rub << "," << t.kop;
	return out;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "rub?"; in >> t.rub;
	cout << "kop?"; in >> t.kop;
	return in;
}
