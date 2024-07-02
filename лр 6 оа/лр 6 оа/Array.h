#pragma once
#include <iostream>
#include<vector>
using namespace std;

class Iterator
{
	friend class Array;//дружественный класс
public:
	Iterator() { elem = 0; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	bool operator==(const Iterator& it) { return elem == it.elem; } //перегруженные операции сравнения
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	void operator++(int) { elem++; };//перегруженная операция инкремент
	void operator--() { --elem; }//перегруженная операция декремент
	int& operator *() const { return*elem; }//перегруженная операция разыменования
private:
	int* elem;//указатель на элемент типа int
};

class Array
{
public:
	Array(int s, int x = 0); //конструктор с параметрами: выделяет память под s элементов и заполняет их
	Array(const Array& arr);//конструктор с параметрами
	~Array();//деструктор
	Array& operator=(const Array& arr);//оператор присваивания
	int& operator[](int index);//операция доступа по индексу
	Array operator-(Array& arr);
	int operator()();//операция, возвращающая длину вектора
	friend ostream& operator<<(ostream& out, const Array& arr);//перегруженные операции ввода-вывода
	friend istream& operator>>(istream& in, Array& arr);
	Iterator first() { return beg; }//возвращает указатель на первый элемент
	Iterator last() { return end; }//возвращает указатель на элемент следующий за последним
private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений множества
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
};
