#include <iostream> 
#include <Windows.h>
#include <string>

using namespace std;

// ������� ������ (����� ���������� char)
bool yesNo(char* choice = nullptr, string message = "NONE", string y = "��", string n = "���")
{
	bool isNoChoice = false; // ��������, ����� �� choice
	if (choice == nullptr) { choice = new char; isNoChoice = true; } // ���� �� �����
	if (message != "NONE") cout << message << endl; // ���� �������� ���������, ������� ��� �� �����
	cout << "����� �������: " << y << endl;
	cout << "Q:             " << n << endl;
	cin >> *choice;
	if (*choice == 'q' || *choice == 'Q')
	{
		if (isNoChoice) delete choice;
		return false;
	}
	if (isNoChoice) delete choice;
	return true;
}