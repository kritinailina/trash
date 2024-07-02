#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Magazin.h"
using namespace std;
Magazin::Magazin(void) :Print()
{
	pages = 0;
}
Magazin::~Magazin(void)
{
}
Magazin::Magazin(int P)
{
	pages = P;
}
Magazin::Magazin(const Magazin& L)
{
	pages = L.pages;
}
void Magazin::Set_pages(int P)
{
	pages = P;
}
Magazin& Magazin::operator=(const Magazin& l)
{
	if (&l == this)return *this;
	pages = l.pages;
	return *this;
}
void Magazin::Show()
{
	cout << "Pages: " << pages << "\n";
	cout << "\n";
}
void Magazin::Input()
{
	cout << "\nPages:"; cin >> pages;
}
