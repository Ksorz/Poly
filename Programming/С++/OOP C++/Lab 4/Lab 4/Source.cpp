#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std; 

/*
Лабораторная работа №4. Разработка класса и переопределение операций.
Реализовать класс в соответствии с вариантом. Ввести следующие элементы класса (элементы, специфические для разных вариантов перечислены в таблице):
++++++++-	закрытые поля;
++++++++-	открытые методы доступа к полям;
++++++++-	конструкторы;
-	переопределения арифметических операций (+, -, +=, -=);
-	переопределение операций сравнения (>, <, ==);
++++++++-	переопределение операции преобразования типа;
++++++++- 	переопределение операции << для вывода на консоль;

Через консольное меню реализовать возможность взаимодействия с пользователем и проверки функциональности класса.

int V = abs(int(c1) - int(c2)) % 4, где с1 – первая буква фамилии на английском языке в верхнем регистре, 
с2 – первая буква имени на английском языке в верхнем регистре.

Вариант 3:
++++++++ Класс для работы с множествами чисел.
Поддерживаются операции пересечения множеств(+=), объединения(+), разности(-), нахождение уникальных элементов(-=),
++++++++ проверка наличия элемента в множестве
++++++++ Операция индексирования
++++++++ Деструктор
++++++++ Преобразование в тип int*
*/

class NSet // (задание) Класс для работы с множествами чисел
{

private: // (задание) закрытые поля

	int cardinality;
	int* set;

	void copy(int* from, int* to, int fSize) const // Функция копирования (from всегда >= to)
	{
		for (int i = 0; i < fSize; i++) to[i] = from[i];
	}

public:

	// (задание) конструкторы
	NSet() // конструктор по умолчанию (в данном случае пользователь выбирает как задать множество)
	{
		cout << "Укажите количество элементов множества" << endl;
		cin >> cardinality;
		system("cls");

		if (cardinality > 5 && cardinality <= 10)
		{
			cout << "Заполнить случайными значениями?" << endl;
			if (yesNo('y')) randomSetFilling();
			system("cls");
		}
		else if (cardinality > 10)
		{
			cout << "Довольно большое множество, лучше заполнить случайными значениями." << endl;
			randomSetFilling();
			system("cls");
		}
		else
		{
			set = new int[cardinality];
			for (int i = 0; i < cardinality; i++)
			{
				cout << "Элемент " << i + 1 << ":" << endl;
				cin >> set[i];
				system("cls");
			}
		}
	}
	NSet(const int cardinality, int* set = nullptr) : cardinality(cardinality), set(set) {} // конструктор с параметром мощности множества
	NSet(const NSet& other) // Конструктор копирования
	{ // В данном случае объекта ещё нет и мы его создаём
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
	}

	// (задание) Деструктор
	~NSet()
	{
		//cout << "[ Destructor ] " << "Множество, мощность: " << cardinality << " <" << this << ">" << endl;
		delete[] set;
	}

	// (задание) Переопределения
	friend std::ostream& operator<< (std::ostream& os, const NSet& p) // (задание) переопределение операции << для вывода на консоль
	{ // 1й аргумент (cout) - не объект класса, поэтому функция должна быть внешней
		os << "Мощность множества: " << p.cardinality;
		return os;
	}
	int operator[] (int i) const { return set[i]; } // (задание) Операция индексирования
	NSet operator= (NSet other) // Переопределение операции =
	{
		if (&other == this) return *this; // Проверяем на самоприсваивание 
		delete[] set; // Удаляем текущий объект (устраняем возможность утечки памяти)
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
		return *this;        
	}

	friend NSet operator+= (NSet& ns1, NSet& ns2) // Пересечение множеств
	{
		int newCard = 0; // мощность нового множества
		int* temp = new int[ns1.getCard()]; // временное множество (мощность не будет больше наименьшей из мощностей двух множеств)

		for (int i = 0; i < ns1.getCard(); i++)
		{
			if (ns2.isExist(ns1[i])) // если элемент существует в обоих множествах
			{
				newCard++;
				temp[i] = ns1[i]; // добавляем его во временное множество
			}
		}

		int* result = new int[newCard]; // новое множество нужного размера
		ns1.copy(temp, result, newCard); // копируем элементы из temp в новое множество
		delete[] temp;
		return NSet{ newCard, result }; // Возвращаем пересечение множеств
	}

	friend NSet operator+ (NSet& ns1, NSet& ns2) // Объединение множеств
	{
		int newCard = ns1.cardinality; // При объединении минимальная мощность будет равна большему из двух множеств
		int* temp = new int[ns1.cardinality + ns2.cardinality]; // Временное множество, способное вместить все элементы из двух
		ns1.copy(ns1.set, temp, ns1.cardinality); // Копируем все элементы одного из множеств (не важно какого именно)

		for (int i = 0, j = ns1.cardinality; i < ns2.cardinality; i++) // Пробегаем временное множество от элемента ns1.getCard() + 1 до конца, ...
		{                                                              // ... этот промежуток равен ns2.getCard(), поэтому i < ns2.getCard()
			if (!ns1.isExist(ns2[i])) // Если элемента нет, то... --- тут какаято фигня
			{
				newCard++; // ... увеличиваем минимальную мощность нового множества и ...
				temp[j] = ns2[i]; // ... добавляем элемент во временное множество
				j++;
			}
		}

		int* result = new int[newCard]; // новое множество нужного размера
		ns1.copy(temp, result, newCard); // копируем элементы из temp в новое множество
		delete[] temp;
		return NSet { newCard, result }; // Возвращаем объединение множеств
	}

	operator int* () // (задание) Преобразование в тип int*, переопределение операции преобразования типа
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

	// Методы
	// (задание) открытые методы доступа к полям

	

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
		else { cout << "Слишком большое множество, показывать не будем!" << endl; }
	}
	int getCard() const { return cardinality; }

	void randomSetFilling() // Заполнение массива случайными значениями
	{
		int min, max;
		cout << "Укажите диапозон значений:" << endl;
		cin >> min >> max;
		set = new int[cardinality];

		for (int i = 0; i < cardinality; i++)
		{
			set[i] = rnd(min, max);
		}
	}

	

	// (задание) проверка наличия элемента в множестве	
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
	cout << "Вариант: " << abs(int('L') - int('A')) % 4 << endl << endl;



	
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