#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//��������
	string name_student;
	string subject;
	int mark;
public:
	Exam();//����������� ��� ����������
	Exam(string, string, int);//����������� � �����������
	Exam(const Exam&);//����������� �����������
	~Exam();//����������
	string get_naime_student();//��������
	void set_name_student(string);//�����������
	string get_subject();//��������
	void set_subject(string); //�����������
	int get_mark();//��������
	void set_mark(int); //�����������
	void show();//�������� ���������
};
