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


//ввод через итератор
/*
template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	while (first != last)
		f(*first++);
	return f;
}


void printValue(int num)
{
	cout << num << "n";
}
*/

//ДРУЗЬЯ КЛАССА_____________________________
/*
class Complex;
class RealTok;
class Realii;


void RealTok::Out_(Realii & itog)
{
	cout <<"\n"<< "Загружаю FRIEND метод..." << "\n";
	cout << "Выводим числа " << itog.real1 << " и " << itog.real2 << "\n";
}

void RealTok::RealSum(Realii & itog)
{
	cout << "Демонстрирую работу с FRIEND..." << "\n";
	cout << "Real1 = " << itog.real1 << "\n" << "Real2 = " << itog.real2 << "\n";
	int summa = itog.real1 + itog.real2;
	cout << "Сумма равна = " << summa;
}
*/


//Работа с ядрами МНОГОПОТОЧНОСТЬ(Функция)
/*void ThreFu(int&a)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Thread ID = " << this_thread::get_id() << " ========\tFUNC START \t==========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;
	cout << "Thread ID = " << this_thread::get_id() << " ========\tFUNC STOP \t==========" << endl;

}*/


//Работа с бинаркой
/* 
class person
{
protected:
	char name[80];
	int age;
public:
	virtual void get()
	{
		setlocale(LC_ALL, "Russian");
		cout << "\n Введите имя:\t";
		cin >> name;
		cout << "\n Введите возраст:\t";
		cin >> age;
	}
	virtual void put()
	{
		cout << "\n Имя:\t" << name;
		cout << "\n Возраст:\t" << age;

	}
};

class Skills :public person
{
private:
	int soft;
public:
	void get()
	{
		person::get();
		cout << "\n Баллы по программированию:\t";
		cin >> soft;
	}

	void put()
	{
		person::put();
		cout << "\n Баллы по программированию:\t" << soft;
	}
};
*/ 

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> v = { 3,3,4,5,11,33,43,11,441 };

	int elem;
	cout << "Введите элемент для поиска: " << endl;
	cin >> elem;
	auto result = find(v.begin(), v.end(), elem);
	if (result == v.end()) //если ничего не найдено, то возвращает конец
	{
		cout << "Нет такого элемента" << endl;
	}
	else //если найден элемент в коллекции 
	{
		cout << "Данный элемент найден" << endl;
	}

	system("pause");

	auto result1 = find_if(v.begin(), v.end(), [](int a)
	{
		return a % 2 == 0;
	});

	if (result1 == v.end()) //если ничего не найдено, то возвращает конец
	{
		cout << "Нет четных элементов в коллекции" << endl;
	}
	else //если найден элемент в коллекции 
	{
		cout << "Четный элемент найден в коллекции" << endl;
	}

	//алгоритм find_if_not аналогичный, но с инвертированным результатом

	vector<int> a = { 1,2,3,4,5 };
	vector<int> b = { 88 };
	copy(a.begin(), a.end(), back_inserter(b)); //помещаем элементы коллекции a в коллекцию b

	for (int i = 0; i < b.size(); i++)
	{
		cout << "Элемент " << i << " = " << b[i] << "\n";
	}

	//помещаем по выборке
	copy_if(a.begin(), a.end(), back_inserter(b), [](int b)
	{
		return b == 3;
	});

	cout << "\n";
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Элемент " << i << " = " << b[i] << "\n";
	}

	//поиск минимального и максимального элементов

	vector<int> z = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> z1 = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "\n";
	auto test = max_element(z.begin(), z.end());
	auto test2 = min_element(z.begin(), z.end());
	cout << "Максимальное число в коллекции z = " << *test << endl;
	cout << "Минимальное число в коллекции z = " << *test2 << endl;

	//сравнение коллекций: 1 - равны, 0 - не равны.
	bool zet = equal(begin(z), end(z), begin(z1), end(z1));

	if (zet == 0)
	{
		cout << "Коллекции z и z1 не равны по equal" << endl;
	}
	else
	{
		cout << "Коллекции z и z1 равны по equal" << endl;
	}

	//сравнение и вывод различающихся элементов
	auto zet1 = mismatch(begin(z), end(z), begin(z1), end(z1));
	if (zet1.first == end(z) && zet1.second == end(z1))
	{
		cout << "Коллекции z и z1 равны по mismatch" << endl;
	}
	else
	{
		cout << "Коллекции z и z1 не равны по mismatch" << endl;
	}

	return 0;


	//Концепции STL
	/*
	int init1[] = { 1, 2, 3, 4, 5 };
	int init2[] = { 6, 7, 8, 9, 10 };
	int init[] = { 11, 12, 13, 14, 15 };

	//вывод через итератор
	vector<int> v(10);
	merge(init1, init1 + 5, init2, init2 + 5, v.begin());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "n"));

	cout << "\n"; //переход на новою строку

	std::for_each(init, init + 5, printValue);

	cout << "\nРЕВЕРС:" << "\n"; //реверс

	reverse(init, init + 5);
	copy(init, init + 5, ostream_iterator<int>(cout, "n"));

	cout << "\nВывод определенных элементов вектора:" << "\n"; //реверс
	//Создаем переменную типа "итератор произвольного доступа"
	typedef vector<int>::iterator vectItr;
	vectItr itr;
	//Инициализируем вектор значениями из массива констант и присваиваем адрес его первого элемента итератору произвольного доступа :
	copy(init, init + 5, itr = v.begin());
	//Последовательно читаем элементы вектора, начиная с конца, и выводим их на экран:
	cout << *(itr + 4) << endl;
	cout << *(itr += 3) << endl;
	cout << *(itr -= 1) << endl;
	cout << *(itr = itr - 1) << endl;
	cout << *(--itr) << endl;
	//Итератор, претерпев несколько изменений, снова указывает на первый элемент вектора.
	for (int i = 0; i < (v.end() - v.begin()); i++) cout << itr[i] << space; cout << endl;
	*/


	//ДРУЗЬЯ КЛАССА
	/*
	Realii test(1, 22);
	RealTok schet;
	schet.RealSum(test);
	schet.Out_(test);
	*/



	//Работа с ядрами МНОГОПОТОЧНОСТЬ

	/*int xxx = 5;
	thread t(ThreFu, std::ref(xxx));

	cout << "Начинаю работу с многопоточностью, создаю 2 потока...\n";

	for (size_t i = 0; i < 10; i++)
	{
		cout << "Thread ID = " << this_thread::get_id() << "\tMAIN WORK \t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));

	}

	t.join();
	cout <<"\nRESULT:  "<< xxx << endl;
	*/
	
	//__________________________________________РАЗДЕЛЕНИЕ_________________________________________

	//Работа с бинаркой
	/* 
	cout << "\n Начинаю работу с бинарными файлами... \t";

	Skills x;
	ofstream f;

	cout << "\n Создаю бинарный файл... Начинайте ввод информации. \t";
	f.open("C:\\Users\\Боженька\\Desktop\\ComplexItog\\Files\\BINAR.dat", ios::binary);
	x.get();
	f.write(reinterpret_cast<char*>(&x), sizeof(x));
	f.close();
	cout << "\n Данные записаны в бинарный файл. \t";


	ifstream in;
	in.open("C:\\Users\\Боженька\\Desktop\\ComplexItog\\Files\\BINAR.dat", ios::binary);
	in.read(reinterpret_cast<char*>(&x), sizeof(x));
	cout << "\n Начинаю считывание данных из бинарного файла... \t";
	x.put();
	in.close();
	cout << "\n Данные из бинарного файла считаны. \t";
	system("pause");
	*/

	int x1, x4;
	int x2, x3;
	float aa;
	setlocale(LC_ALL, "Russian");

	//ДЛЛ
	/* 
	cout << "\n Подгружаю библиотеку DLL... \t";
	system("pause");

	typedef  void(*lol)();
	HINSTANCE hlib = LoadLibrary(L"Dll1.dll");

	if (hlib == NULL) cout << "Error";
	
	lol kek = (lol)GetProcAddress(hlib, "foo");
	if (hlib != NULL) kek();

	lol sum = (lol)GetProcAddress(hlib, "foo2");
	if (hlib != NULL) sum();
	*/
	

	cout << "\n" << "Введите параметры для числа А:" << "\n";
	cin >> x1 >> x2;
	cout << "Введите параметры для числа B:" << "\n";
	cin >> x3 >> x4;

    Complex A(x1,x2),B(x3,x4),C,ZZ;

	cout << "Деление на вещественное." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / 5;
	ZZ = B / 5;

	//ДЛЛ (Попытка работы с классами)
	/* 
	void (Complex::*pConstructor)();
	(FARPROC &)pConstructor = GetProcAddress(hlib, "Constructor");

	// Создаём объект на стеке
	char _C[sizeof(Complex)];
	Complex &C = *(Complex*)_C;

	// Явно вызываем конструкторы для обоих объектов
	(C.*pConstructor)();


	int (Complex::*pOutD)();
	(FARPROC &)pOutD = GetProcAddress(hlib, "OutD");

	printf("C.a = %d\n", (C.*pOutD)());

	// Получаем указатель на деструктор
	void (Complex::*pDestructor)();
	(FARPROC &)pDestructor = GetProcAddress(hlib, "Destructor");

	// Уничтожаем объект, созданный на стеке
	(C.*pDestructor)();
	*/

	//ДЛЛ
	/*HMODULE hmodule;
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
		
	}*/
	
	


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

