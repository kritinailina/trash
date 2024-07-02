#include "Array.h"
#include <iostream>
using namespace std;
Array::Array(int s, int k) //конструктор с параметрами
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
Array::Array(const Array& a)//конструктор копирования
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
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
	return *this;
}
int& Array::operator[](int index)
{
	if (index < 0)throw 1;
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
Array Array::operator--()
{
	if (size == 0) throw 2;
	Array temp(size - 1, 0);
	temp.data = data;
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