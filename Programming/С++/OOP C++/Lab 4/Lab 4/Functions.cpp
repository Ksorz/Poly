#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std;

// ��������� ��������� ��������
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// ������� ������
bool yesNo(char yes)
{
	char yesNo;
	cout << "��:  " << yes << "\n���: ����� �������" << endl;
	cin >> yesNo;
	system("cls");
	if (yesNo == yes) return true;
	else return false;
}

void push_back(int*& oldArr, int& size, const int newVal)
{
	int* newArr = new int[size + 1]; // ������� ����� ������

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i]; // �������� ��������
	}

	newArr[size++] = newVal; // �������� ����� �������
	delete[] oldArr; // ������� ������ ������ �� ������
	oldArr = newArr; // ��������������� ���������
}








