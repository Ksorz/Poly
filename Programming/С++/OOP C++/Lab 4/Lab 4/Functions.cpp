#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std;

// Генерация случайных значений
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// Функция выбора
bool yesNo(char yes)
{
	char yesNo;
	cout << "Да:  " << yes << "\nНет: любая клавиша" << endl;
	cin >> yesNo;
	system("cls");
	if (yesNo == yes) return true;
	else return false;
}





