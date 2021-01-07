#include <iostream> 
#include <Windows.h>
#include <string>

using namespace std;

// Функция выбора (может возвращать char)
bool yesNo(char* choice = nullptr, string message = "NONE", string y = "Да", string n = "Нет")
{
	bool isNoChoice = false; // Проверим, введён ли choice
	if (choice == nullptr) { choice = new char; isNoChoice = true; } // Если не введён
	if (message != "NONE") cout << message << endl; // Если добавили сообщение, выведем его на экран
	cout << "Любая клавиша: " << y << endl;
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