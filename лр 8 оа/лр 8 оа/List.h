#pragma once
#include "Object.h"
#include "Event.h"
class List
{
public:
	List(int);//конструктор с параметрами
public:
	~List(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	int operator()();//размер вектора
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};
