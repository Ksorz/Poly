#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std; 

/*
������������ ������ �4. ���������� ������ � ��������������� ��������.
����������� ����� � ������������ � ���������. ������ ��������� �������� ������ (��������, ������������� ��� ������ ��������� ����������� � �������):
++++++++ �������� ����;
++++++++ �������� ������ ������� � �����;
++++++++ ������������;
++++++++ ��������������� �������������� �������� (+, -, +=, -=);
++++++++ ��������������� �������� ��������� (>, <, ==);
++++++++ ��������������� �������� �������������� ����;
++++++++ ��������������� �������� << ��� ������ �� �������;

����� ���������� ���� ����������� ����������� �������������� � ������������� � �������� ���������������� ������.

int V = abs(int(c1) - int(c2)) % 4, ��� �1 � ������ ����� ������� �� ���������� ����� � ������� ��������, 
�2 � ������ ����� ����� �� ���������� ����� � ������� ��������.

������� 3:
++++++++ ����� ��� ������ � ����������� �����.
++++++++ �������������� �������� ����������� ��������(+=), �����������(+), ��������(-), ���������� ���������� ���������(-=),
++++++++ �������� ������� �������� � ���������
++++++++ �������� ��������������
++++++++ ����������
++++++++ �������������� � ��� int*
*/

// =================================
// =================================
// ����� ����������� ���������������� ���� � ����������� ����������, �� ������ ��� ������� :(
// �� ���� ���������� ����� �� Source.cpp ���� �� ���� � ����� ����� � ���� ����� ���������
// =================================
// =================================
class NSet // (�������) ����� ��� ������ � ����������� �����
{
private: // (�������) �������� ����

	int cardinality;
	int* set;
	// ������� ����������� (from ������ >= to)
	void copy(int* from, int* to, int fSize) const 
	{
		for (int i = 0; i < fSize; i++) to[i] = from[i];
	}
	// (�������) �������� ������� �������� � ���������	
	bool isExist(const int element) const
	{
		for (int i = 0; i < cardinality; i++) if (set[i] == element) return true;
		return false;
	}
	bool isExist(int* inThisArr, const int arrLen, const int element)
	{
		for (int i = 0; i < arrLen; i++) if (inThisArr[i] == element) return true;
		return false;
	}

public:
	// (�������) ������������
	NSet() // ����������� �� ��������� 
	{
		set = nullptr;
		int cardinality = 0;
		/*cout << "������� ���������� ��������� ���������" << endl; // (� ������ ������ ������������ �������� ��� ������ ���������)
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
		}*/
	}
	// ����������� � ���������� �������� ���������
	NSet(const int cardinality, int* set = nullptr) : cardinality(cardinality), set(set) {}
	// ����������� �����������
	NSet(const NSet& other)
	{ // � ������ ������ ������� ��� ��� � �� ��� ������
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
	}
	// (�������) ����������
	~NSet()
	{
		cout << "[ Destructor ] " << "���������, ��������: " << cardinality << " <" << this << ">" << endl;
		delete[] set;
	}
	// (�������) ���������������
	// (�������) ��������������� �������� (<<) ��� ������ �� �������
	friend std::ostream& operator<< (std::ostream& os, const NSet& p)
	{ // 1� �������� (cout) - �� ������ ������, ������� ������� ������ ���� �������
		os << "�������� ���������: " << p.cardinality;
		return os;
	}
	// (�������) �������� �������������� []
	int operator[] (int i) const { return set[i]; }
	// (�������) �������������� � ��� int*, ��������������� �������� �������������� ����
	operator int* ()
	{
		int* result = new int[this->getCard()];
		for (int i = 0; i < this->getCard(); i++) result[i] = set[i];
		return result;
	}
	// (�������) ��������������� �������� (=)
	NSet operator= (NSet other) 
	{
		if (&other == this) return *this; // ��������� �� ���������������� 
		delete[] set; // ������� ������� ������ (��������� ����������� ������ ������)
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
		return *this;        
	}
	// (�������) ��������������� �������� (>)
	bool operator> (NSet& other)
	{
		if (getCard() > other.getCard()) return true; // ���������� �������� ��������
		return false;
	}
	// (�������) ��������������� �������� (<)
	bool operator< (NSet& other)
	{
		if (getCard() < other.getCard()) return true; // ���������� �������� ��������
		return false;
	}
	// (�������) ��������������� �������� (==)
	bool operator== (NSet& other)
	{
		if (getCard() == other.getCard()) // ���������� �������� ��������
		{
			for (int i = 0; i < other.getCard(); i++)
			{
				if (!isExist(other[i])) return false;
			}
			return true;
		}
		return false;
	}
	// (�������) ����������� �������� (+=)
	NSet operator+= (NSet& other)
	{
		int newCard = 0; // �������� ������ ���������
		int* temp = new int[getCard()]; // ��������� ��������� (�������� �� ����� ������ ���������� �� ��������� ���� ��������)

		for (int i = 0; i < getCard(); i++)
		{
			if (other.isExist(getSet()[i])) // ���� ������� ���������� � ����� ���������� ...
			{
				newCard++;
				temp[i] = getSet()[i]; // ... ��������� ��� �� ��������� ���������
			}
		}

		int* result = new int[newCard]; // ����� ��������� ������� �������
		copy(temp, result, newCard); // �������� �������� �� temp � ����� ���������
		delete[] temp;
		return NSet{ newCard, result }; // ���������� ����������� ��������
	}
	// (�������) ����������� �������� (+)
	NSet operator+ (NSet& other)
	{
		int newCard = getCard(); // ��� ����������� ����������� �������� ����� ����� �������� �� ���� ��������
		int* temp = new int[getCard() + other.getCard()]; // ��������� ���������, ��������� �������� ��� �������� �� ����
		copy(getSet(), temp, getCard()); // �������� ��� �������� ������ �� �������� (�� ����� ������ ������)

		for (int i = 0, j = getCard(); i < other.getCard(); i++) // ��������� ��������� ��������� �� �������� getCard() + 1 �� �����, ...
		{                                                              // ... ���� ���������� ����� other.getCard(), ������� i < other.getCard()
			if (!isExist(other[i])) // ���� �������� ���, ��...
			{
				newCard++; // ... ����������� ����������� �������� ������ ��������� � ...
				temp[j++] = other[i]; // ... ��������� ������� �� ��������� ���������
			}
		}
		int* result = new int[newCard]; // ����� ��������� ������� �������
		copy(temp, result, newCard); // �������� �������� �� temp � ����� ���������
		delete[] temp;
		return NSet { newCard, result }; // ���������� ����������� ��������
	}
	// (�������) ���������� ���������� ��������� (-=)
	NSet operator-= (NSet& other) 
	{
		int newCard = 0; // �������� ������ ���������
		int* temp = new int[getCard() + other.getCard()]; // ��������� ��������� ��������� �������� ��� �������� �� ����

		for (int i = 0; i < getCard(); i++)
		{
			if (!other.isExist(getSet()[i])) // ���� ������� �� 1 ��������� ��� �� 2 ...
			{
				temp[newCard++] = getSet()[i]; // ... �� ��������� ��� �� ��������� ������
			}
		}
		for (int i = 0; i < other.getCard(); i++)
		{   // ���� �������� �� 2 ��������� ��� � 1 ��������� � �� ��������� ������� ...
			if (!isExist(other[i]) && !isExist(temp, newCard, other[i]))
			{
				temp[newCard++] = other[i]; // ... �� ��������� ��� �� ��������� ������
			}
		}
		int* result = new int[newCard]; // ����� ��������� ������� �������
		copy(temp, result, newCard);
		delete[] temp;
		return NSet{ newCard, result };
	}
	// (�������) �������� �������� (��������������) (-)
	NSet operator- (NSet& other)
	{
		int newCard = getCard(); // �������� ������ ���������
		int* temp = new int[getCard()]; // ��������� ��������� (�������� �� ����� ��������� ���������� �� ����)

		for (int i = 0, j = 0; i < other.getCard(); i++)
		{
			if (isExist(other[i])) // ���� ������� ���������� � ����� ���������� ...
			{
				newCard--;
				temp[j++] = other[i]; // ... ��������� ��� �� ��������� ���������
			}
		}

		int* result = new int[newCard]; // ����� ��������� ������� �������
		for (int i = 0, j = 0; i < getCard(); i++)      // (ns1.cardinality - newCard) - ��� ����������� ����� temp, ��������� �� temp ...
		{
			if (!isExist(temp, getCard() - newCard, getSet()[i])) result[j++] = getSet()[i]; // getCard() - newCard ��� ����������� ����� temp
			// ... ���� �������� �� ns1 ��� � ������� temp, �� ��������� ��� � result. ���������� ����������� ��������� �� ������ ����� ������ ����� = newCard
		}
		delete[] temp;
		return NSet { newCard, result };
	}
	// ������
	// (�������) �������� ������ ������� � �����
	int getCard() const { return cardinality; }
	int* getSet() const { return set; }

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
	// ���������� ������� ���������� ����������
	void randomSetFilling()
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
};
// MAIN ======================================================================================= MAIN
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << abs(int('L') - int('A')) % 4 << endl << endl;


	int* a = new int[16]{ 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 };
	int* b = new int[16]{ 0, -1, -2, -3, -5, -8, -13, -21, -34, -55, -89, -144, -233, -377 };
	int* c = new int[5]{ 1, 2, 3, 4, 5 };
	int* d = new int[5]{ 1, 2, 3, 4, 7 };
	NSet fe { 16, a };
	NSet rFe { 14, b };
	NSet five { 5, c };
	NSet anotherFive { 5, d };


	cout << "checkCrossing" << endl;
	NSet checkCrossing = fe += rFe;
	checkCrossing.printSet();
	cout << "\n\n";
	cout << "checkCombination" << endl;
	NSet checkCombination = fe + rFe;
	checkCombination.printSet();
	cout << "\n\n";
	cout << "checkDifference" << endl;
	NSet checkDifference = rFe - fe;
	checkDifference.printSet();
	cout << "\n\n";
	cout << "checkDifference 2" << endl;
	NSet checkDifference2 = fe - rFe - five;
	checkDifference2.printSet();
	cout << "\n\n";
	cout << "symmetricDifference" << endl;
	NSet symmetricDifference = fe -= rFe;
	symmetricDifference.printSet();
	cout << "\n\n";
	   
	cout << ">" << endl;
	if (rFe > five && symmetricDifference > five && fe > checkCrossing) cout << "this is true" << endl;
	if (rFe > fe || checkDifference2 > fe || rFe > symmetricDifference) cout << "this is false" << endl;
	cout << "\n\n";
	cout << "<" << endl;
	if (rFe < fe && anotherFive < rFe && five < symmetricDifference) cout << "this is true" << endl;
	if (fe < fe || five < anotherFive || checkCombination < checkCrossing) cout << "this is false" << endl;
	cout << "\n\n";
	cout << "==" << endl;
	if (fe == fe && rFe == rFe && five == five && checkDifference == checkDifference) cout << "this is true" << endl;
	if (fe == rFe || five == fe || rFe == five || anotherFive == five) cout << "this is false" << endl;

	cout << "\n\n";
	cout << "int* = NSet" << endl;
	int* alpha = fe;
	alpha[15] = 1000;
	for (int i = 0; i < 16; i++) cout << alpha[i] << " : ";	
	cout << "\n\n\n\n";
	//system("cls");

	return 0;
}