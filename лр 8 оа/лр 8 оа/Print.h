#pragma once
#include <string>
#include "Object.h"
#include "Event.h"
using namespace std;
class Print :
    public Object
{
public:
    Print(void);//конструктор без параметров
public:
    virtual ~Print(void);//деструктор
    void Show();//функция для просмотра атрибутов класса
    void Input();//функция для ввода значений атрибутов
    Print(string, string);//конструктор с параметрами
    Print(const Print&);//конструктор копирования
    //селекторы
    string Get_name() { return name; }
    string Get_author() { return author; }
    //модификаторы
    void Set_name(string);
    void Set_author(string);
    Print& operator=(const Print&);//перегрузка операции
    void HandleEvent(const TEvent& e);
protected:
    string name;
    string author;
};

