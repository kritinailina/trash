#pragma once
#include <iostream>
#include<vector>
using namespace std;

class Iterator
{
	friend class Array;//������������� �����
public:
	Iterator() { elem = 0; }//����������� ��� ����������
	Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������
	bool operator==(const Iterator& it) { return elem == it.elem; } //������������� �������� ���������
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	void operator++(int) { elem++; };//������������� �������� ���������
	void operator--() { --elem; }//������������� �������� ���������
	int& operator *() const { return*elem; }//������������� �������� �������������
private:
	int* elem;//��������� �� ������� ���� int
};

class Array
{
public:
	Array(int s, int x = 0); //����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	Array(const Array& arr);//����������� � �����������
	~Array();//����������
	Array& operator=(const Array& arr);//�������� ������������
	int& operator[](int index);//�������� ������� �� �������
	Array operator-(Array& arr);
	int operator()();//��������, ������������ ����� �������
	friend ostream& operator<<(ostream& out, const Array& arr);//������������� �������� �����-������
	friend istream& operator>>(istream& in, Array& arr);
	Iterator first() { return beg; }//���������� ��������� �� ������ �������
	Iterator last() { return end; }//���������� ��������� �� ������� ��������� �� ���������
private:
	int size;//������ �������
	int* data;//�������� �� ������������ ������ �������� ���������
	Iterator beg;//��������� �� ������ ������� �������
	Iterator end;//��������� �� ������� ��������� �� ���������
};
