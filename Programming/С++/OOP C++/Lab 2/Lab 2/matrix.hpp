#pragma once
// файл с объявлениями (н-р, matrix.hpp)

struct Matrix // Структура для матрицы
{
	int sizeX; // Кол-во строк
	int sizeY; // Кол-во столбцов
	int maxNumLen; // количество символов самого большого числа в матрице (учитывая минус). Для оформления вывода на экран
	int** mx;
};

void printMx(Matrix mx); // Вывод матрицы на экран
Matrix matrix(); // Создание матрицы
void traceMx(Matrix mx); // Вычисление следа квадратной матрицы
void deleteMx(Matrix mx); // Удаление матрицы


