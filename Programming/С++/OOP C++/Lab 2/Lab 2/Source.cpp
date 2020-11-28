#include <iostream>
#include <climits>
#include <Windows.h>
#include <string>
#include <iomanip>

#include <ctime> // для функции time()
#include <cstdlib> // для функций rand() и srand()

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



int getRand(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

struct Matrix
{
	int sizeX;
	int sizeY;
	int** mx;
};

Matrix matrix()
{
	Matrix mx;
	int value;
	cout << "Количество столбцов:" << endl;
	cin >> mx.sizeY;
	cout << "Количество строк:" << endl;
	cin >> mx.sizeX;

	mx.mx = new int* [mx.sizeX];
	if (mx.sizeX * mx.sizeY > 10)
	{
		srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
		int min;
		int max;
		cout << "Матрица слишком большая, введите диапозон случайных значений для автоматического заполнения" << endl;
		cout << "Минимальное значение:" << endl;
		cin >> min;
		cout << "Максимальное значение:" << endl;
		cin >> max;

		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY];
			for (int j = 0; j < mx.sizeY; j++)
			{
				mx.mx[i][j] = getRand(min, max);
			}
		}
	}
	else
	{
		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY];
			for (int j = 0; j < mx.sizeY; j++)
			{
				cout << "Позиция " << i + 1 << " - " << j + 1 << ". Введите значение:"<< endl;
				cin >> value;
				mx.mx[i][j] = value;
			}
		}
	}
	return mx;
}



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string variants[8] = { "Матричное умножение", "Умножение матрицы на вектор", "Сложение матриц", "Поэлементное умножение матриц",
	"Вычисление следа квадратной матрицы", "Вычитание матриц", "Умножение строки на столбец", "Умножение матрицы на число" };
	cout << "Вариант: " << int('L') % 8 << ' ' << variants[int('L') % 8] << endl;
	
	Matrix mx = matrix();

	for (int i = 0; i < mx.sizeX; i++)
	{
		cout << string(mx.sizeX * 4, '~') << endl;
		cout << "| ";
		for (int j = 0; j < mx.sizeY; j++)
		{
			cout << mx.mx[i][j] << " | ";
		}
		cout << endl;
	}



	char choice = '0';
	while (choice != 'q')
	{

	}


	return 0;
}