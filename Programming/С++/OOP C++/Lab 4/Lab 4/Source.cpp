#include <iostream> 
#include <Windows.h>
#include <string>
#include "Functions.hpp"

using namespace std; 

/*
Лабораторная работа №4. Разработка класса и переопределение операций.
Реализовать класс в соответствии с вариантом. Ввести следующие элементы класса (элементы, специфические для разных вариантов перечислены в таблице):
-	закрытые поля;
-	открытые методы доступа к полям;
-	конструкторы;
-	переопределения арифметических операций (+, -, +=, -=);
-	переопределение операций сравнения (>, <, ==);
-	переопределение операции преобразования типа;
-	переопределение операции << для вывода на консоль;

Через консольное меню реализовать возможность взаимодействия с пользователем и проверки функциональности класса.

int V = abs(int(c1) - int(c2)) % 4, где с1 – первая буква фамилии на английском языке в верхнем регистре, 
с2 – первая буква имени на английском языке в верхнем регистре.

Вариант 3:
Класс для работы с множествами чисел.
Поддерживаются операции пересечения множеств, объединения, разности, нахождение уникальных элементов,
проверка наличия элемента в множестве
Операция индексирования
Деструктор
Преобразование в тип int*
*/

// Генерация случайных значений
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// Заполнение массива случайными значениями
void randomArrayFilling(int* arr, const int size)
{
	int min, max;
	cout << "Укажите диапозон значений:" << endl;
	cin >> min >> max;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rnd(min, max);
	}
}

bool yesNo(char yes)
{
	char yesNo;
	cout << "Да:  " << yes << "\nНет: любая клавиша" << endl;
	cin >> yesNo;
	system("cls");
	if (yesNo == yes) return true;
	else return false;
}

class NSet
{
public:

	int size;
	int* set;

	NSet()
	{
		cout << "Укажите количество элементов множества" << endl;
		cin >> size;
		set = new int[size];
		system("cls");

		if (size > 5 && size <= 10)
		{
			cout << "Заполнить случайными значениями?" << endl;
			if (yesNo('y')) randomArrayFilling(set, size);
			system("cls");
		}
		else if (size > 10)
		{
			cout << "Довольно большое множество, лучше заполнить случайными значениями." << endl;
			randomArrayFilling(set, size);
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
	void show()
	{
		if (size <= 600)
		{
			cout << "-- ";
			for (int i = 0; i < size; i++)
			{
				cout <<  set[i] << " -- ";
				if ((i + 1) % 15 == 0) cout << endl << "-- ";
			}
			cout << endl;
		}
		else { cout << "Слишком большое множество, показывать не будем!" << endl; }
	}
private:
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << abs(int('L') - int('A')) % 4 << endl << endl;

	NSet* nSets;

	NSet a;
	a.show();



	return 0;
}