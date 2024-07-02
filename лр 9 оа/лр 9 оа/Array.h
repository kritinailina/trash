#pragma once
#include <iostream>
#include<vector>
using namespace std;
class Array
{
public:
	Array() { size = 0; data = {}; };
	Array(int s, int x = 0); //конструктор с параметрами: выделяет память под s элементов и заполняет их
	Array(const Array& arr);//конструктор с параметрами
	~Array();//деструктор
	Array& operator=(const Array& arr);//оператор присваивания
	int& operator[](int index);//операция доступа по индексу
	Array operator-(Array& arr);
	int operator()();//операция, возвращающая длину вектора
	Array operator--();
	friend ostream& operator<<(ostream& out, const Array& arr);//перегруженные операции ввода-вывода
	friend istream& operator>>(istream& in, Array& arr);
private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений множества
};