#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>

#include "triangles.hpp"

using namespace std;

/* ������������ ������ �3. ���������������� ���� ������

� ������ �������������� �������� ���������������� ����� ������ � ���� ��������� (��� ������). 
����������� ��������� Point ����� ��������� ��������� �������:
struct Point { double x; double y; };

� ����������� �� ��������, ����� ���� Point, ���������� ������ ���������������� ��� ������ ������������, ��������������,
��������, ����� ��� ����������, ������� �������� ������ ����� � ���� ����������� �������� (����).

������� ��� ���������� ������������ � ������������ � ���������. ����������� ��������� ����� ��������.
� ���������� ����� �� ������� ������������ ��������� ��� ������ (�-�, Point& ��� Rectangle&) ��� ���������� ��� ������������� ��������.

������� 9: ���������� �������������� �������������
int getIsoscelesTriangles(Triangles t[], int size, Triangles* selected);  */



// �������� � ������ ������...
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << (int('L') + int('A')) % 11 << endl;

	char ll = 'd';
	float ss = ll;
	char ddd = ss;
	cout << ll + ss;
	
	int pointsSize = 0; // ������ �������� ������� �����
	int trianglesSize = 0; // ������ �������� ������� �������������
	int selectedSize = 0; // ������ �������� ������� �������������� �������������

	Point* points = new Point[pointsSize]; // ������� ������ �����
	Triangle* triangles = new Triangle[trianglesSize]; // ������� ������ �������������
	Triangle* selected = new Triangle[selectedSize]; // ������� ������ �������������� �������������
	
	int iterator = 0; // ������� ����� ��� �������� �����
	char choice = '0'; // ����� switch



	while (choice != 'q')
	{
		cout << "\n������� (��������) �����:                                       'M'" << endl;
		cout << "������� (�����������) ��� ��������� ������������ �� �����:      'T'" << endl;
		cout << "���������� (��������) ����� ������������:                       'N'\n" << endl;
		cout << "������� ��� ����� �� �����:                                     'P'" << endl;
		cout << "������� ��� ������������ �� �����:                              'O'" << endl;
		cout << "������� �� ����� ������ �������������� ������������:            'I'\n" << endl;
		cout << "������� ��� ��������� �����:                                    'D'" << endl;
		cout << "������� ��� ��������� ������������:                             'C'" << endl;
		cout << "�����:                                                          'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case 'm': // �������� �����

			system("cls");
			cout << "�������� �����.\n������� ������� 3 �����, ����� ����� ������� ����������� (����� ������ ��� Enter)" << endl;
			while (choice != 'q')
			{
				cout << "\n����� �" << ++iterator << ":" << endl;
				Point Point = newPoint(); // ����������� ����� �����
				push_back_Point(points, pointsSize, Point); // ������� ��������� � ������� "points" ������� "newPoint" � ����������� "size" �� 1
				system("cls");
				choice = endOrContinue();
			}
			choice = '0';
			continue;

		case 't': // �������� �������������

			system("cls");
			if (trianglesSize > 0)
			{
				// ��������������� �������� ������������� � �������������� ������������� �� ������ ������������
				delTriangles(triangles, trianglesSize, selected, selectedSize);
			}
			if (pointsSize >= 3)
			{
				trianglesSize = pointsSize; // � ������� ���������� ���-�� �����, ������� ������ ���������� �� ���-�� �������������
				// �������� �������������
				triangles = buildAllPossibleTriangles(points, trianglesSize, selected, selectedSize);
			}
			else cout << "\n������� ���� �����, ������ ���� �� ������ ���" << endl;
			continue;

		case 'n': // �������� ������������ � ������

			while (choice != 'q')
			{
				Triangle ABC;
				cout << "\n������ ��������������:                                        'T'" << endl;
				cout << "������� ��������� ������������ (������ ����� �����):          'R'" << endl;
				cout << "�����:                                                        'Q'" << endl;
				cin >> choice;
				switch (choice)
				{
				case 't':

					system("cls");
					cout << "���������� ����� �����������:" << endl;
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
					cout << "������ ����� �����������:\n" << endl;
					ABC.printTriangle();
					cout << "\n����� �������������: " << trianglesSize << "\n" << endl;
					choice = endOrContinue();
					continue;

				case 'r':

					system("cls");
					int quantity, min, max;
					cout << "\n������� ���������� � �������� ��������� ��������" << endl;
					cout << "(quantity, min, max; ����� �����!. ����� ������ ��� Enter)" << endl;
					cin >> quantity >> min >> max;
					randomTriangles(triangles, trianglesSize, selected, selectedSize, quantity, min, max);
					cout << "����� �������������: " << trianglesSize << "\n" << endl;
					choice = endOrContinue();

				default:
					break;
				}
			}
			choice = '0';
			continue;

		case 'p': // ������ �����

			system("cls");
			if (pointsSize > 0) printAllPoints(points, pointsSize);
			else cout << "\n����� ���� ���" << endl;			
			continue;

		case 'o': // ������ �������������

			system("cls");
			if (trianglesSize > 0)
			{
				printAllTriangles(triangles, trianglesSize);
				cout << "\n����� �������������: " << trianglesSize << endl;
			}
			else cout << "\n������������� ���� ���" << endl;
			continue;

		case 'i': // ������ �������������� �������������

			system("cls");
			if (selectedSize > 0) printAllTriangles(selected, selectedSize);
			else cout << "\n�������������� ������������� ���� ���" << endl;
			continue;

		case 'd': // �������� �����

			system("cls");
			if (pointsSize > 0)
			{
				delete[] points;
				cout << "\n������� �����: " << pointsSize << endl;
				pointsSize = 0;
				iterator = 0;
				points = new Point[pointsSize];
			}
			else cout << "\n����� �� �������" << endl;
			continue;

		case 'c': // �������� �������������

			system("cls");
			if (trianglesSize > 0) delTriangles(triangles, trianglesSize, selected, selectedSize);
			else cout << "\n������������� �� �������" << endl;
			continue;

		default:
			break;
		}
		return 0;
	}
}
