#include <iostream> 
#include <Windows.h>
#include <string>

#include "Instrument.hpp"

using namespace std;


static int const matsExLen = 4;
static string const materialsExample[matsExLen] = { "�������", "������" , "������" , "��������" };
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
void Instrument::show_all(const int size, Instrument** iss)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		iss[i]->showInfo();
		cout << endl << iss[i]->getClassName() << "\n\n";
	}
}
void Instrument::show_stat()
{
	cout << Instrument::className << " (" << Instrument::getTotalQ() << " ��.):\n";
	cout << " � " << Mechanical::className << " (" << Mechanical::getTotalQ() << " ��.)\n";
	cout << " � " << Electrical::className << " (" << Electrical::getTotalQ() << " ��.)\n";
	cout << "   � " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " ��.)\n";
	cout << "   � " << �lectricalWire::className << " (" << �lectricalWire::getTotalQ() << " ��.)\n";
}
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
void Instrument::delete_item_iss(Instrument**& oldIss, int& size, int index)
{
	bool siDeleted = false;
	Instrument** newIss = new Instrument * [--size];

	for (int i = 0; i < size + 1; i++)
	{
		if (!siDeleted)
		{
			if (i == index)
			{
				system("cls");
				cout << "�������:\n";
				oldIss[index]->showInfo();
				cout << endl << oldIss[index]->getClassName() << "\n\n";
				delete oldIss[index];
				siDeleted = true;
				continue;
			}
			newIss[i] = oldIss[i];
		}
		else newIss[i - 1] = oldIss[i];
	}

	delete[] oldIss;
	oldIss = newIss;
}
void Instrument::create_new_item(Instrument**& iss, int& issSize)
{
	char choice = '0';
	while (choice != 'q')
	{
		system("cls");
		cout << "���������� ������ �����������" << endl;
		cout << "�������� ��� \n\n1: " << Mechanical::className << "\n2: " << Fishing::className;
		cout << "\n3: " << Rechargeable::className << "\n4: " << �lectricalWire::className << "\n\nQ: ������� ����\n";
		cin >> choice;
		

		switch (choice)
		{
		

		case'1':

		{
			Mechanical* newItem = new Mechanical;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;
			
		case'2':

		{
			Fishing* newItem = new Fishing;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		case'3':

		{
			Rechargeable* newItem = new Rechargeable;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		case'4':

		{
			�lectricalWire* newItem = new �lectricalWire;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "�������� ���", "���������");
		continue;

		default:

			continue;
		}
	}
}
// ���� static ������� � Instrument ==============================================================



void Instrument::renewHighestPrice(const int size, Instrument** iss)
{
	maxPrice = 0;
	for (int i = 0; i < size; i++)
		if (is_same<decltype(iss[i]), class Instrument>::value&& iss[i]->getMaxPrice() > maxPrice)
		{
			maxPrice = iss[i]->getMaxPrice();
			maxPriceTool = *this;
		}
}
void Mechanical::renewHighestPrice(const int size, Instrument** iss)
{
	maxPrice = 0;
	for (int i = 0; i < size; i++)
		if (is_same<decltype(iss[i]), class Mechanical>::value&& iss[i]->getMaxPrice() > maxPrice)
		{
			maxPrice = iss[i]->getMaxPrice();
			maxPriceTool = *this;
		}
}
void Electrical::renewHighestPrice(const int size, Instrument** iss)
{
	maxPrice = 0;
	for (int i = 0; i < size; i++)
		if (is_same<decltype(iss[i]), class Electrical>::value && iss[i]->getMaxPrice() > maxPrice) 
		{
			maxPrice = iss[i]->getMaxPrice();
			maxPriceTool = *this;
		}
}





void Instrument::initializeData()
{
	cout << "\n������� ��������:" << endl;
	getline(cin >> ws, itemName);
	cout << "\n������� ���������� (����� �����):" << endl;
	cin >> itemQuantity;
	totalPrice = price * itemQuantity;
	
	cout << "\n������� �������������� ��������?" << endl;
	char choice = '0';
	if (yesNo(choice, "��", "���"))
	{
		cout << "\n������� �������� ������:" << endl;
		getline(cin >> ws, model);
		cout << "\n������� ���� (����� �����):" << endl;
		cin >> price;
		totalPrice = price * itemQuantity;
		initializeSpecialData();
	}
	if (maxPrice < price) maxPrice = price;
}




void Electrical::initializeSpecialData()
{
	cout << "\n������� ������� ���������� (����� �����):" << endl;
	cin >> voltage;
}
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
		if (chosenLen > 0) cout << "\nQ: ���������" << endl;
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




