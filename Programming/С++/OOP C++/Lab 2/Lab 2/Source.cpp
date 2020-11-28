#include <iostream>
#include <Windows.h>
#include <string>

#include "matrix.hpp"

using namespace std;

/* Лабораторная работа №2. Работа с массивами и указателями в C++
Реализовать следующие операции при работе с матрицами:
1.	Вывод матрицы (или вектора) на консоль
2.	Ввод матрицы (или вектора) с консоли
3.	Операция с матрицами или векторами (с учётом варианта)
4.	Консольное меню для работы матрицами (ввод, вывод, операция)

В реализации использовать файл с объявлениями (н-р, matrix.hpp) и файл с определениями функций (н-р, matrix.cpp). Работа с консолью - в основном файле (н-р, source.cpp).
В реализации одной из функций (н-р, вывод на консоль) использовать указатели и адресную арифметику для доступа к элементам массива.

Вариант 4: Вычисление следа квадратной матрицы
*/



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string variants[8] = { "Матричное умножение", "Умножение матрицы на вектор", "Сложение матриц", "Поэлементное умножение матриц",
	"Вычисление следа квадратной матрицы", "Вычитание матриц", "Умножение строки на столбец", "Умножение матрицы на число" };
	cout << "Вариант: " << int('L') % 8 << ' ' << variants[int('L') % 8] << endl;
	
	char choice = '0'; // Переменная switch
	char isExist = 'x'; // Для проверки существования матрицы

	while (choice != 'q')
	{
		cout << endl;
		cout << "Создать матрицу:         'm'" << endl;
		cout << "Вывод матрицы на экран:  'p'" << endl;
		cout << "След матрицы:            't'" << endl;
		cout << "Удалить матрицу:         'd'" << endl;
		cin >> choice;

		switch (choice)
		{
		case 'm':

			Matrix mx = matrix();
			isExist = 'v';
			continue;

		case 'p':

			cout << endl;
			if (isExist == 'v') { printMx(mx); }
			else { cout << "Сначала создайте матрицу!" << endl;	}
			continue;
			
		case 't':

			cout << endl;
			if (isExist == 'v') { traceMx(mx); }
			else { cout << "Сначала создайте матрицу!" << endl; }
			continue;

		case 'd':

			cout << endl;
			if (isExist == 'v')
			{
				deleteMx(mx);
				isExist = 'x';
				cout << "Матрица удалена" << endl;
			}
			else
			{ 
				cout << "Матрицы итак нет!" << endl;
			}
			continue;
			
		default:
			break;
		}
	}
	return 0;
}