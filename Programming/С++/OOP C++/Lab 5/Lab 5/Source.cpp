#include <iostream> 
#include <Windows.h>
#include <string>

#include "Instrument.hpp"

using namespace std;

/*
������������ ������ �5. ������������ � �����������

����������� �������� ������� ��� ���������� �������� ����.
� �������� �������� ������ ����� ������������ ������� �� �������, ���� ���������� ���� ����������� ������� ����� � �������� �����������(�� ������������� � �������).
������� ��� ������� ��������� �� ������� : V = (int(c1) + int(c2)) % 8, ��� �1 � c2 � ������ ����� � ������� � ����� �� ���������� ����� � ������� ��������.

������� 3: Instrument

������:
-- + ������ �������� ������ ����������� �� ����� 5 ����������� ������� �, �� ������� ����, 3 ������ � ��������(� - �, ����� � ��������� B, � ����� B ��������� A).
-- � ������ ������ ������ �������� ���� � �������� ������ ������� � �����.
-- + � ������� ������ ������ ����������� ������ (� - �, toString, show), � ����������� ������� ������ ��������������� ����������� �������.
-- + ������ ����������� �������� ���� �� � 3 ������� (� - �, ����������� ���� - ���������� ��� �������������� ��������� Mammal::MaximalWeight,
     ����������� ������� ��������� �������� � �������� ������ ������� Square::GetSquare).
--- � ������� ������(� �������� main) ������ ������ ���������� �� ������� �������� ������. ����� ��������� ������� ����� ������ ����������(N >= 10)
--- ��� ���������� ����������� � ���������. ��������� ������ ��������� ������ �����. ��������� ��������� ������� �������� ��� ����, �����:
 -- ���������� ���������� �������� ������� ����; ��� �������� ���� ������� � ������� ����� ������������ ��������� dynamic_cast ��� typeid;
 -- ������� ���������� �� ������� �������, ��������� ����������� ������ �������� ������(� - �, show ��� toString);
 -- ����� ������� ��������������� �������; ��������, ����� ��������� � ����� ������ ����� ����������� (��� �������� 0),
   ����� ��������������� � ������������ ��������(��� �������� 4), ����� ������������� �������� � ���������� ������ ����(��� �������� 1), 
   ����� ������� � ���������� ������������ ���������(��� �������� 6).
-- ������������� ������������ ������������ ������.
*/


int Instrument::quantity = 0;        // Mechanical + Electrical
int Electrical::quantity = 0;        // Rechargeable + ElectricityGrid
int Mechanical::quantity = 0;
int Fishing::quantity = 0;
int Rechargeable::quantity = 0;
int �lectricalWire::quantity = 0;

int Instrument::maxPrice = 0;
int Electrical::maxPrice = 0;
int Mechanical::maxPrice = 0;

Instrument Instrument::maxPriceTool{};
Electrical Electrical::maxPriceTool{};
Mechanical Mechanical::maxPriceTool{};

string Instrument::className = "����������";
string Electrical::className = "�������������";
string Mechanical::className = "������������";
string Fishing::className = "������ �����";
string Rechargeable::className = "� �������������";
string �lectricalWire::className = "������� �� �������";

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << (int('E') + int('N')) % 8 << "\n\n";

	string* v3000 = new string[2]{ "�������", "��������" };

	int issSize = 13;
	Instrument** iss = new Instrument*[issSize]; // iss (instruments)
	iss[0] = new Mechanical{ "�������", 28, "��� 666", 1499 };
	iss[1] = new Mechanical{ "�������", 23 };
	iss[2] = new Mechanical{ "��������", 1, "�������� 3000", 999, v3000, 2 };
	iss[3] = new Mechanical{ "�����", 26 };
	iss[4] = new Mechanical{ "����", 19 };
	iss[5] = new Fishing{ "������", 14, "�������� junior", 3799 };
	iss[6] = new Fishing{ "����", 3 };
	iss[7] = new Rechargeable{ "�����", 11 };
	iss[8] = new Rechargeable{ "���������", 9 };
	iss[9] = new Rechargeable{ "����������", 7, "������� XL", 4999 };
	iss[10] = new �lectricalWire{ "��������", 18, "���� over 9000", 1000, 220, 2.5 };
	iss[11] = new �lectricalWire{ "�����", 6 };
	iss[12] = new �lectricalWire{ "������������ ���", 4, "������������", 7999 };
	





	char choice = '0';
	while (choice != 'q')
	{
		cout << "\n�������� ��� �����������:                                  'S'" << endl;
		cout << "���� � ����������:                                         'A'" << endl;
		cout << "�������� ����������:                                       'N'" << endl;
		cout << "������� ����������:                                        'D'" << endl;
		cout << "�������� �������� � ������������ ����������                'C'\n" << endl;
		cout << "�����:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case'a':
			system("cls");
			Instrument::show_stat();
			continue;
		case 's':
			system("cls");
			Instrument::show_all(issSize, iss);
			yesNo(choice);
			system("cls");
			continue;
		case 'n':
			system("cls");
			Instrument::create_new_item(iss, issSize);
			system("cls");
			continue;
		case 'd':
			int index;
			system("cls");
			Instrument::show_all(issSize, iss);
			cout << "����� ���������� �������?" << endl;
			cin >> index;
			Instrument::delete_item_iss(iss, issSize, index - 1);
			continue;
		case 'c':
			system("cls");
			cout << "�� ����: " << endl;
			Instrument::getmaxPriceTool().showInfo();
			cout << "\n\n�� �������������: " << endl;
			Electrical::getmaxPriceTool().showInfo();
			cout << "\n\n�� ������������: " << endl;
			Mechanical::getmaxPriceTool().showInfo();
			cout << endl;
			continue;
		default:
			continue;
		}
	}


	return 0;
}