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
// ���� ����������� ��������������? (true/false)
bool Triangle::isIsosceles()
{
	double AB = getSideLen(ABC[0], ABC[1]);
	double BC = getSideLen(ABC[1], ABC[2]);
	double CA = getSideLen(ABC[2], ABC[0]);

	if (AB == BC || BC == CA || AB == CA) { return true; }
	return false;
}
// ���������� ����� �������
double Triangle::getSideLen(Point one, Point two)
{
	return (double)sqrt(pow((one.x - two.x), 2) + pow((one.y - two.y), 2));
}
// ������� �� ����� �����������
void Triangle::printTriangle()
{
	cout << "�(x) = " << ABC[0].x << "; B(x) = " << ABC[1].x << "; C(x) = " << ABC[2].x << endl;
	cout << "�(y) = " << ABC[0].y << "; B(y) = " << ABC[1].y << "; C(y) = " << ABC[2].y << endl;
	if (isIsosceles()) cout << "��������������" << endl;
	else cout << "�� ��������������" << endl;
}


// ��������� �����
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ���������� ������������ ��������� ����� � ����� ���������
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// �������� ��������� �������������
void randomTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel, int quantity, int rndMin, int rndMax)
{
	Point A, B, C;
	srand(static_cast<unsigned int>(time(0))); // ��� ��������� ��������� ��������
	for (int i = 0; i < quantity; i++)
	{
		A.x = rnd(rndMin, rndMax);
		A.y = rnd(rndMin, rndMax);
		B.x = rnd(rndMin, rndMax);
		B.y = rnd(rndMin, rndMax);
		C.x = rnd(rndMin, rndMax);
		C.y = rnd(rndMin, rndMax);
		Triangle ABC = Triangle(A, B, C);
		push_back_Triangle(allTr, sizeAll, ABC); // ������������ ��������� �����������3 ���������� � ����� �������
		if (ABC.isIsosceles()) push_back_Triangle(selectedTr, sizeSel, ABC); // ���� ��������������, �� � � ������ ������ ����
	}
	cout << "\n��������� ������������� �������: " << quantity << endl;
}
// ����� �������� ��� �����
char endOrContinue() 
{
	char result;
	cout << "\n--- ���������? ---\n'q':      ��\nany key:  ���" << endl;
	cin >> result;
	system("cls");
	return result;
}
// ��������� �����
int factorial(int N) // ���������
{
	if (N < 0) return 0;
	if (N == 0) { return 1; }
	else { return N * factorial(N - 1); }
}
// ��������� ������� Point � ����� �������
void push_back_Point(Point*& oldArr, int& size, const Point newPoint) 
{
	Point* newArr = new Point[size + 1]; // ������� ����� ������

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i]; // �������� ��������
	}

	newArr[size++] = newPoint; // �������� ����� �������
	delete[] oldArr; // ������� ������ ������ �� ������
	oldArr = newArr; // ��������������� ���������
}
// ��������� ������� Triangle � ����� �������
void push_back_Triangle(Triangle*& oldArr, int& size, const Triangle newTriangle)
{ // ������� ��������� ����������, � ��������� � �� ����� ��� ���������� �� � ����
	Triangle* newArr = new Triangle[size + 1]; // ������� ����� ������

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i]; // �������� ��������
	}

	newArr[size++] = newTriangle; // �������� ����� �������
	delete[] oldArr; // ������� ������ ������ �� ������
	oldArr = newArr; // ��������������� ���������
}
// ������� ����� �����
Point newPoint()
{
	Point X;
	cin >> X.x >> X.y;
	return X;
}

// �������� ������� �������. ���������� ������ ���� ���������� ������������� �� ������� �����. ������� ������ �������������� �������������
Triangle* buildAllPossibleTriangles(Point* points, int& sizeP, Triangle*& selected, int& sizeT)
{
	int iterator = 0; // ���������� ��������� ������
	int numberOfTriangles = factorial(sizeP) / (factorial(3) * factorial(sizeP - 3)); // ��������� ��� ���������� (���-�� ����� �������������)
	Triangle* triangles = new Triangle[numberOfTriangles]; // ������ ����� ������ ����� �������������
	
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

	sizeP = iterator; // ���������� �� ������� �������� ������� ������ ������� �������������
	cout << "\n������������� �������: " << numberOfTriangles << endl;
	cout << "�� ��� ��������������: " << sizeT << endl;
	return triangles;
}
// ����� �� ����� ���� �������������
void printAllTriangles(Triangle* triangles, int size) // ������� �� ����� ��� ������������ �� �������
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n����������� " << i + 1 << ":" << endl;
		triangles[i].printTriangle();
	}
}
// ����� �� ����� ���� �����
void printAllPoints(Point* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "����� " << i + 1 << "  --  x: " << arr[i].x << "  " << "y: " << arr[i].y << endl;
	}
}
// �������� ������� ���� � �������������� ������������� 
void delTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel)
{
	delete[] allTr;
	delete[] selectedTr;
	cout << "\n������������� �������: " << sizeAll << endl;
	sizeAll = 0; // ���-�� ���� �������������
	sizeSel = 0; // ���������� �������������� �������������
	allTr = new Triangle[sizeAll];
	selectedTr = new Triangle[sizeSel];
}