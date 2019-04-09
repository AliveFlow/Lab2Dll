// Laboratornaya1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Complex.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iterator>
#define space " "

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");


	int x1, x4;
	int x2, x3;
	float aa;
	setlocale(LC_ALL, "Russian");

	
	cout << "\n Подгружаю библиотеку DLL... \t";
	system("pause");

	typedef  void(*lol)();
	HINSTANCE hlib = LoadLibrary(L"Dll1.dll");

	if (hlib == NULL) cout << "Error";
	
	lol kek = (lol)GetProcAddress(hlib, "foo");
	if (hlib != NULL) kek();

	lol sum = (lol)GetProcAddress(hlib, "foo2");
	if (hlib != NULL) sum();
	
	

	cout << "\n" << "Введите параметры для числа А:" << "\n";
	cin >> x1 >> x2;
	cout << "Введите параметры для числа B:" << "\n";
	cin >> x3 >> x4;

    Complex A(x1,x2),B(x3,x4),C,ZZ;

	cout << "Деление на вещественное." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / 5;
	ZZ = B / 5;

	
	HMODULE hmodule;
	hmodule = LoadLibrary(L"Dll1.dll");

	if (hmodule == NULL)
	{
		cout << "Failed to load";
		system("pause");
		return 0;

	}
	if (hmodule != NULL)
	{
		cout << "Loading dll...Nice job, Steave Jobs";
		system("pause");
		
	}


	C.OutD();
	ZZ.OutD();
	cout << "Деление двух комплексных." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / B;
	C.OutD();
	cout << "\n";
	cout << "Разность комплексных." << "\n";
	cout << "Результат разности:" << "\n";
	C = A - B;
	C.OutD();
	cout << "Сумма комплексных." << "\n";
	cout << "Результат суммы:" << "\n";
	C = A + B;
	C.OutD();
	cout << "Умножение двух комплексныx." << "\n";
	cout << "Результат умножения:" << "\n";
    C = A * B;
	C.OutD();
	
	cout << "Умножение float на complex."<< "\n";
	cout << "На какое число желаете умножить?" << "\n";
	cin >> aa ;
	cout << "Результат умножения числа А:" << "\n";
	C = A * aa;
	C.OutD();
	cout << "Результат умножения числа В:" << "\n";
	ZZ = B * aa;
	ZZ.OutD();
	system("pause");

	
}

