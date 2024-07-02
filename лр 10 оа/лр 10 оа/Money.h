#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>
using namespace std;
class Money
{
public:
	Money();
	Money(long r, int k);
	Money(const Money& t);
	Money operator =(const Money&);
	friend ostream& operator <<(ostream& out, const Money& p);
	friend istream& operator>>(istream& in, Money& p);
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
public:
	~Money();
private:
	long rub;
	int kop;
};