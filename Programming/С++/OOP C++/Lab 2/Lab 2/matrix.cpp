// файл с определениями функций (н-р, matrix.cpp)
#include <iostream>
#include <Windows.h>
#include <string>

#include <ctime> // для функции time()
#include <cstdlib> // для функций rand() и srand()
#include "matrix.hpp"

using namespace std;

int getRand(int min, int max) // Получаем случайное значение
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getLen(int n) // Нахождение количества символов в числе (учитывая минус)
{
	int result = 0;
	if (n <= 0) result++;
	while (n)
	{
		n /= 10;
		result++;
	}
	return result;
}

void printMx(Matrix mx) // Вывод матрицы на экран
{
	int printStringLen = mx.sizeY * 3 + mx.sizeY * mx.maxNumLen + 1; // длина строки выводимой матрицы (для красоты)
	int fillingVal; // Количество пробелов относительно каждой ячейки (для красоты)

	for (int i = 0; i < mx.sizeX; i++)
	{
		cout << string(printStringLen, '~') << endl; // заполняем '~' (для красоты)
		cout << "| ";
		for (int j = 0; j < mx.sizeY; j++)
		{
			fillingVal = mx.maxNumLen - getLen(mx.mx[i][j]); // подгоняем каждую ячейку выводимого значения матрицы под общую длину (и это для красоты)
			cout << string(fillingVal, ' '); // заполняем ' ' (тоже для красоты)
			cout << mx.mx[i][j] << " | ";
		}
		cout << endl;
	}
	cout << string(printStringLen, '~') << endl;
}// Я понимаю, что подобное наведение красоты сильно тормозит нашу программу, но хотелось сделать симпатичный вывод на консоль :)

void traceMx(Matrix mx) // Вычисление следа квадратной матрицы
{

	if (mx.sizeX == mx.sizeY)
	{
		int result = 0;
		for (int i = 0; i < mx.sizeX; i++)
		{
			result += mx.mx[i][i];
		}
		cout << "След квадратной матрицы tr(A) = " << result << endl;
	}
	else
	{
		cout << "Невозможно вычислить след прямоугольной матрицы" << endl;
	}
}

void deleteMx(Matrix mx) // Правильно ли я тут удаляю матрицу?
{
	for (int i = 0; i < mx.sizeX; i++)
	{
		delete[] mx.mx[i];
	}
}

Matrix matrix() // Создаём матрицу
{
	
	Matrix mx; // Структура матрицы
	int maxNumLen = 1; // Для подсчета количества символов самого большого числа (с учетом минуса)
	mx.maxNumLen = maxNumLen;

	cout << "\nНовая матрица" << endl;
	cout << "Количество столбцов:" << endl;
	cin >> mx.sizeY;
	cout << "Количество строк:" << endl;
	cin >> mx.sizeX;

	mx.mx = new int* [mx.sizeX]; // создаём массив указателей

	if (mx.sizeX * mx.sizeY > 12) // условие для автоматического заполнения значений матрицы
	{
		srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа для rand()
		int min; //
		int max; // диапозон случайных чисел
		
		cout << "Матрица слишком большая (>12), введите диапозон значений для случайного заполнения" << endl;
		cout << "Минимальное значение:" << endl;
		cin >> min;
		cout << "Максимальное значение:" << endl;
		cin >> max;

		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY]; // для каждого указателя создаем массив значений
			for (int j = 0; j < mx.sizeY; j++)
			{
				mx.mx[i][j] = getRand(min, max); // присваиваем случайные значения из диапозона
				maxNumLen = getLen(mx.mx[i][j]); // вычисляем количество символов значения
				if (mx.maxNumLen < maxNumLen) mx.maxNumLen = maxNumLen; // условно обновляем значение в структуре
			}
		}
	}
	else // условие для ручного заполнения значений матрицы
	{
		int value; // Переменная для ручного ввода значений

		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY]; // для каждого указателя создаем массив значений
			for (int j = 0; j < mx.sizeY; j++)
			{
				cout << "Позиция " << i + 1 << " --- " << j + 1 << ". Введите значение:" << endl;
				cin >> value;
				mx.mx[i][j] = value; // присваиваем введенное значение
				maxNumLen = getLen(mx.mx[i][j]); // вычисляем количество символов значения
				if (mx.maxNumLen < maxNumLen) mx.maxNumLen = maxNumLen; // условно обновляем значение в структуре
			}
		}
	}
	return mx;
}