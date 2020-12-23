#include <iostream> 
#include <Windows.h>
#include <string>
#include "Functions.hpp"

using namespace std; 

/*
������������ ������ �4. ���������� ������ � ��������������� ��������.
����������� ����� � ������������ � ���������. ������ ��������� �������� ������ (��������, ������������� ��� ������ ��������� ����������� � �������):
-	�������� ����;
-	�������� ������ ������� � �����;
-	������������;
-	��������������� �������������� �������� (+, -, +=, -=);
-	��������������� �������� ��������� (>, <, ==);
-	��������������� �������� �������������� ����;
-	��������������� �������� << ��� ������ �� �������;

����� ���������� ���� ����������� ����������� �������������� � ������������� � �������� ���������������� ������.

int V = abs(int(c1) - int(c2)) % 4, ��� �1 � ������ ����� ������� �� ���������� ����� � ������� ��������, 
�2 � ������ ����� ����� �� ���������� ����� � ������� ��������.

������� 3:
����� ��� ������ � ����������� �����.
�������������� �������� ����������� ��������, �����������, ��������, ���������� ���������� ���������,
�������� ������� �������� � ���������
�������� ��������������
����������
�������������� � ��� int*
*/

// ��������� ��������� ��������
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// ���������� ������� ���������� ����������
void randomArrayFilling(int* arr, const int size)
{
	int min, max;
	cout << "������� �������� ��������:" << endl;
	cin >> min >> max;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rnd(min, max);
	}
}

bool yesNo(char yes)
{
	char yesNo;
	cout << "��:  " << yes << "\n���: ����� �������" << endl;
	cin >> yesNo;
	system("cls");
	if (yesNo == yes) return true;
	else return false;
}

class NSet
{
public:

	int size;
	int* set;

	NSet()
	{
		cout << "������� ���������� ��������� ���������" << endl;
		cin >> size;
		set = new int[size];
		system("cls");

		if (size > 5 && size <= 10)
		{
			cout << "��������� ���������� ����������?" << endl;
			if (yesNo('y')) randomArrayFilling(set, size);
			system("cls");
		}
		else if (size > 10)
		{
			cout << "�������� ������� ���������, ����� ��������� ���������� ����������." << endl;
			randomArrayFilling(set, size);
			system("cls");

		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << "������� " << i + 1 << ":" << endl;
				cin >> set[i];
				system("cls");
			}
		}
	}
	void show()
	{
		if (size <= 600)
		{
			cout << "-- ";
			for (int i = 0; i < size; i++)
			{
				cout <<  set[i] << " -- ";
				if ((i + 1) % 15 == 0) cout << endl << "-- ";
			}
			cout << endl;
		}
		else { cout << "������� ������� ���������, ���������� �� �����!" << endl; }
	}
private:
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << abs(int('L') - int('A')) % 4 << endl << endl;

	NSet* nSets;

	NSet a;
	a.show();



	return 0;
}