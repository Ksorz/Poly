#include <iostream> 
#include <Windows.h>
#include <string>

#include "Instrument.hpp"

using namespace std;


static int const matsExLen = 4;
static string const materialsExample[matsExLen] = { "Пластик", "Металл" , "Дерево" , "Текстиль" };
// Блок свободных функций ========================================================================
bool yesNo(char& choice, string yes, string no)
{
	cout << yes << ": любая клавиша" << "\n" << no << ": 'Q'" << endl;
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
// Блок свободных функций ========================================================================

// Блок virtual showInfo() =======================================================================
void Instrument::showInfo() const
{
	cout << itemName;

	if (model != "000") cout << ", модель: \"" << model << "\"";
	cout << " (" << itemQuantity << " шт.) ";
	if (price != 0) cout << "\nЦена: за единицу - " << price << " руб., общая - " << totalPrice << " руб.";
	else cout << "Цена не указана.";
}
void Mechanical::showInfo() const
{
	Instrument::showInfo();
	if (matsLen > 0)
	{
		cout << "\nМатериалы: ";
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
		if (isProfessional == '1') cout << "\nПрофессиональное";
		else cout << "\nПодойдёт для начинающих";
	}
}
void Electrical::showInfo() const
{
	Instrument::showInfo();
	if (voltage > 0) cout << "\n" << voltage << " вольт";
}
void Rechargeable::showInfo() const
{
	Electrical::showInfo();
	if (batteryCapacity > 0) cout << ", " << batteryCapacity << " mAh";
}
void ЕlectricalWire::showInfo() const
{
	Electrical::showInfo();
	if (wireLength > 0) cout << ". Длина провода: " << wireLength << "м.";
}
// Блок virtual showInfo() =======================================================================

// Блок static функций в Instrument ==============================================================
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
	cout << Instrument::className << " (" << Instrument::getTotalQ() << " шт.):\n";
	cout << " • " << Mechanical::className << " (" << Mechanical::getTotalQ() << " шт.)\n";
	cout << " • " << Electrical::className << " (" << Electrical::getTotalQ() << " шт.)\n";
	cout << "   • " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " шт.)\n";
	cout << "   • " << ЕlectricalWire::className << " (" << ЕlectricalWire::getTotalQ() << " шт.)\n";
}
void Instrument::push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem)
{
	Instrument** newIss = new Instrument * [size + 1]; // Создаем новый массив

	for (int i = 0; i < size; i++)
	{
		newIss[i] = oldIss[i]; // Копируем элементы
	}

	newIss[size++] = newItem; // Включаем новый элемент
	delete[] oldIss;
	oldIss = newIss; // Переприсваиваем указатель
	system("cls");
	cout << "Добавлено:\n";
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
				cout << "Удалено:\n";
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
		cout << "Добавление нового инструмента" << endl;
		cout << "Выберите тип \n\n1: " << Mechanical::className << "\n2: " << Fishing::className;
		cout << "\n3: " << Rechargeable::className << "\n4: " << ЕlectricalWire::className << "\n\nQ: Главное меню\n";
		cin >> choice;
		

		switch (choice)
		{
		

		case'1':

		{
			Mechanical* newItem = new Mechanical;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;
			
		case'2':

		{
			Fishing* newItem = new Fishing;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		case'3':

		{
			Rechargeable* newItem = new Rechargeable;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		case'4':

		{
			ЕlectricalWire* newItem = new ЕlectricalWire;
			newItem->initializeData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		default:

			continue;
		}
	}
}
// Блок static функций в Instrument ==============================================================



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
	cout << "\nВведите название:" << endl;
	getline(cin >> ws, itemName);
	cout << "\nВведите количество (целое число):" << endl;
	cin >> itemQuantity;
	totalPrice = price * itemQuantity;
	
	cout << "\nУказать дополнительные сведения?" << endl;
	char choice = '0';
	if (yesNo(choice, "Да", "Нет"))
	{
		cout << "\nУкажите название модели:" << endl;
		getline(cin >> ws, model);
		cout << "\nУкажите цену (целое число):" << endl;
		cin >> price;
		totalPrice = price * itemQuantity;
		initializeSpecialData();
	}
	if (maxPrice < price) maxPrice = price;
}




void Electrical::initializeSpecialData()
{
	cout << "\nУкажите вольтаж устройства (целое число):" << endl;
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
		cout << "Выберите материалы изделия (по одному):\n\n";
		for (int i = 0; i < matsExLen; i++)
		{
			if (!isAlereadyChosen(i, chosenIndexes, chosenLen))
			{
				cout << i + 1 << ": " << materialsExample[i] << endl;
			}
		}
		if (chosenLen > 0) cout << "\nQ: Завершить" << endl;
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
	cout << "\nВыберите назначение" << endl;
	char c = '0';
	if (yesNo(c, "Подойдёт для начинающих", "Профессиональное")) isProfessional = '0';
	else isProfessional = '1';
}
void Rechargeable::initializeSpecialData()
{
	Electrical::initializeSpecialData();
	cout << "\nУкажите ёмкость аккумулятора (целое число):" << endl;
	cin >> batteryCapacity;
}
void ЕlectricalWire::initializeSpecialData()
{
	Electrical::initializeSpecialData();
	cout << "\nУкажите длину провода (целое число):" << endl;
	cin >> wireLength;
}




