#include "Array.h"
#include <iostream>
using namespace std;
Array::Array(int s, int k) //конструктор с параметрами
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
Array::Array(const Array& a)//конструктор копирования
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
Array::~Array()//деструктор
{
	delete[]data;
	data = 0;
}
Array& Array::operator=(const Array& a) //операция присваивания
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
	beg = a.beg;
	end = a.end;
	return *this;
}
int& Array::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
Array Array::operator-(Array& arr)
{
	int coun = 0; Array temp(size);
	for (int i = 0; i < size; i++)
	{
		bool exist = false;
		for (int j = 0; j < arr.size; j++)
		{
			if (arr.data[j] == data[i]) exist = true;
		}
		if (exist)
		{
			coun++;
			temp.data[i] = 0;
		}
		else
		{
			temp.data[i] = data[i];
		}
	}
	return temp;
}
int Array::operator()()//операция для получения длины вектора
{
	return size;
}
ostream& operator<<(ostream& out, const Array& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Array& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}
