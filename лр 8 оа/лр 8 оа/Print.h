#pragma once
#include <string>
#include "Object.h"
#include "Event.h"
using namespace std;
class Print :
    public Object
{
public:
    Print(void);//����������� ��� ����������
public:
    virtual ~Print(void);//����������
    void Show();//������� ��� ��������� ��������� ������
    void Input();//������� ��� ����� �������� ���������
    Print(string, string);//����������� � �����������
    Print(const Print&);//����������� �����������
    //���������
    string Get_name() { return name; }
    string Get_author() { return author; }
    //������������
    void Set_name(string);
    void Set_author(string);
    Print& operator=(const Print&);//���������� ��������
    void HandleEvent(const TEvent& e);
protected:
    string name;
    string author;
};

