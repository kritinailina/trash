#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//атрибуты
	string name_student;
	string subject;
	int mark;
public:
	Exam();//конструктор без параметров
	Exam(string, string, int);//конструктор с параметрами
	Exam(const Exam&);//конструктор копирования
	~Exam();//деструктор
	string get_naime_student();//селектор
	void set_name_student(string);//модификатор
	string get_subject();//селектор
	void set_subject(string); //модификатор
	int get_mark();//селектор
	void set_mark(int); //модификатор
	void show();//просмотр атрибутов
};
