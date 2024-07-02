#pragma once
#include <iostream>
#include<vector>
using namespace std;
class Array
{
public:
	Array() { size = 0; data = {}; };
	Array(int s, int x = 0); //����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	Array(const Array& arr);//����������� � �����������
	~Array();//����������
	Array& operator=(const Array& arr);//�������� ������������
	int& operator[](int index);//�������� ������� �� �������
	Array operator-(Array& arr);
	int operator()();//��������, ������������ ����� �������
	Array operator--();
	friend ostream& operator<<(ostream& out, const Array& arr);//������������� �������� �����-������
	friend istream& operator>>(istream& in, Array& arr);
private:
	int size;//������ �������
	int* data;//�������� �� ������������ ������ �������� ���������
};