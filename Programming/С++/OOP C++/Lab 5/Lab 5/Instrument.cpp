#include <iostream> 
#include <Windows.h>
#include <string>
#include <climits>

#include "Instrument.hpp"

using namespace std;

// Глобальные константы ==========================================================================
static int const matsExLen = 4;
static string const materialsExample[matsExLen] = { "Пластик", "Металл" , "Дерево" , "Текстиль" };
// Глобальные константы ==========================================================================



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
// virtual функции (показать информацию)
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
// Показать все предметы
void Instrument::show_all(const int size, Instrument** iss)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		iss[i]->showInfo();
		cout << endl << iss[i]->getClassName() << "\n\n";
	}
}
// Отобразить статистику по имеющимся предметам
void Instrument::show_stat()
{
	cout << Instrument::className << " (" << Instrument::getTotalQ() << " шт.):\n";
	cout << " • " << Mechanical::className << " (" << Mechanical::getTotalQ() << " шт.)\n";
	cout << "   • " << Fishing::className << " (" << Fishing::getTotalQ() << " шт.)\n";
	cout << " • " << Electrical::className << " (" << Electrical::getTotalQ() << " шт.)\n";
	cout << "   • " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " шт.)\n";
	cout << "   • " << ЕlectricalWire::className << " (" << ЕlectricalWire::getTotalQ() << " шт.)\n";
}
// Добавить инструмент в конец списка
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
// Удалить инструмент из списка
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
				cout << "Удалено:\n";
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
// Инициализировать новый инструмент
void Instrument::create_new_item(Instrument**& iss, int& issSize)
{
	char choice = '0';
	int q, p;
	string n, m;
	while (choice != 'q')
	{
		system("cls");
		cout << "Добавление нового инструмента" << endl;
		cout << "Выберите тип \n\n1: " << Mechanical::className << "\n2: " << Fishing::className;
		cout << "\n3: " << Rechargeable::className << "\n4: " << ЕlectricalWire::className << "\n\nQ: Главное меню\n";
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
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;
			
		case'2':

		{
			Instrument::initializeData(n, q, m, p);
			Fishing* newItem = new Fishing(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		case'3':

		{
			Instrument::initializeData(n, q, m, p);
			Rechargeable* newItem = new Rechargeable(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		case'4':

		{

			Instrument::initializeData(n, q, m, p);
			ЕlectricalWire* newItem = new ЕlectricalWire(n, q, m, p);
			newItem->initializeSpecialData();
			Instrument::push_back_iss(iss, issSize, newItem);
		}
		yesNo(choice, "Добавить ещё", "Завершить");
		continue;

		default:

			continue;
		}
	}
}
// Инициализировать базовые сведения о предмете
void Instrument::initializeData(string& iName, int& iQuantity, string& mod, int& p)
{
	cout << "\nВведите название:" << endl;
	getline(cin >> ws, iName);
	cout << "\nВведите количество (целое число):" << endl;
	cin >> iQuantity;

	cout << "\nУказать дополнительные сведения?" << endl;
	char choice = '0';
	if (yesNo(choice, "Да", "Нет"))
	{
		cout << "\nУкажите название модели:" << endl;
		getline(cin >> ws, mod);
		cout << "\nУкажите цену (целое число):" << endl;
		cin >> p;
	}
}
// Функция поиска
void Instrument::search(const int size, Instrument** iss)
{
	char choice = '0';
	int var = 0;
	Instrument* varObject = nullptr;

	while (choice != 'q')
	{
		cout << "\nПоиск по типу:                                             '1'" << endl;
		cout << "Максимальная стоимость:                                    '2'" << endl;
		cout << "Минимальная стоимость:                                     '3'" << endl;
		cout << "Максимальное количество:                                   '4'" << endl;
		cout << "Минимальное количество:                                    '5'\n" << endl;
		cout << "Главное меню:                                              'Q'" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':

			while (choice != 'q')
			{
				cout << "\nМеханические:                                              '1'" << endl;
				cout << "Электрические:                                             '2'" << endl;
			
				cout << "Для рыбалки:                                               '3'" << endl;
				cout << "С аккумулятором:                                           '4'" << endl;
				cout << "С проводом:                                                '5'\n" << endl;
				cout << "Шаг назад:                                                 'Q'" << endl;
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
						if (typeid(*iss[i]) == typeid(Rechargeable) || typeid(*iss[i]) == typeid(ЕlectricalWire))
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
						if (typeid(*iss[i]) == typeid(ЕlectricalWire))
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
			cout << "Максимальную стоимость имеет следующий инструмент: \n\n";
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
				cout << "Не нашли..." << endl;
				var = 0;
				continue;
			}
			cout << "Минимальную стоимость имеет следующий инструмент: \n\n";
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
			cout << "Максимальное количество экземпляров: \n\n";
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
				cout << "Не нашли..." << endl;
				var = 0;
				continue;
			}
			cout << "Минимальное количество экземпляров: \n\n";
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
// Блок static функций в Instrument ==============================================================



// Блок virtual функций инициализации (правки) данных ============================================
void Electrical::initializeSpecialData()
{
	cout << "\nУкажите вольтаж устройства (целое число):" << endl;
	cin >> voltage;
}
// Вспомогательная функция (отслеживание выбранных материалов)
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
		if (chosenLen > 0) cout << "\nQ: Далее" << endl;
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
// Блок virtual функций инициализации (правки) данных ============================================