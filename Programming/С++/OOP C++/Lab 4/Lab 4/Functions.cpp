#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std;

// Генерация случайных значений
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// Функция выбора
bool yesNo(char yes)
{
	char yesNo;
	cout << "Да:  " << yes << "\nНет: любая клавиша" << endl;
	cin >> yesNo;
	system("cls");
	if (yesNo == yes) return true;
	else return false;
}

NSet::NSet()
{
	cout << "Укажите количество элементов множества" << endl;
	cin >> size;
	set = new int[size];
	system("cls");

	if (size > 5 && size <= 10)
	{
		cout << "Заполнить случайными значениями?" << endl;
		if (yesNo('y')) randomSetFilling(set, size);
		system("cls");
	}
	else if (size > 10)
	{
		cout << "Довольно большое множество, лучше заполнить случайными значениями." << endl;
		randomSetFilling(set, size);
		system("cls");

	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Элемент " << i + 1 << ":" << endl;
			cin >> set[i];
			system("cls");
		}
	}
}

void NSet::show()
{
	if (size <= 600)
	{
		cout << "-- ";
		for (int i = 0; i < size; i++)
		{
			cout << set[i] << " -- ";
			if ((i + 1) % 15 == 0) cout << endl << "-- ";
		}
		cout << endl;
	}
	else { cout << "Слишком большое множество, показывать не будем!" << endl; }
}

void NSet::randomSetFilling(int* arr, const int size)
{
	int min, max;
	cout << "Укажите диапозон значений:" << endl;
	cin >> min >> max;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rnd(min, max);
	}
}