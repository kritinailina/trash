#include <iostream>
#include "fraction.h"
using namespace std;
fraction make_fraction(double F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	fraction A;
	A.Read();
	A.Show();
	cout << "A.Hipotenuse(" << A.first << "," << A.second << ")=" << A.Hipotenuse() << endl;
}

