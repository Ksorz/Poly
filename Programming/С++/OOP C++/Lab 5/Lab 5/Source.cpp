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
-- ������ �������� ������ ����������� �� ����� 5 ����������� ������� �, �� ������� ����, 3 ������ � ��������(� - �, ����� � ��������� B, � ����� B ��������� A).
-- � ������ ������ ������ �������� ���� � �������� ������ ������� � �����.
-- � ������� ������ ������ ����������� ������ (� - �, toString, show), � ����������� ������� ������ ��������������� ����������� �������.
-- ������ ����������� �������� ���� �� � 3 ������� (� - �, ����������� ���� - ���������� ��� �������������� ��������� Mammal::MaximalWeight,
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




class Instrument
{	
protected:
	
	int itemQuantity;      // ������������
	string itemName;       // ������������
	string model;
	int price;
	static int quantity;

public:

	static string className;
	Instrument() {}
	Instrument(string n, int q, string m, int p) : itemQuantity(q), itemName(n), model(m), price(p) { quantity += q; }
	virtual ~Instrument() {};

	void showInfo() const
	{
		cout << itemName << " (" << itemQuantity << " ��.) ";
		if (price != 0) cout << "����: " << price << " ���. ";
		else cout << "���� �� �������. ";
		if (model != "000") cout << "������: " << model;
		else cout << "������ �� �������";
	}
	inline static int getTotalQ() { return quantity; }
	int getQ() { return itemQuantity; }
	virtual string getName(bool ClassName = false) { return className; } // inline
};

class Electrical : public Instrument
{
protected:

	static int quantity;

public:

	static string className;
	Electrical() {}
	Electrical(string n, int q, string m, int p) : Instrument(n, q, m, p) { quantity += q; }
	virtual ~Electrical() {};

	inline static int getTotalQ() { return quantity; }
	virtual string getName(bool ClassName = false) { return className; }
};






class Mechanical : public Instrument
{
protected:

	static int quantity;

public:

	static string className;
	Mechanical() {}
	Mechanical(string n, int q, string m = "000", int p = 0) : Instrument(n, q, m, p) { quantity += q; }
	~Mechanical() 
	{
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
	}

	inline static int getTotalQ() { return quantity; }
	string getName(bool ClassName = false)
	{ 
		if (ClassName) return Instrument::getName() + ". " + className;
		return itemName;
	}
};

class Rechargeable : public Electrical
{	
protected:

	static int quantity;

public:

	static string className;
	Rechargeable() {}
	Rechargeable(string n, int q, string m = "000", int p = 0) : Electrical(n, q, m, p) { quantity += q; }
	~Rechargeable()
	{ 
		Electrical::quantity -= itemQuantity;
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity; 
	}

	inline static int getTotalQ() { return quantity; }
	string getName(bool ClassName = false)
	{
		if (ClassName) return Instrument::getName() + ". " + Electrical::getName() + ". " + className;
		return itemName;
	}
};

class ElectricityGrid : public Electrical
{
protected:

	static int quantity;

public:

	static string className;
	ElectricityGrid() {}
	ElectricityGrid(string n, int q, string m = "000", int p = 0) : Electrical(n, q, m, p) { quantity += q; }
	~ElectricityGrid()
	{
		Electrical::quantity -= itemQuantity;
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
	}

	inline static int getTotalQ() { return quantity; }
	string getName(bool ClassName = false)
	{
		if (ClassName) return Instrument::getName() + ". " + Electrical::getName() + ". " + className;
		return itemName;
	}
};


int Instrument::quantity = 0;        // Mechanical + Electrical
int Electrical::quantity = 0;        // Rechargeable + ElectricityGrid
int Mechanical::quantity = 0;
int Rechargeable::quantity = 0;
int ElectricityGrid::quantity = 0;

string Instrument::className = "����������";
string Electrical::className = "�������������";
string Mechanical::className = "������������";
string Rechargeable::className = "� �������������";
string ElectricityGrid::className = "������� �� �������";




void showAll(const int size, Instrument** iss)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		iss[i]->showInfo();
		cout << endl << iss[i]->getName(true) << "\n\n";
	}		
}

bool yesNo(char& choice, string yes = "����������", string no = "���������")
{
	cout << "\n" << yes << ": ����� �������" << "\n" << no << ": 'Q'" << endl;
	cin >> choice;
	if (choice == 'q' || choice == 'Q') return false;
	return true;
}

void push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem)
{ 
	Instrument** newIss = new Instrument*[size + 1]; // ������� ����� ������

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
	cout << endl << newIss[size - 1]->getName(true) << "\n\n";
}

void delete_iss(Instrument**& oldIss, int& size, int index)
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
				cout << endl << oldIss[index]->getName(true) << "\n\n";
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

void initializeData(string& name, int& quantity, string& model, int& price, char& choice)
{
	cout << "\n������� ��������:" << endl;
	getline(cin >> ws, name);
	cout << "������� ����������:" << endl;
	cin >> quantity;
	cout << "������ �������������� ��������?" << endl;
	if (yesNo(choice, "��", "���"))
	{
		cout << "������� ������:" << endl;
		getline(cin >> ws, model);
		cout << "������� ����:" << endl;
		cin >> price;
	}
	choice = '0';
}

void createNewItem(Instrument**& iss, int& issSize)
{
	char choice = '0';
	string name, model;
	int quantity, price;
	
	while (choice != 'q')
	{
		system("cls");
		cout << "���������� ������ �����������" << endl;
		cout << "�������� ��� \n1: " << Mechanical::className << "\n2: " << Rechargeable::className << "\n3: " << ElectricityGrid::className << endl;
		cin >> choice;
		model = "000";
		price = 0;

		switch (choice)
		{
		case'1':

			initializeData(name, quantity, model, price, choice);
			{ Mechanical* newItem = new Mechanical{ name, quantity, model, price };
			push_back_iss(iss, issSize, newItem); }
			yesNo(choice);
			continue;

		case'2':

			initializeData(name, quantity, model, price, choice);
			{ Rechargeable* newItem = new Rechargeable{ name, quantity, model, price };
			push_back_iss(iss, issSize, newItem); }
			yesNo(choice);
			continue;

		case'3':

			initializeData(name, quantity, model, price, choice);
			{ ElectricityGrid* newItem = new ElectricityGrid{ name, quantity, model, price };
			push_back_iss(iss, issSize, newItem); }
			yesNo(choice);
			continue;

		default:
			
			cout << "��� ������ ����...\n����������� �����?" << endl;
			yesNo(choice, "��", "���");
		}
		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << (int('E') + int('N')) % 8 << "\n\n";

	int issSize = 11;
	Instrument** iss = new Instrument*[issSize]; // iss (instruments)
	iss[0] = new Mechanical{ "�������", 28 };
	iss[1] = new Mechanical{ "�������", 23 };
	iss[2] = new Mechanical{ "��������", 41 };
	iss[3] = new Mechanical{ "�����", 26 };
	iss[4] = new Mechanical{ "����", 19 };
	iss[5] = new Rechargeable{ "�����", 11 };
	iss[6] = new Rechargeable{ "���������", 9 };
	iss[7] = new Rechargeable{ "����������", 7 };
	iss[8] = new ElectricityGrid{ "��������", 18 };
	iss[9] = new ElectricityGrid{ "�����", 6 };
	iss[10] = new ElectricityGrid{ "������������ ���", 4 };
	

	char choice = '0';
	while (choice != 'q')
	{
		cout << "\n�������� ��� �����������:                                  'S'" << endl;
		cout << "���� � ����������:                                         'A'" << endl;
		cout << "�������� ����������:                                       'N'" << endl;
		cout << "������� ����������:                                        'D'\n" << endl;
		cout << "�����:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case'a':
			system("cls");
			cout << Instrument::className << " (" << Instrument::getTotalQ() << " ��.):\n";
			cout << " � " << Mechanical::className << " (" << Mechanical::getTotalQ() << " ��.)\n";
			cout << " � " << Electrical::className << " (" << Electrical::getTotalQ() << " ��.)\n";
			cout << "   � " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " ��.)\n";
			cout << "   � " << ElectricityGrid::className << " (" << ElectricityGrid::getTotalQ() << " ��.)\n";
			yesNo(choice);
			system("cls");
			continue;
		case 's':
			system("cls");
			showAll(issSize, iss);
			yesNo(choice);
			system("cls");
			continue;
		case 'n':
			system("cls");
			createNewItem(iss, issSize);
			continue;
		case 'd':
			int index;
			system("cls");
			showAll(issSize, iss);
			cout << "����� ���������� �������?" << endl;
			cin >> index;
			delete_iss(iss, issSize, index - 1);
		default:
			continue;
		}
	}


	return 0;
}