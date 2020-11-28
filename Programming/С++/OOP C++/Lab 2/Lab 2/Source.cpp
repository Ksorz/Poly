#include <iostream>
#include <climits>
#include <Windows.h>
#include <string>
#include <iomanip>

#include <ctime> // ��� ������� time()
#include <cstdlib> // ��� ������� rand() � srand()

using namespace std;

/* ������������ ������ �2. ������ � ��������� � ����������� � C++
����������� ��������� �������� ��� ������ � ���������:
1.	����� ������� (��� �������) �� �������
2.	���� ������� (��� �������) � �������
3.	�������� � ��������� ��� ��������� (� ������ ��������)
4.	���������� ���� ��� ������ ��������� (����, �����, ��������)

� ���������� ������������ ���� � ������������ (�-�, matrix.hpp) � ���� � ������������� ������� (�-�, matrix.cpp). ������ � �������� - � �������� ����� (�-�, source.cpp).
� ���������� ����� �� ������� (�-�, ����� �� �������) ������������ ��������� � �������� ���������� ��� ������� � ��������� �������.

������� 4: ���������� ����� ���������� �������
*/



int getRand(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ���������� ������������ ��������� ����� � ����� ���������
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
	cout << "���������� ��������:" << endl;
	cin >> mx.sizeY;
	cout << "���������� �����:" << endl;
	cin >> mx.sizeX;

	mx.mx = new int* [mx.sizeX];
	if (mx.sizeX * mx.sizeY > 10)
	{
		srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
		int min;
		int max;
		cout << "������� ������� �������, ������� �������� ��������� �������� ��� ��������������� ����������" << endl;
		cout << "����������� ��������:" << endl;
		cin >> min;
		cout << "������������ ��������:" << endl;
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
				cout << "������� " << i + 1 << " - " << j + 1 << ". ������� ��������:"<< endl;
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
	
	string variants[8] = { "��������� ���������", "��������� ������� �� ������", "�������� ������", "������������ ��������� ������",
	"���������� ����� ���������� �������", "��������� ������", "��������� ������ �� �������", "��������� ������� �� �����" };
	cout << "�������: " << int('L') % 8 << ' ' << variants[int('L') % 8] << endl;
	
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