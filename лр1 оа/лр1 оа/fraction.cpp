#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, double S)
{
	first = F; second = S;
}

void fraction::Read()
{
	cout << "first?"; cin >> first;
	cout << "second?"; cin >> second;
}

void fraction::Show()
{
	cout << "first=" << first << "\n";
	cout << "second=" << second<< "\n";
}

double fraction::Hipotenuse()
{
	double res = sqrt(pow(first, 2) + pow(second, 2));
	return res;
}