#include "Array.h"
#include "Money.h"
#include <iostream>
using namespace std;
int main()
{
	Money t;
	cin >> t;
	cout << t << endl;
	Array<Money>A(2, t);
	cin >> A;
	cout << A << endl;
	Array<Money>B(4, t);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size=" << A() << endl;
	cout << B[1] - A[1] << endl;
}
