#include <iostream>
using namespace std;
template <class T> //T - �������� �������
class Array
{
public:
	Array(int s, T k); //����������� � �����������: �������� ������ ��� s ��������� � ��������� �� k
	Array(const Array<T>& a);//����������� � �����������
	~Array();//����������
	Array& operator=(const Array<T>& a);//�������� ������������
	T& operator[](int index);//�������� ������� �� �������
	Array operator-(Array<T>& a);//�������� ��� ���������� ���������
	int operator()();//��������, ������������ ����� �������
	friend ostream& operator<< <>(ostream& out, const Array<T>& a);//������������� �������� �����-������
	friend istream& operator>> <>(istream& in, Array<T>& a);//<> ��������� �� ��, ��� ������� - ������
private:
	int size;//������ �������
	T* data;//�������� �� ������������ ������ �������� �������
};

//���e������� �������
//����������� � �����������
template <class T>
Array<T>::Array(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//����������� �����������
template <class T>
Array<T>::Array(const Array& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class T>
Array<T>::~Array()
{
	delete[]data;
	data = 0;
}
//�������� ������������
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
//�������� ������� �� �������
template <class T>
T& Array<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� ��� ���������� ���������
template <class T>
Array<T> Array<T>::operator-(Array<T>& arr)//+k
{
	Array<T> temp(size, 0);
	for (int i = 0; i < size; i++)
	{
		bool exist = false;
		for (int j = 0; j < arr.size; j++)
		{
			if (arr.data[j] == data[i]) exist = true;
		}
		if (exist)
		{
			temp.data[i] = 0;
		}
		else
		{
			temp.data[i] = data[i];
		}
	}
	return temp;
}
//�������� ��� ��������� ����� �������
template <class T>
int Array<T>::operator ()()
{
	return size;
}
//�������� ��� �����-������
template <class T>
ostream& operator<< (ostream& out, const Array<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Array<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}