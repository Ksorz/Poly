#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>

#include "triangles.hpp"

using namespace std;

/* Лабораторная работа №3. Пользовательские типы данных

В работе предполагается введение пользовательских типов данных в виде структуры (или класса). 
Определение структуры Point может выглядеть следующим образом:
struct Point { double x; double y; };

В зависимости от варианта, кроме типа Point, необходимо ввести пользовательский тип данных «Треугольник», «Прямоугольник»,
«Квадрат», «Ромб» или «Трапеция», которые содержат массив точек в виде внутреннего элемента (поля).

Функции для реализации определяются в соответствии с вариантом. Приведенные сигнатуры можно изменять.
В реализации одной из функций использовать ссылочный тип данных (н-р, Point& или Rectangle&) для аргументов или возвращаемого значения.

Вариант 9: Нахождение равнобедренных треугольников
int getIsoscelesTriangles(Triangles t[], int size, Triangles* selected);  */



// Возможно я слегка увлёкся...
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << (int('L') + int('A')) % 11 << endl;

	char ll = 'd';
	float ss = ll;
	char ddd = ss;
	cout << ll + ss;
	
	int pointsSize = 0; // Размер будущего массива точек
	int trianglesSize = 0; // Размер будущего массива треугольников
	int selectedSize = 0; // Размер будущего массива равнобедренных треугольников

	Point* points = new Point[pointsSize]; // Будущий массив точек
	Triangle* triangles = new Triangle[trianglesSize]; // Будущий массив треугольников
	Triangle* selected = new Triangle[selectedSize]; // Будущий массив равнобедренных треугольников
	
	int iterator = 0; // Счетчик шагов при создании точек
	char choice = '0'; // Выбор switch



	while (choice != 'q')
	{
		cout << "\nСоздать (добавить) точки:                                       'M'" << endl;
		cout << "Создать (пересоздать) все возможные треугольники из точек:      'T'" << endl;
		cout << "Определить (добавить) новые треугольники:                       'N'\n" << endl;
		cout << "Вывести все точки на экран:                                     'P'" << endl;
		cout << "Вывести все треугольники на экран:                              'O'" << endl;
		cout << "Вывести на экран только равнобедренные треугольники:            'I'\n" << endl;
		cout << "Удалить все созданные точки:                                    'D'" << endl;
		cout << "Удалить все созданные треугольники:                             'C'" << endl;
		cout << "Выход:                                                          'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case 'm': // Создание точек

			system("cls");
			cout << "Создание точек.\nВведите минимум 3 точки, чтобы затем создать треугольник (через пробел или Enter)" << endl;
			while (choice != 'q')
			{
				cout << "\nТочка №" << ++iterator << ":" << endl;
				Point Point = newPoint(); // Определение новой точки
				push_back_Point(points, pointsSize, Point); // Функция добавляет к массиву "points" элемент "newPoint" и увеличивает "size" на 1
				system("cls");
				choice = endOrContinue();
			}
			choice = '0';
			continue;

		case 't': // Создание треугольников

			system("cls");
			if (trianglesSize > 0)
			{
				// переопределение массивов треугольников и равнобедренных треугольников на случай пересоздания
				delTriangles(triangles, trianglesSize, selected, selectedSize);
			}
			if (pointsSize >= 3)
			{
				trianglesSize = pointsSize; // В функцию передается кол-во точек, функция меняет переменную на кол-во треугольников
				// Создание треугольников
				triangles = buildAllPossibleTriangles(points, trianglesSize, selected, selectedSize);
			}
			else cout << "\nСлишком мало точек, должно быть не меньше трёх" << endl;
			continue;

		case 'n': // Добавить треугольники в массив

			while (choice != 'q')
			{
				Triangle ABC;
				cout << "\nВвести самостоятельно:                                        'T'" << endl;
				cout << "Создать случайные треугольники (только целые числа):          'R'" << endl;
				cout << "Выход:                                                        'Q'" << endl;
				cin >> choice;
				switch (choice)
				{
				case 't':

					system("cls");
					cout << "Определите новый треугольник:" << endl;
					cout << "\nA(x), A(y):" << endl;
					Point A = newPoint();
					cout << "\nB(x), B(y):" << endl;
					Point B = newPoint();
					cout << "\nC(x), C(y):" << endl;
					Point C = newPoint();
					ABC = Triangle(A, B, C);
					push_back_Triangle(triangles, trianglesSize, ABC);
					if (ABC.isIsosceles()) push_back_Triangle(selected, selectedSize, ABC);
					system("cls");
					cout << "Создан новый треугольник:\n" << endl;
					ABC.printTriangle();
					cout << "\nВсего треугольников: " << trianglesSize << "\n" << endl;
					choice = endOrContinue();
					continue;

				case 'r':

					system("cls");
					int quantity, min, max;
					cout << "\nВведите количество и диапозон случайных значений" << endl;
					cout << "(quantity, min, max; целые числа!. Через пробел или Enter)" << endl;
					cin >> quantity >> min >> max;
					randomTriangles(triangles, trianglesSize, selected, selectedSize, quantity, min, max);
					cout << "Всего треугольников: " << trianglesSize << "\n" << endl;
					choice = endOrContinue();

				default:
					break;
				}
			}
			choice = '0';
			continue;

		case 'p': // Печать точек

			system("cls");
			if (pointsSize > 0) printAllPoints(points, pointsSize);
			else cout << "\nТочек пока нет" << endl;			
			continue;

		case 'o': // Печать треугольников

			system("cls");
			if (trianglesSize > 0)
			{
				printAllTriangles(triangles, trianglesSize);
				cout << "\nВсего треугольников: " << trianglesSize << endl;
			}
			else cout << "\nТреугольников пока нет" << endl;
			continue;

		case 'i': // Печать равнобедренных треугольников

			system("cls");
			if (selectedSize > 0) printAllTriangles(selected, selectedSize);
			else cout << "\nРавнобедренных треугольников пока нет" << endl;
			continue;

		case 'd': // Удаление точек

			system("cls");
			if (pointsSize > 0)
			{
				delete[] points;
				cout << "\nУдалено точек: " << pointsSize << endl;
				pointsSize = 0;
				iterator = 0;
				points = new Point[pointsSize];
			}
			else cout << "\nТочек не создано" << endl;
			continue;

		case 'c': // Удаление треугольников

			system("cls");
			if (trianglesSize > 0) delTriangles(triangles, trianglesSize, selected, selectedSize);
			else cout << "\nТреугольников не создано" << endl;
			continue;

		default:
			break;
		}
		return 0;
	}
}
