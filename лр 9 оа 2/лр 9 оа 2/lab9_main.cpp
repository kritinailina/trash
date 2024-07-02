#include <iostream>
#include "Array.h"
#include "error.h"
using namespace std;
int main()
{
	try
	{
		Array x(0, 0);
		Array y;
		cout << x;
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y = x - y;
		cout << y;
		--x;
		cout << x;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}
