#include "Money.h"
Money::Money()
{
	rub = kop = 0;
}
Money::Money(long R, int K)
{
	rub = R; kop = K;
}
Money::Money(const Money& p)
{
	rub = p.rub; kop = p.kop;
}
Money Money::operator =(const Money& p)
{
	if (&p == this) return *this;
	rub = p.rub; kop = p.kop;
	return*this;
}
Money::~Money()
{
}
ostream& operator<<(ostream& out, const Money& p)
{
	out << "rub: " << p.rub << " kop: " << p.kop << "\n";
	return out;
}
istream& operator>>(istream& in, Money& p)
{
	cout << "rub? "; in >> p.rub;
	cout << "kop? "; in >> p.kop;
	return in;
}
fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.rub;
	fin >> p.kop;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& p)
{
	fout << p.rub << "\n" << p.kop << "\n";
	return fout;
}