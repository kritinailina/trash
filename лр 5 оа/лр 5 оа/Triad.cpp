#include "Triad.h"
Triad::Triad(void) :Object()//конструктор без параметров
{
	first = 0;
	second = 0;
	third = 0;
}
Triad::~Triad(void)//деструктор
{
}
Triad::Triad(int F, int S, int T) //конструктор с параметрами
{
	first = F;
	second = S;
	third = T;
}
Triad::Triad(const Triad& triad) //конструктор копирования
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
void Triad::Set_second(int S) //модификаторы
{
	second = S;
}
void Triad::Set_first(int F)
{
	second = F;
}
void Triad::Set_third(int T)
{
	third = T;
}
Triad& Triad::operator++()
{
	Triad t(first, second, third);
	first++;
	second++;
	third++;
	return t;
}
Triad& Triad::operator=(const Triad& t)
{
	if (&t == this)return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}
istream& operator>>(istream& in, Triad& t)
{
	cout << "First:"; in >> t.first;
	cout << "Second:"; in >> t.second;
	cout << "Third:"; in >> t.third;
	return in;
}
ostream& operator<<(ostream& out, const Triad& t)
{
	out << "FIRST : " << t.first;
	out << "\nSECOND : " << t.second;
	out << "\nTHIRD : " << t.third;
	out << "\n";
	return out;
}
void Triad::Show()
{
	cout << "FIRST : " << first;
	cout << "\nSECOND : " << second;
	cout << "\nTHIRD : " << third;
	cout << "\n";
}
