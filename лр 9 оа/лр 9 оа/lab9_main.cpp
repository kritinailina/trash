#include "Array.h"
#include <iostream>
using namespace std;
int main()
{
	//контролируемый блок
	try
	{
		Array x(0, 0);
		Array y(3, 8);
		Array z(3, 8);
		y[2] = 6;
		cout << x << "\n";
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << "\n";
		z = z - y;
		cout << z << "\n";
		--x;
		cout << x << "\n";
	}
	//обработчик исключения
	catch (int)
	{
		cout << "ERROR!!!" << endl;
	}//сообщение об ошибке
	return 0;
}
