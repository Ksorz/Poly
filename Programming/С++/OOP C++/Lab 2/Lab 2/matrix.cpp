// ���� � ������������� ������� (�-�, matrix.cpp)
#include <iostream>
#include <Windows.h>
#include <string>

#include <ctime> // ��� ������� time()
#include <cstdlib> // ��� ������� rand() � srand()
#include "matrix.hpp"

using namespace std;

int getRand(int min, int max) // �������� ��������� ��������
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ���������� ������������ ��������� ����� � ����� ���������
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getLen(int n) // ���������� ���������� �������� � ����� (�������� �����)
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

void printMx(Matrix mx) // ����� ������� �� �����
{
	int printStringLen = mx.sizeY * 3 + mx.sizeY * mx.maxNumLen + 1; // ����� ������ ��������� ������� (��� �������)
	int fillingVal; // ���������� �������� ������������ ������ ������ (��� �������)

	for (int i = 0; i < mx.sizeX; i++)
	{
		cout << string(printStringLen, '~') << endl; // ��������� '~' (��� �������)
		cout << "| ";
		for (int j = 0; j < mx.sizeY; j++)
		{
			fillingVal = mx.maxNumLen - getLen(mx.mx[i][j]); // ��������� ������ ������ ���������� �������� ������� ��� ����� ����� (� ��� ��� �������)
			cout << string(fillingVal, ' '); // ��������� ' ' (���� ��� �������)
			cout << mx.mx[i][j] << " | ";
		}
		cout << endl;
	}
	cout << string(printStringLen, '~') << endl;
}// � �������, ��� �������� ��������� ������� ������ �������� ���� ���������, �� �������� ������� ����������� ����� �� ������� :)

void traceMx(Matrix mx) // ���������� ����� ���������� �������
{

	if (mx.sizeX == mx.sizeY)
	{
		int result = 0;
		for (int i = 0; i < mx.sizeX; i++)
		{
			result += mx.mx[i][i];
		}
		cout << "���� ���������� ������� tr(A) = " << result << endl;
	}
	else
	{
		cout << "���������� ��������� ���� ������������� �������" << endl;
	}
}

void deleteMx(Matrix mx) // ��������� �� � ��� ������ �������?
{
	for (int i = 0; i < mx.sizeX; i++)
	{
		delete[] mx.mx[i];
	}
}

Matrix matrix() // ������ �������
{
	
	Matrix mx; // ��������� �������
	int maxNumLen = 1; // ��� �������� ���������� �������� ������ �������� ����� (� ������ ������)
	mx.maxNumLen = maxNumLen;

	cout << "\n����� �������" << endl;
	cout << "���������� ��������:" << endl;
	cin >> mx.sizeY;
	cout << "���������� �����:" << endl;
	cin >> mx.sizeX;

	mx.mx = new int* [mx.sizeX]; // ������ ������ ����������

	if (mx.sizeX * mx.sizeY > 12) // ������� ��� ��������������� ���������� �������� �������
	{
		srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� ����� ��� rand()
		int min; //
		int max; // �������� ��������� �����
		
		cout << "������� ������� ������� (>12), ������� �������� �������� ��� ���������� ����������" << endl;
		cout << "����������� ��������:" << endl;
		cin >> min;
		cout << "������������ ��������:" << endl;
		cin >> max;

		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY]; // ��� ������� ��������� ������� ������ ��������
			for (int j = 0; j < mx.sizeY; j++)
			{
				mx.mx[i][j] = getRand(min, max); // ����������� ��������� �������� �� ���������
				maxNumLen = getLen(mx.mx[i][j]); // ��������� ���������� �������� ��������
				if (mx.maxNumLen < maxNumLen) mx.maxNumLen = maxNumLen; // ������� ��������� �������� � ���������
			}
		}
	}
	else // ������� ��� ������� ���������� �������� �������
	{
		int value; // ���������� ��� ������� ����� ��������

		for (int i = 0; i < mx.sizeX; i++)
		{
			mx.mx[i] = new int[mx.sizeY]; // ��� ������� ��������� ������� ������ ��������
			for (int j = 0; j < mx.sizeY; j++)
			{
				cout << "������� " << i + 1 << " --- " << j + 1 << ". ������� ��������:" << endl;
				cin >> value;
				mx.mx[i][j] = value; // ����������� ��������� ��������
				maxNumLen = getLen(mx.mx[i][j]); // ��������� ���������� �������� ��������
				if (mx.maxNumLen < maxNumLen) mx.maxNumLen = maxNumLen; // ������� ��������� �������� � ���������
			}
		}
	}
	return mx;
}