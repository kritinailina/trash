#include "Array.h"
#include <iostream>
using namespace std;
void main()
{
	Array a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	Array b(10);
	cout << b << "\n";
 	b = a;
	a[2] = 100;
	cout << a << "\n";
	cout << b << "\n";
	Array c(1);
	cout << c << "\n";
	c = b - a;
	cout << c << "\n";
	cout << "\nthe length of a=" << a() << endl;
	cout << *a.first() << endl;
	Iterator i = a.last();
	--i;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); i++)cout << *i << endl;
}
