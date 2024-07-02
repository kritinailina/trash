#include <iostream>
using namespace std;
class Money
{
public:
	Money(void);
	Money(int, int);
	Money(const Money&);
	Money& operator=(const Money&);
	Money operator-(Money k);
	//������������� �������� �����-������
	friend ostream& operator<< (ostream& out, const Money&);
	friend istream& operator>> (istream& in, Money&);
public:
	virtual ~Money(void) {};
private:
	long rub;
	int kop;
};
