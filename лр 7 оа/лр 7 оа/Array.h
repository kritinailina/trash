#include <iostream>
using namespace std;
template <class T> //T - параметр шаблона
class Array
{
public:
	Array(int s, T k); //конструктор с параметрами: выделяет память под s элементов и заполняет их k
	Array(const Array<T>& a);//конструктор с параметрами
	~Array();//деструктор
	Array& operator=(const Array<T>& a);//оператор присваивания
	T& operator[](int index);//операция доступа по индексу
	Array operator-(Array<T>& a);//операция для добавление константы
	int operator()();//операция, возвращающая длину вектора
	friend ostream& operator<< <>(ostream& out, const Array<T>& a);//перегруженные операции ввода-вывода
	friend istream& operator>> <>(istream& in, Array<T>& a);//<> указывают на то, что функция - шаблон
private:
	int size;//размер вектора
	T* data;//укзатель на динамический массив значений вектора
};

//опрeделение функций
//конструктор с параметрами
template <class T>
Array<T>::Array(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//конструктор копирования
template <class T>
Array<T>::Array(const Array& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//деструктор
template <class T>
Array<T>::~Array()
{
	delete[]data;
	data = 0;
}
//операция присваивания
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
//операция доступа по индексу
template <class T>
T& Array<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция для добавления константы
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
//операция для получения длины вектора
template <class T>
int Array<T>::operator ()()
{
	return size;
}
//операции для ввода-вывода
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