#include <iostream>
#include <Windows.h>
#include <string>

#include "matrix.hpp"

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



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string variants[8] = { "��������� ���������", "��������� ������� �� ������", "�������� ������", "������������ ��������� ������",
	"���������� ����� ���������� �������", "��������� ������", "��������� ������ �� �������", "��������� ������� �� �����" };
	cout << "�������: " << int('L') % 8 << ' ' << variants[int('L') % 8] << endl;
	
	char choice = '0'; // ���������� switch
	char isExist = 'x'; // ��� �������� ������������� �������

	while (choice != 'q')
	{
		cout << endl;
		cout << "������� �������:         'm'" << endl;
		cout << "����� ������� �� �����:  'p'" << endl;
		cout << "���� �������:            't'" << endl;
		cout << "������� �������:         'd'" << endl;
		cin >> choice;

		switch (choice)
		{
		case 'm':

			Matrix mx = matrix();
			isExist = 'v';
			continue;

		case 'p':

			cout << endl;
			if (isExist == 'v') { printMx(mx); }
			else { cout << "������� �������� �������!" << endl;	}
			continue;
			
		case 't':

			cout << endl;
			if (isExist == 'v') { traceMx(mx); }
			else { cout << "������� �������� �������!" << endl; }
			continue;

		case 'd':

			cout << endl;
			if (isExist == 'v')
			{
				deleteMx(mx);
				isExist = 'x';
				cout << "������� �������" << endl;
			}
			else
			{ 
				cout << "������� ���� ���!" << endl;
			}
			continue;
			
		default:
			break;
		}
	}
	return 0;
}