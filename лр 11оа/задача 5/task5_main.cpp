#include "C:\Users\Кристина\source\repos\лр 11 оа\задача 2\Money.h"
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;
int main()
{
	Vector<Money>vec(3);
	vec.Print();
	Money t = vec.avarage();
	cout << "\nSrednee=" << t << endl;
	cout << "Add srednee" << endl;
	cout << "pos?";
	int pos;
	cin >> pos;
	vec.add_vector(t, pos);
	vec.Print();
	vec.del_vector();
	vec.Print();
	vec.multiplication();
	vec.Print();

}
