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
-- + Помимо базового класса реализовать не менее 5 производных классов и, по крайней мере, 3 уровня в иерархии(н - р, класс С наследует B, а класс B наследует A).
-- В каждом классе ввести закрытые поля и открытые методы доступа к полям.
-- + В базовом классе ввести виртуальные методы (н - р, toString, show), в производных классах ввести переопределения виртуальных методов.
-- + Ввести статические элементы хотя бы в 3 классах (н - р, статическое поле - наибольший вес млекопитающего животного Mammal::MaximalWeight,
     статическая функция получения квадрата с заданной длиной стороны Square::GetSquare).
--- + В главном модуле(с функцией main) ввести массив указателей на объекты базового класса. Число элементов массива можно задать константой(N >= 10)
--- + или определять динамически в программе. Заполнить массив объектами разных типов. Выполнить обработку массива объектов для того, чтобы:
 -- + подсчитать количество объектов каждого типа; для проверки типа объекта в массиве можно использовать операторы dynamic_cast или typeid;
 -- + вывести информацию по каждому объекту, используя виртуальные методы базового класса(н - р, show или toString);
 -- найти объекты удовлетворяющие условию; например, найти студентов с самым ранним годом поступления (для варианта 0),
   найти четырехугольник с максимальной площадью(для варианта 4), найти млекопитающее животное с наибольшей длиной тела(для варианта 1), 
   найти самолёты с наибольшей максимальной скоростью(для варианта 6).
-- + Предусмотреть освобождение динамической памяти.
*/


int Instrument::quantity = 0;        // Mechanical + Electrical
int Electrical::quantity = 0;        // Rechargeable + ElectricityGrid
int Mechanical::quantity = 0;
int Fishing::quantity = 0;
int Rechargeable::quantity = 0;
int ЕlectricalWire::quantity = 0;

string Instrument::className = "Инструмент";
string Electrical::className = "Электрический";
string Mechanical::className = "Механический";
string Fishing::className = "Рыбная ловля";
string Rechargeable::className = "С аккумулятором";
string ЕlectricalWire::className = "Питание от провода";



int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << (int('E') + int('N')) % 8 << "\n\n";

	string* v3000 = new string[2]{ "Платина", "Палладий" };


	static int issSize = 13;
	static Instrument** iss = new Instrument * [issSize]; // iss (instruments)
	

	iss[0] = new Mechanical{ "Молоток", 28, "Тор 666", 1499 };
	iss[1] = new Mechanical{ "Ножницы", 23 };
	iss[2] = new Mechanical{ "Отвертка", 1, "Вертухай 3000", 79999, v3000, 2 };
	iss[3] = new Mechanical{ "Щипцы", 26 };
	iss[4] = new Mechanical{ "Пила", 19 };
	iss[5] = new Fishing{ "Удочка", 14, "Посейдон junior", 3799 };
	iss[6] = new Fishing{ "Сеть", 3 };
	iss[7] = new Rechargeable{ "Дрель", 11 };
	iss[8] = new Rechargeable{ "Шуруповёрт", 9 };
	iss[9] = new Rechargeable{ "Заклёпочник", 7, "Печенег XL", 4999 };
	iss[10] = new ЕlectricalWire{ "Паяльник", 18, "Пояй over 9000", 1000, 220, 2.5 };
	iss[11] = new ЕlectricalWire{ "Дрель", 6 };
	iss[12] = new ЕlectricalWire{ "Строительный фен", 4, "Птеродактиль", 7999 };
	

	if (typeid(*iss[1]) == typeid(Mechanical)) cout << "YES YES YES" << endl;

	cout << typeid(*iss[1]).name() << endl;

	cout << typeid(*iss[5]).name() << endl;

	cout << typeid(*iss[9]).name() << endl;


	char choice = '0';
	while (choice != 'q')
	{

		cout << "\nТипы и количество:                                         '1'" << endl;
		cout << "Показать все инструменты:                                  '2'" << endl;
		cout << "Добавить инструмент:                                       '3'" << endl;
		cout << "Удалить инструмент:                                        '4'" << endl;
		cout << "Поиск:                                                     '5'\n" << endl;
		cout << "Выход:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case'1':
			system("cls");
			Instrument::show_stat();
			continue;
		case '2':
			system("cls");
			Instrument::show_all(issSize, iss);
			continue;
		case '3':
			system("cls");
			Instrument::create_new_item(iss, issSize);
			system("cls");
			continue;
		case '4':
			int index;
			system("cls");
			Instrument::show_all(issSize, iss);
			cout << "Какой инструмент удаляем?" << endl;
			cin >> index;
			Instrument::delete_item_iss(iss, issSize, index - 1);
			continue;
		case '5':
			system("cls");
			Instrument::search(issSize, iss);


			continue;
		default:
			continue;
		}
	}


	return 0;
}