#include <iostream> 
#include <Windows.h>
#include <string>

#include "Instrument.hpp"

using namespace std;

/*
Лабораторная работа №5. Наследование и полиморфизм

Реализовать иерархию классов для выбранного базового типа.
В качестве базового класса можно использовать вариант из таблицы, либо предложить свой собственный базовый класс и иерархию наследников(но отсутствующие в таблице).
Вариант для таблицы вычисляем по формуле : V = (int(c1) + int(c2)) % 8, где с1 и c2 – вторая буква в фамилии и имени на английском языке в верхнем регистре.

Вариант 3: Instrument

Задачи:
-- Помимо базового класса реализовать не менее 5 производных классов и, по крайней мере, 3 уровня в иерархии(н - р, класс С наследует B, а класс B наследует A).
-- В каждом классе ввести закрытые поля и открытые методы доступа к полям.
-- В базовом классе ввести виртуальные методы (н - р, toString, show), в производных классах ввести переопределения виртуальных методов.
-- Ввести статические элементы хотя бы в 3 классах (н - р, статическое поле - наибольший вес млекопитающего животного Mammal::MaximalWeight,
   статическая функция получения квадрата с заданной длиной стороны Square::GetSquare).
--- В главном модуле(с функцией main) ввести массив указателей на объекты базового класса. Число элементов массива можно задать константой(N >= 10)
--- или определять динамически в программе. Заполнить массив объектами разных типов. Выполнить обработку массива объектов для того, чтобы:
 -- подсчитать количество объектов каждого типа; для проверки типа объекта в массиве можно использовать операторы dynamic_cast или typeid;
 -- вывести информацию по каждому объекту, используя виртуальные методы базового класса(н - р, show или toString);
 -- найти объекты удовлетворяющие условию; например, найти студентов с самым ранним годом поступления (для варианта 0),
   найти четырехугольник с максимальной площадью(для варианта 4), найти млекопитающее животное с наибольшей длиной тела(для варианта 1), 
   найти самолёты с наибольшей максимальной скоростью(для варианта 6).
-- Предусмотреть освобождение динамической памяти.
*/




class Instrument
{	
protected:
	
	int itemQuantity;      // Обязательное
	string itemName;       // Обязательное
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
		cout << itemName << " (" << itemQuantity << " шт.) ";
		if (price != 0) cout << "Цена: " << price << " руб. ";
		else cout << "Цена не указана. ";
		if (model != "000") cout << "Модель: " << model;
		else cout << "Модель не указана";
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

string Instrument::className = "Инструмент";
string Electrical::className = "Электрический";
string Mechanical::className = "Механический";
string Rechargeable::className = "С аккумулятором";
string ElectricityGrid::className = "Питание от провода";




void showAll(const int size, Instrument** iss)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		iss[i]->showInfo();
		cout << endl << iss[i]->getName(true) << "\n\n";
	}		
}

bool yesNo(char& choice, string yes = "Продолжить", string no = "Завершить")
{
	cout << "\n" << yes << ": любая клавиша" << "\n" << no << ": 'Q'" << endl;
	cin >> choice;
	if (choice == 'q' || choice == 'Q') return false;
	return true;
}

void push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem)
{ 
	Instrument** newIss = new Instrument*[size + 1]; // Создаем новый массив

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
				cout << "Удалено:\n";
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
	cout << "\nВведите название:" << endl;
	getline(cin >> ws, name);
	cout << "Введите количество:" << endl;
	cin >> quantity;
	cout << "Ввести дополнительные сведения?" << endl;
	if (yesNo(choice, "Да", "Нет"))
	{
		cout << "Введите модель:" << endl;
		getline(cin >> ws, model);
		cout << "Введите цену:" << endl;
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
		cout << "Добавление нового инструмента" << endl;
		cout << "Выберите тип \n1: " << Mechanical::className << "\n2: " << Rechargeable::className << "\n3: " << ElectricityGrid::className << endl;
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
			
			cout << "Нет такого типа...\nПопробовать снова?" << endl;
			yesNo(choice, "Да", "Нет");
		}
		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << (int('E') + int('N')) % 8 << "\n\n";

	int issSize = 11;
	Instrument** iss = new Instrument*[issSize]; // iss (instruments)
	iss[0] = new Mechanical{ "Молоток", 28 };
	iss[1] = new Mechanical{ "Ножницы", 23 };
	iss[2] = new Mechanical{ "Отвертка", 41 };
	iss[3] = new Mechanical{ "Щипцы", 26 };
	iss[4] = new Mechanical{ "Пила", 19 };
	iss[5] = new Rechargeable{ "Дрель", 11 };
	iss[6] = new Rechargeable{ "Шуруповёрт", 9 };
	iss[7] = new Rechargeable{ "Заклёпочник", 7 };
	iss[8] = new ElectricityGrid{ "Паяльник", 18 };
	iss[9] = new ElectricityGrid{ "Дрель", 6 };
	iss[10] = new ElectricityGrid{ "Строительный фен", 4 };
	

	char choice = '0';
	while (choice != 'q')
	{
		cout << "\nПоказать все инструменты:                                  'S'" << endl;
		cout << "Типы и количество:                                         'A'" << endl;
		cout << "Добавить инструмент:                                       'N'" << endl;
		cout << "Удалить инструмент:                                        'D'\n" << endl;
		cout << "Выход:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case'a':
			system("cls");
			cout << Instrument::className << " (" << Instrument::getTotalQ() << " шт.):\n";
			cout << " • " << Mechanical::className << " (" << Mechanical::getTotalQ() << " шт.)\n";
			cout << " • " << Electrical::className << " (" << Electrical::getTotalQ() << " шт.)\n";
			cout << "   • " << Rechargeable::className << " (" << Rechargeable::getTotalQ() << " шт.)\n";
			cout << "   • " << ElectricityGrid::className << " (" << ElectricityGrid::getTotalQ() << " шт.)\n";
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
			cout << "Какой инструмент удаляем?" << endl;
			cin >> index;
			delete_iss(iss, issSize, index - 1);
		default:
			continue;
		}
	}


	return 0;
}