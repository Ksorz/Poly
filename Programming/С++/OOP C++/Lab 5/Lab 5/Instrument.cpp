#include <iostream> 
#include <Windows.h>
#include <string>
#include <climits>

#include "Instrument.hpp"

using namespace std;

// ���������� ��������� ==========================================================================
static int const matsExLen = 4;
static string const materialsExample[matsExLen] = { "�������", "������" , "������" , "��������" };
// ���������� ��������� ==========================================================================



// ���� ��������� ������� ========================================================================
bool yesNo(char& choice, string yes, string no)
{
	cout << yes << ": ����� �������" << "\n" << no << ": 'Q'" << endl;
	cin >> choice;
	if (choice == 'q' || choice == 'Q') return false;
	return true;
}
void push_back(int*& oldArr, const int newItem, int& size)
{
	int* newArr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i];
	}

	newArr[size++] = newItem;
	delete[] oldArr;
	oldArr = newArr;
}
void push_back(string*& oldArr, const string newItem, int& size)
{
	string* newArr = new string[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i];
	}

	newArr[size++] = newItem;
	delete[] oldArr;
	oldArr = newArr;
}
// ���� ��������� ������� ========================================================================



// ���� virtual showInfo() =======================================================================
// virtual ������� (�������� ����������)
void Instrument::showInfo() const
{
	cout << itemName;

	if (model != "000") cout << ", ������: \"" << model << "\"";
	cout << " (" << itemQuantity << " ��.) ";
	if (price != 0) cout << "\n����: �� ������� - " << price << " ���., ����� - " << totalPrice << " ���.";
	else cout << "���� �� �������.";
}
void Mechanical::showInfo() const
{
	Instrument::showInfo();
	if (matsLen > 0)
	{
		cout << "\n���������: ";
		for (int i = 0; i < matsLen; i++)
		{
			cout << " " << materials[i];
			if (matsLen != (i + 1)) cout << ", ";
		}
	}
}
void Fishing::showInfo() const
{
	Mechanical::showInfo();
	if (isProfessional == '0' || isProfessional == '1')
	{
		if (isProfessional == '1') cout << "\n����������������";
		else cout << "\n������� ��� ����������";
	}
}
void Electrical::showInfo() const
{
	Instrument::showInfo();
	if (voltage > 0) cout << "\n" << voltage << " �����";
}
void Rechargeable::showInfo() const
{
	Electrical::showInfo();
	if (batteryCapacity > 0) cout << ", " << batteryCapacity << " mAh";
}
void �lectricalWire::showInfo() const
{
	Electrical::showInfo();
	if (wireLength > 0) cout << ". ����� �������: " << wireLength << "�.";
}
// ���� virtual showInfo() =======================================================================



// ���� static ������� � Instrument ==============================================================
// �������� ��� ��������
void Instrument::show_all(const int size, Instrument** iss)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		iss[i]->showInfo();
		cout << endl << iss[i]->getClassName() << "\n\n";
	}
}
// ���������� ���������� �� ��������� ���������
void Instrument::show_stat()
{
	cout << Instrument::className << " (" << Instrument::getTotalQ() << " ��.):\n";
	cout << " � " << Mechanical::className << " (" << Mechanical::getTotalQ() << " ��.)\n";
	cout << "   � " << Fishing::className << " (" << Fishing::getTotalQ() << " ��.)\n";
	cout << " � " << Electrical::className << " (" << Electrical::getTotalQ() << " ��.)\n";
	cout << "   � " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " ��.)\n";
	cout << "   � " << �lectricalWire::className << " (" << �lectricalWire::getTotalQ() << " ��.)\n";
}
// �������� ���������� � ����� ������
void Instrument::push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem)
{
	Instrument** newIss = new Instrument * [size + 1]; // ������� ����� ������

	for (int i = 0; i < size; i++)
	{
		newIss[i] = oldIss[i]; // �������� ��������
	}

	newIss[size++] = newItem; // �������� ����� �������
	delete[] oldIss;
	oldIss = newIss; // ��������������� ���������
	system("cls");
	cout << "���������:\n";
	newIss[size - 1]->showInfo();
	cout << endl << newIss[size - 1]->getClassName() << "\n\n";
}
// ������� ���������� �� ������
void Instrument::delete_item_iss(Instrument**& oldIss, int& size, int index)
{
	bool isDeleted = false;
	Instrument** newIss = new Instrument * [--size];
	
	for (int i = 0; i < size + 1; i++)
	{
		if (!isDeleted)
		{
			if (i == index)
			{
				system("cls");
				cout << "�������:\n";
				oldIss[index]->showInfo();
				cout << endl << oldIss[index]->getClassName() << "\n\n";
				delete oldIss[index];
				isDeleted = true;
				continue;
			}
			newIss[i] = oldIss[i];
		}
		else newIss[i - 1] = oldIss[i];
	}

	delete[] oldIss;
	oldIss = newIss;
}
// ���������������� ����� ����������
void Instrument::create_new_item(Instrument**& iss, int& issSize)
{
	char choice = '0';
	int q, p;
	string n, m;
	while (choice != 'q')
	{
		system("cls");
		cout << "���������� ������ �����������" << endl;
		cout << "�������� ��� \n\n1: " << Mechanical::className << "\n2: " << Fishing::className;
		cout << "\n3: " << Rechargeable::className << "\n4: " << �lectricalWire::className << "\n\nQ: ������� ����\n";
		cin >> choice;
		p = 0; m = "000";

		switch (choice)
		{
		

		case'1':

		{
			Instrument::initializeData(n, q, m, p);
			Mechanical* newItem = new Mechanical(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;
			
		case'2':

		{
			Instrument::initializeData(n, q, m, p);
			Fishing* newItem = new Fishing(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		case'3':

		{
			Instrument::initializeData(n, q, m, p);
			Rechargeable* newItem = new Rechargeable(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		case'4':

		{

			Instrument::initializeData(n, q, m, p);
			�lectricalWire* newItem = new �lectricalWire(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		default:

			continue;
		}
	}
}
// ���������������� ������� �������� � ��������
void Instrument::initializeData(string& iName, int& iQuantity, string& mod, int& p)
{
	cout << "\n������� ��������:" << endl;
	getline(cin >> ws, iName);
	cout << "\n������� ���������� (����� �����):" << endl;
	cin >> iQuantity;

	cout << "\n������� �������������� ��������?" << endl;
	char choice = '0';
	if (yesNo(choice, "��", "���"))
	{
		cout << "\n������� �������� ������:" << endl;
		getline(cin >> ws, mod);
		cout << "\n������� ���� (����� �����):" << endl;
		cin >> p;
	}
}
// ������� ������
void Instrument::search(const int size, Instrument** iss)
{
	char choice = '0';
	int var = 0;
	Instrument* varObject = nullptr;

	while (choice != 'q')
	{
		cout << "\n����� �� ����:                                             '1'" << endl;
		cout << "������������ ���������:                                    '2'" << endl;
		cout << "����������� ���������:                                     '3'" << endl;
		cout << "������������ ����������:                                   '4'" << endl;
		cout << "����������� ����������:                                    '5'\n" << endl;
		cout << "������� ����:                                              'Q'" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':

			while (choice != 'q')
			{
				cout << "\n������������:                                              '1'" << endl;
				cout << "�������������:                                             '2'" << endl;
			
				cout << "��� �������:                                               '3'" << endl;
				cout << "� �������������:                                           '4'" << endl;
				cout << "� ��������:                                                '5'\n" << endl;
				cout << "��� �����:                                                 'Q'" << endl;
				cin >> choice;

				switch (choice)
				{
				case '1':

					system("cls");
					for (int i = 0; i < size; i++)
						if (typeid(*iss[i]) == typeid(Mechanical) || typeid(*iss[i]) == typeid(Fishing))
						{
							iss[i]->showInfo();
							cout << "\n" << iss[i]->getClassName() << "\n\n";
						}
					continue;

				case '2':

					system("cls");
					for (int i = 0; i < size; i++)
						if (typeid(*iss[i]) == typeid(Rechargeable) || typeid(*iss[i]) == typeid(�lectricalWire))
						{
							iss[i]->showInfo();
							cout << "\n" << iss[i]->getClassName() << "\n\n";
						}
					continue;

				case '3':

					system("cls");
					for (int i = 0; i < size; i++)
						if (typeid(*iss[i]) == typeid(Fishing))
						{
							iss[i]->showInfo();
							cout << "\n" << iss[i]->getClassName() << "\n\n";
						}
					continue;

				case '4':

					system("cls");
					for (int i = 0; i < size; i++)
						if (typeid(*iss[i]) == typeid(Rechargeable))
						{
							iss[i]->showInfo();
							cout << "\n" << iss[i]->getClassName() << "\n\n";
						}
					continue;

				case '5':

					system("cls");
					for (int i = 0; i < size; i++)
						if (typeid(*iss[i]) == typeid(�lectricalWire))
						{
							iss[i]->showInfo();
							cout << "\n" << iss[i]->getClassName() << "\n\n";
						}
					continue;

				default:
					continue;
				}
			}
			system("cls");
			choice = '0';

		case '2':

			system("cls");
			for (int i = 0; i < size; i++)
				if (iss[i]->price > var)
				{
					var = iss[i]->price;
					varObject = iss[i];
				}
			cout << "������������ ��������� ����� ��������� ����������: \n\n";
			varObject->showInfo();
			cout << "\n" << varObject->getClassName() << "\n\n";
			var = 0;
			varObject = nullptr;
			continue;

		case '3':

			system("cls");
			var = INT_MAX;
			for (int i = 0; i < size; i++)
				if (iss[i]->price < var && iss[i]->price != 0)
				{
					var = iss[i]->price;
					varObject = iss[i];
				}
			if (varObject == nullptr)
			{
				cout << "�� �����..." << endl;
				var = 0;
				continue;
			}
			cout << "����������� ��������� ����� ��������� ����������: \n\n";
			varObject->showInfo();
			cout << "\n" << varObject->getClassName() << "\n\n";
			var = 0;
			varObject = nullptr;
			continue;

		case '4':

			system("cls");
			for (int i = 0; i < size; i++)
			{
				if (iss[i]->getQ() > var)
				{
					var = iss[i]->getQ();
					varObject = iss[i];
				}
			}
			cout << "������������ ���������� �����������: \n\n";
			varObject->showInfo();
			cout << "\n" << varObject->getClassName() << "\n\n";
			var = 0;
			varObject = nullptr;
			continue;

		case '5':

			system("cls");
			var = INT_MAX;
			for (int i = 0; i < size; i++)
				if (iss[i]->getQ() < var && iss[i]->getQ() != 0)
				{
					var = iss[i]->getQ();
					varObject = iss[i];
				}
			if (varObject == nullptr)
			{
				cout << "�� �����..." << endl;
				var = 0;
				continue;
			}
			cout << "����������� ���������� �����������: \n\n";
			varObject->showInfo();
			cout << "\n" << varObject->getClassName() << "\n\n";
			var = 0;
			varObject = nullptr;
			continue;

		default:
			continue;
		}
	}
}
// ���� static ������� � Instrument ==============================================================



// ���� virtual ������� ������������� (������) ������ ============================================
void Electrical::initializeSpecialData()
{
	cout << "\n������� ������� ���������� (����� �����):" << endl;
	cin >> voltage;
}
// ��������������� ������� (������������ ��������� ����������)
bool Mechanical::isAlereadyChosen(const int currentIndex, const int* chosenIndexes, const int chosenLen)
{
	for (int i = 0; i < chosenLen; i++) if (chosenIndexes[i] == currentIndex) return true;
	return false;
}
void Mechanical::initializeSpecialData()
{
	int chosenLen = 0;
	int* chosenIndexes = new int;
	char choice = '0';
	while (choice != 'q')
	{
		system("cls");
		cout << "�������� ��������� ������� (�� ������):\n\n";
		for (int i = 0; i < matsExLen; i++)
		{
			if (!isAlereadyChosen(i, chosenIndexes, chosenLen))
			{
				cout << i + 1 << ": " << materialsExample[i] << endl;
			}
		}
		if (chosenLen > 0) cout << "\nQ: �����" << endl;
		if (chosenLen >= matsExLen) break;
		cin >> choice;
		if ((int(choice - '0' - 1) + 1) > matsExLen) continue;
		push_back(chosenIndexes, int(choice - '0' - 1), chosenLen);
		push_back(materials, materialsExample[int(choice - '0' - 1)], matsLen);
	}
	delete chosenIndexes;
}
void Fishing::initializeSpecialData()
{
	Mechanical::initializeSpecialData();
	cout << "\n�������� ����������" << endl;
	char c = '0';
	if (yesNo(c, "������� ��� ����������", "����������������")) isProfessional = '0';
	else isProfessional = '1';
}
void Rechargeable::initializeSpecialData()
{
	Electrical::initializeSpecialData();
	cout << "\n������� ������� ������������ (����� �����):" << endl;
	cin >> batteryCapacity;
}
void �lectricalWire::initializeSpecialData()
{
	Electrical::initializeSpecialData();
	cout << "\n������� ����� ������� (����� �����):" << endl;
	cin >> wireLength;
}
// ���� virtual ������� ������������� (������) ������ ============================================