#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>

#include "triangles.hpp"

using namespace std;

Triangle::Triangle()
{
	Point* ABC = new Point[3];
}
Triangle::Triangle(Point a, Point b, Point c)
{
	ABC[0] = a;
	ABC[1] = b;
	ABC[2] = c;
}
// Этот треугольник равнобедренный? (true/false)
bool Triangle::isIsosceles()
{
	double AB = getSideLen(ABC[0], ABC[1]);
	double BC = getSideLen(ABC[1], ABC[2]);
	double CA = getSideLen(ABC[2], ABC[0]);

	if (AB == BC || BC == CA || AB == CA) { return true; }
	return false;
}
// Возвращает длину стороны
double Triangle::getSideLen(Point one, Point two)
{
	return (double)sqrt(pow((one.x - two.x), 2) + pow((one.y - two.y), 2));
}
// Выводит на экран треугольник
void Triangle::printTriangle()
{
	cout << "А(x) = " << ABC[0].x << "; B(x) = " << ABC[1].x << "; C(x) = " << ABC[2].x << endl;
	cout << "А(y) = " << ABC[0].y << "; B(y) = " << ABC[1].y << "; C(y) = " << ABC[2].y << endl;
	if (isIsosceles()) cout << "Равнобедренный" << endl;
	else cout << "Не равнобедренный" << endl;
}


// Случайное число
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// Налепить случайных треугольников
void randomTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel, int quantity, int rndMin, int rndMax)
{
	Point A, B, C;
	srand(static_cast<unsigned int>(time(0))); // Для генерации случайных значений
	for (int i = 0; i < quantity; i++)
	{
		A.x = rnd(rndMin, rndMax);
		A.y = rnd(rndMin, rndMax);
		B.x = rnd(rndMin, rndMax);
		B.y = rnd(rndMin, rndMax);
		C.x = rnd(rndMin, rndMax);
		C.y = rnd(rndMin, rndMax);
		Triangle ABC = Triangle(A, B, C);
		push_back_Triangle(allTr, sizeAll, ABC); // Получившийся случайный треугольник3 отправляем в конец массива
		if (ABC.isIsosceles()) push_back_Triangle(selectedTr, sizeSel, ABC); // Если равнобедренный, то и в другой массив тоже
	}
	cout << "\nСлучайных треугольников создано: " << quantity << endl;
}
// Выбор действия для цикла
char endOrContinue() 
{
	char result;
	cout << "\n--- Завершить? ---\n'q':      да\nany key:  нет" << endl;
	cin >> result;
	system("cls");
	return result;
}
// Факториал числа
int factorial(int N) // Факториал
{
	if (N < 0) return 0;
	if (N == 0) { return 1; }
	else { return N * factorial(N - 1); }
}
// Добавляет элемент Point в конец массива
void push_back_Point(Point*& oldArr, int& size, const Point newPoint) 
{
	Point* newArr = new Point[size + 1]; // Создаем новый массив

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i]; // Копируем элементы
	}

	newArr[size++] = newPoint; // Включаем новый элемент
	delete[] oldArr; // Удаляем старый массив из памяти
	oldArr = newArr; // Переприсваиваем указатель
}
// Добавляет элемент Triangle в конец массива
void push_back_Triangle(Triangle*& oldArr, int& size, const Triangle newTriangle)
{ // Функция идентична предыдущей, к сожалению я не понял как объединить их в одну
	Triangle* newArr = new Triangle[size + 1]; // Создаем новый массив

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i]; // Копируем элементы
	}

	newArr[size++] = newTriangle; // Включаем новый элемент
	delete[] oldArr; // Удаляем старый массив из памяти
	oldArr = newArr; // Переприсваиваем указатель
}
// Создает новую точку
Point newPoint()
{
	Point X;
	cin >> X.x >> X.y;
	return X;
}

// Основная функция задания. Возвращает массив всех возможноых треугольников из массива точек. Создает массив равнобедренных треугольников
Triangle* buildAllPossibleTriangles(Point* points, int& sizeP, Triangle*& selected, int& sizeT)
{
	int iterator = 0; // Переменная кличества циклов
	int numberOfTriangles = factorial(sizeP) / (factorial(3) * factorial(sizeP - 3)); // Сочетания без повторений (кол-во наших треугольников)
	Triangle* triangles = new Triangle[numberOfTriangles]; // Создаём новый массив наших треугольников
	
	for (int i = 0; i < (sizeP - 2); i++)
	{
		for (int j = (i + 1); j < (sizeP - 1); j++)
		{
			for (int t = (j + 1); t < sizeP; t++)
			{
				triangles[iterator] = Triangle(points[i], points[j], points[t]);
				if (triangles[iterator].isIsosceles()) push_back_Triangle(selected, sizeT, triangles[iterator]);
				iterator++;
			}
		}
	}

	sizeP = iterator; // Возвращаем из функции значение размера нового массива треугольников
	cout << "\nТреугольников создано: " << numberOfTriangles << endl;
	cout << "Из них равнобедренных: " << sizeT << endl;
	return triangles;
}
// Вывод на экран всех треугольников
void printAllTriangles(Triangle* triangles, int size) // Вывести на экран все треугольники из массива
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nТреугольник " << i + 1 << ":" << endl;
		triangles[i].printTriangle();
	}
}
// Вывод на экран всех точек
void printAllPoints(Point* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Точка " << i + 1 << "  --  x: " << arr[i].x << "  " << "y: " << arr[i].y << endl;
	}
}
// Обнуляет массивы всех и равнобедренных треугольников 
void delTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel)
{
	delete[] allTr;
	delete[] selectedTr;
	cout << "\nТреугольников удалено: " << sizeAll << endl;
	sizeAll = 0; // кол-во всех треугольников
	sizeSel = 0; // Количество равнобедренных треугольников
	allTr = new Triangle[sizeAll];
	selectedTr = new Triangle[sizeSel];
}