#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std; 

/*
������������ ������ �4. ���������� ������ � ��������������� ��������.
����������� ����� � ������������ � ���������. ������ ��������� �������� ������ (��������, ������������� ��� ������ ��������� ����������� � �������):
++++++++-	�������� ����;
++++++++-	�������� ������ ������� � �����;
++++++++-	������������;
-	��������������� �������������� �������� (+, -, +=, -=);
-	��������������� �������� ��������� (>, <, ==);
++++++++-	��������������� �������� �������������� ����;
++++++++- 	��������������� �������� << ��� ������ �� �������;

����� ���������� ���� ����������� ����������� �������������� � ������������� � �������� ���������������� ������.

int V = abs(int(c1) - int(c2)) % 4, ��� �1 � ������ ����� ������� �� ���������� ����� � ������� ��������, 
�2 � ������ ����� ����� �� ���������� ����� � ������� ��������.

������� 3:
++++++++ ����� ��� ������ � ����������� �����.
�������������� �������� ����������� ��������(+=), �����������(+), ��������(-), ���������� ���������� ���������(-=),
++++++++ �������� ������� �������� � ���������
++++++++ �������� ��������������
++++++++ ����������
++++++++ �������������� � ��� int*
*/

class NSet // (�������) ����� ��� ������ � ����������� �����
{

private: // (�������) �������� ����

	int cardinality;
	int* set;

	void copy(int* from, int* to, int fSize) const // ������� ����������� (from ������ >= to)
	{
		for (int i = 0; i < fSize; i++) to[i] = from[i];
	}

public:

	// (�������) ������������
	NSet() // ����������� �� ��������� (� ������ ������ ������������ �������� ��� ������ ���������)
	{
		cout << "������� ���������� ��������� ���������" << endl;
		cin >> cardinality;
		system("cls");

		if (cardinality > 5 && cardinality <= 10)
		{
			cout << "��������� ���������� ����������?" << endl;
			if (yesNo('y')) randomSetFilling();
			system("cls");
		}
		else if (cardinality > 10)
		{
			cout << "�������� ������� ���������, ����� ��������� ���������� ����������." << endl;
			randomSetFilling();
			system("cls");
		}
		else
		{
			set = new int[cardinality];
			for (int i = 0; i < cardinality; i++)
			{
				cout << "������� " << i + 1 << ":" << endl;
				cin >> set[i];
				system("cls");
			}
		}
	}
	NSet(const int cardinality, int* set = nullptr) : cardinality(cardinality), set(set) {} // ����������� � ���������� �������� ���������
	NSet(const NSet& other) // ����������� �����������
	{ // � ������ ������ ������� ��� ��� � �� ��� ������
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
	}

	// (�������) ����������
	~NSet()
	{
		//cout << "[ Destructor ] " << "���������, ��������: " << cardinality << " <" << this << ">" << endl;
		delete[] set;
	}

	// (�������) ���������������
	friend std::ostream& operator<< (std::ostream& os, const NSet& p) // (�������) ��������������� �������� << ��� ������ �� �������
	{ // 1� �������� (cout) - �� ������ ������, ������� ������� ������ ���� �������
		os << "�������� ���������: " << p.cardinality;
		return os;
	}
	int operator[] (int i) const { return set[i]; } // (�������) �������� ��������������
	NSet operator= (NSet other) // ��������������� �������� =
	{
		if (&other == this) return *this; // ��������� �� ���������������� 
		delete[] set; // ������� ������� ������ (��������� ����������� ������ ������)
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
		return *this;        
	}

	friend NSet operator+= (NSet& ns1, NSet& ns2) // ����������� ��������
	{
		int newCard = 0; // �������� ������ ���������
		int* temp = new int[ns1.getCard()]; // ��������� ��������� (�������� �� ����� ������ ���������� �� ��������� ���� ��������)

		for (int i = 0; i < ns1.getCard(); i++)
		{
			if (ns2.isExist(ns1[i])) // ���� ������� ���������� � ����� ����������
			{
				newCard++;
				temp[i] = ns1[i]; // ��������� ��� �� ��������� ���������
			}
		}

		int* result = new int[newCard]; // ����� ��������� ������� �������
		ns1.copy(temp, result, newCard); // �������� �������� �� temp � ����� ���������
		delete[] temp;
		return NSet{ newCard, result }; // ���������� ����������� ��������
	}

	friend NSet operator+ (NSet& ns1, NSet& ns2) // ����������� ��������
	{
		int newCard = ns1.cardinality; // ��� ����������� ����������� �������� ����� ����� �������� �� ���� ��������
		int* temp = new int[ns1.cardinality + ns2.cardinality]; // ��������� ���������, ��������� �������� ��� �������� �� ����
		ns1.copy(ns1.set, temp, ns1.cardinality); // �������� ��� �������� ������ �� �������� (�� ����� ������ ������)

		for (int i = 0, j = ns1.cardinality; i < ns2.cardinality; i++) // ��������� ��������� ��������� �� �������� ns1.getCard() + 1 �� �����, ...
		{                                                              // ... ���� ���������� ����� ns2.getCard(), ������� i < ns2.getCard()
			if (!ns1.isExist(ns2[i])) // ���� �������� ���, ��... --- ��� ������� �����
			{
				newCard++; // ... ����������� ����������� �������� ������ ��������� � ...
				temp[j] = ns2[i]; // ... ��������� ������� �� ��������� ���������
				j++;
			}
		}

		int* result = new int[newCard]; // ����� ��������� ������� �������
		ns1.copy(temp, result, newCard); // �������� �������� �� temp � ����� ���������
		delete[] temp;
		return NSet { newCard, result }; // ���������� ����������� ��������
	}

	operator int* () // (�������) �������������� � ��� int*, ��������������� �������� �������������� ����
	{
		int* result = new int[cardinality];
		for (int i = 0; i < cardinality; i++) result[i] = set[i];
		return result;
	}

	



	/*
	NSet operator+ (NSet& other)
	{
		int* newSet = new int[cardinality + other.getCard()];
		NSet result { cardinality + other.getCard(), newSet };
		for (int i = 0; i < result.getCard(); i++)
		{

		}
	}
	*/

	// ������
	// (�������) �������� ������ ������� � �����

	

	void printSet() const
	{
		if (cardinality <= 800)
		{
			cout << "Cardinality == " << cardinality << "\n: ";
			for (int i = 0; i < cardinality; i++)
			{
				cout << set[i] << " : ";
				if ((i + 1) % 16 == 0) cout << endl << ": ";
			}
			cout << endl;
		}
		else { cout << "������� ������� ���������, ���������� �� �����!" << endl; }
	}
	int getCard() const { return cardinality; }

	void randomSetFilling() // ���������� ������� ���������� ����������
	{
		int min, max;
		cout << "������� �������� ��������:" << endl;
		cin >> min >> max;
		set = new int[cardinality];

		for (int i = 0; i < cardinality; i++)
		{
			set[i] = rnd(min, max);
		}
	}

	

	// (�������) �������� ������� �������� � ���������	
	bool isExist(const int element) const
	{
		for (int i = 0; i < cardinality; i++) if (set[i] == element) return true;
		return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << abs(int('L') - int('A')) % 4 << endl << endl;



	
	//double* a = new double[13]{ 3.14, 2.72, 6.28, 0.58, 1.62, 0.7, 299792458, 6.67, 6.63, 1.05, 1.6, 1.38, 7.2973e-3 };
	int* a = new int[16]{ 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 };
	int* b = new int[16]{ 0, -1, -2, -3, -5, -8, -13, -21, -34, -55, -89, -144, -233, -377, -610, -987 };
	NSet fe { 16, a };
	NSet rFe{ 16, b };


	
	cout << "checkCrossing" << endl;
	NSet checkCrossing = fe += rFe;
	checkCrossing.printSet();
	cout << "\n\n";
	cout << "checkCombination" << endl;
	NSet checkCombination = fe + rFe;
	checkCombination.printSet();



	cout << "\n\n";
	cout << "\n\n";
	cout << "\n\n";
	int* alpha = fe;
	alpha[15] = 1000;
	cout << fe << endl;
	fe.printSet();
	cout << "Indexing: " << fe[12] << endl;
	for (int i = 0; i < 16; i++) cout << alpha[i] << " : ";
	//system("cls");
	


	return 0;
}