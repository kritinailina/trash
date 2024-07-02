#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(int F, double S)
{
	double first = F; double second = S;
}

void fraction::Read()
{
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}

void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}

double fraction::Hipotenuse()
{
	double res = sqrt(pow(first, 2) + pow(second, 2));
	return res;
}