#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

struct inform
{
	char nos[20];
	int obyom;
	char nazv[12];
	char autor[15];
};

void input(int n)
{
	inform b;
	FILE* f;
	f = fopen("data.txt", "w");
	for (int i = 0; i < n; i++)
	{
		cout << "Вводим структуру: " << i + 1 << endl;
		cout << "Введите носитель: "; cin >> b.nos;
		cout << "Введите объем: "; cin >> b.obyom;
		cout << "Введите название: "; cin >> b.nazv;
		cout << "Введите автора : "; cin >> b.autor;
		cout << endl;
		fwrite(&b, sizeof(b), 1, f);
	}
	fclose(f);
}

void del(int n)
{
	FILE* f, * f1;
	inform b;
	f = fopen("data.txt", "r");
	f1 = fopen("data2.txt", "w"); 
	for (int i = 0; fread(&b, sizeof(b), 1, f); i++)
	{
		if (b.obyom == n) continue;
		fwrite(&b, sizeof(b), 1, f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("data.txt", "w");
	f1 = fopen("data2.txt", "r");
	while (fread(&b, sizeof(b), 1, f1))
	{
		fwrite(&b, sizeof(b), 1, f);
	}
	fclose(f);
	fclose(f1);
}

void output()
{
	inform b;
	FILE* f;
	f = fopen("data.txt", "r");
	cout << setw(3) << "Номер";
	cout << setw(10) << "носитель";
	cout << setw(7) << "объем";
	cout << setw(10) << "название";
	cout << setw(10) << "автор";
	cout << endl;
	for (int i = 0; fread(&b, sizeof(b), 1, f); i++)
	{
		cout << setw(3) << i + 1;
		cout << setw(10) << b.nos;
		cout << setw(7) << b.obyom;
		cout << setw(10) << b.nazv;
		cout << setw(10) << b.autor;
		cout << endl;
	}
	fclose(f);
}

void add(int n)
{
	FILE* f; FILE* f1;
	inform b;
	f = fopen("data.txt", "r");
	f1 = fopen("data2.txt", "w");
	for (int i = 0; fread(&b, sizeof(b), 1, f); i++)
	{
		if (i == n - 1)
		{
			inform k;
			cout << "Введите носитель: "; cin >> k.nos;
			cout << "Введите объем: "; cin >> k.obyom;
			cout << "Введите название: "; cin >> k.nazv;
			cout << "Введите автора: "; cin >> k.autor;
			cout << endl;
			fwrite(&k, sizeof(k), 1, f1);
		}
		fwrite(&b, sizeof(b), 1, f1);
	}
	fclose(f1);
	f = fopen("data.txt", "w");
	f1 = fopen("data2.txt", "r");
	while (fread(&b, sizeof(b), 1, f1))
	{
		fwrite(&b, sizeof(b), 1, f);
	}
	fclose(f);
	fclose(f1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int kol;
	cout << "Сколько элементов запишем? ";
	cin >> kol;
	cout << endl;
	input(kol);
	output();
	cout << endl << "Введите объем носителя, который хотите удалить: ";
	int k;
	cin >> k;
	del(k); 
	output();
	cout << endl << "Номер элемента, перед которым вставить новый элемент: ";
	cin >> k;
	add(k); 
	output();
	return 0;
}
