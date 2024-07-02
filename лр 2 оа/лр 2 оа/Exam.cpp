#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
Exam::Exam()
{
	name_student = "";
	subject = "";
	mark = 0;
	cout << "Constructor bez parametrov dlia objecta" << this << endl;
}
//конструктор с параметрами
Exam::Exam(string N, string S, int M)
{
	name_student = N;
	subject = S;
	mark = M;
	cout << "Constructor s parametrami dlia objecta" << this << endl;
}
//конструктор копирования
Exam::Exam(const Exam& t)
{
	name_student = t.name_student;
	subject = t.subject;
	mark = t.mark;
	cout << "Constructor copirovania dlia objecta" << this << endl;
}
//деструктор
Exam::~Exam()
{
	cout << "Destructor dlia objecta" << this << endl;
}
//селекторы
string Exam::get_naime_student()
{
	return name_student;
}
string Exam::get_subject()
{
	return subject;
}
int Exam::get_mark()
{
	return mark;
}
//модификаторы
void Exam::set_name_student(string N)
{
	name_student = N;
}
void Exam::set_subject(string S)
{
	subject = S;
}
void Exam::set_mark(int M)
{
	mark = M;
}
//метод для просмотра атрибутов
void Exam::show()
{
	cout << "naimenovanie :" << name_student << endl;
	cout << "kolichestvo :" << subject << endl;
	cout << "stoimost :" << mark << endl;
}
