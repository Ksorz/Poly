#include <iostream> 
#include <Windows.h>
#include <string>

#include "Functions.hpp"

using namespace std; 

/*
Лабораторная работа №4. Разработка класса и переопределение операций.
Реализовать класс в соответствии с вариантом. Ввести следующие элементы класса (элементы, специфические для разных вариантов перечислены в таблице):
++++++++ закрытые поля;
++++++++ открытые методы доступа к полям;
++++++++ конструкторы;
++++++++ переопределения арифметических операций (+, -, +=, -=);
++++++++ переопределение операций сравнения (>, <, ==);
++++++++ переопределение операции преобразования типа;
++++++++ переопределение операции << для вывода на консоль;

Через консольное меню реализовать возможность взаимодействия с пользователем и проверки функциональности класса.

int V = abs(int(c1) - int(c2)) % 4, где с1 – первая буква фамилии на английском языке в верхнем регистре, 
с2 – первая буква имени на английском языке в верхнем регистре.

Вариант 3:
++++++++ Класс для работы с множествами чисел.
++++++++ Поддерживаются операции пересечения множеств(+=), объединения(+), разности(-), нахождение уникальных элементов(-=),
++++++++ проверка наличия элемента в множестве
++++++++ Операция индексирования
++++++++ Деструктор
++++++++ Преобразование в тип int*
*/

// =================================
// =================================
// Хотел реализовать пользовательское меню и расширенный функционал, но просто нет времени :(
// Не стал перемещать класс из Source.cpp чтоб всё было в одном месте и было проще проверить
// =================================
// =================================
class NSet // (задание) Класс для работы с множествами чисел
{
private: // (задание) закрытые поля

	int cardinality;
	int* set;
	// Функция копирования (from всегда >= to)
	void copy(int* from, int* to, int fSize) const 
	{
		for (int i = 0; i < fSize; i++) to[i] = from[i];
	}
	// (задание) проверка наличия элемента в множестве	
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
	// (задание) конструкторы
	NSet() // конструктор по умолчанию 
	{
		set = nullptr;
		int cardinality = 0;
		/*cout << "Укажите количество элементов множества" << endl; // (в данном случае пользователь выбирает как задать множество)
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
		}*/
	}
	// конструктор с параметром мощности множества
	NSet(const int cardinality, int* set = nullptr) : cardinality(cardinality), set(set) {}
	// Конструктор копирования
	NSet(const NSet& other)
	{ // В данном случае объекта ещё нет и мы его создаём
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
	}
	// (задание) Деструктор
	~NSet()
	{
		cout << "[ Destructor ] " << "Множество, мощность: " << cardinality << " <" << this << ">" << endl;
		delete[] set;
	}
	// (задание) Переопределения
	// (задание) переопределение операции (<<) для вывода на консоль
	friend std::ostream& operator<< (std::ostream& os, const NSet& p)
	{ // 1й аргумент (cout) - не объект класса, поэтому функция должна быть внешней
		os << "Мощность множества: " << p.cardinality;
		return os;
	}
	// (задание) Операция индексирования []
	int operator[] (int i) const { return set[i]; }
	// (задание) Преобразование в тип int*, переопределение операции преобразования типа
	operator int* ()
	{
		int* result = new int[this->getCard()];
		for (int i = 0; i < this->getCard(); i++) result[i] = set[i];
		return result;
	}
	// (задание) Переопределение операции (=)
	NSet operator= (NSet other) 
	{
		if (&other == this) return *this; // Проверяем на самоприсваивание 
		delete[] set; // Удаляем текущий объект (устраняем возможность утечки памяти)
		cardinality = other.getCard();
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) set[i] = other.set[i];
		return *this;        
	}
	// (задание) Переопределение операции (>)
	bool operator> (NSet& other)
	{
		if (getCard() > other.getCard()) return true; // Сравниваем мощности множеств
		return false;
	}
	// (задание) Переопределение операции (<)
	bool operator< (NSet& other)
	{
		if (getCard() < other.getCard()) return true; // Сравниваем мощности множеств
		return false;
	}
	// (задание) Переопределение операции (==)
	bool operator== (NSet& other)
	{
		if (getCard() == other.getCard()) // Сравниваем мощности множеств
		{
			for (int i = 0; i < other.getCard(); i++)
			{
				if (!isExist(other[i])) return false;
			}
			return true;
		}
		return false;
	}
	// (задание) Пересечение множеств (+=)
	NSet operator+= (NSet& other)
	{
		int newCard = 0; // мощность нового множества
		int* temp = new int[getCard()]; // временное множество (мощность не будет больше наименьшей из мощностей двух множеств)

		for (int i = 0; i < getCard(); i++)
		{
			if (other.isExist(getSet()[i])) // если элемент существует в обоих множествах ...
			{
				newCard++;
				temp[i] = getSet()[i]; // ... добавляем его во временное множество
			}
		}

		int* result = new int[newCard]; // новое множество нужного размера
		copy(temp, result, newCard); // копируем элементы из temp в новое множество
		delete[] temp;
		return NSet{ newCard, result }; // Возвращаем пересечение множеств
	}
	// (задание) Объединение множеств (+)
	NSet operator+ (NSet& other)
	{
		int newCard = getCard(); // При объединении минимальная мощность будет равна большему из двух множеств
		int* temp = new int[getCard() + other.getCard()]; // Временное множество, способное вместить все элементы из двух
		copy(getSet(), temp, getCard()); // Копируем все элементы одного из множеств (не важно какого именно)

		for (int i = 0, j = getCard(); i < other.getCard(); i++) // Пробегаем временное множество от элемента getCard() + 1 до конца, ...
		{                                                              // ... этот промежуток равен other.getCard(), поэтому i < other.getCard()
			if (!isExist(other[i])) // Если элемента нет, то...
			{
				newCard++; // ... увеличиваем минимальную мощность нового множества и ...
				temp[j++] = other[i]; // ... добавляем элемент во временное множество
			}
		}
		int* result = new int[newCard]; // новое множество нужного размера
		copy(temp, result, newCard); // копируем элементы из temp в новое множество
		delete[] temp;
		return NSet { newCard, result }; // Возвращаем объединение множеств
	}
	// (задание) нахождение уникальных элементов (-=)
	NSet operator-= (NSet& other) 
	{
		int newCard = 0; // мощность нового множества
		int* temp = new int[getCard() + other.getCard()]; // временное множество способное вместить все элементы из двух

		for (int i = 0; i < getCard(); i++)
		{
			if (!other.isExist(getSet()[i])) // Если элемена из 1 множества нет во 2 ...
			{
				temp[newCard++] = getSet()[i]; // ... то добавляем его во временный массив
			}
		}
		for (int i = 0; i < other.getCard(); i++)
		{   // Если элемента из 2 множества нет в 1 множества и во временном массива ...
			if (!isExist(other[i]) && !isExist(temp, newCard, other[i]))
			{
				temp[newCard++] = other[i]; // ... то добавляем его во временный массив
			}
		}
		int* result = new int[newCard]; // новое множество нужного размера
		copy(temp, result, newCard);
		delete[] temp;
		return NSet{ newCard, result };
	}
	// (задание) Разность множеств (некоммутативно) (-)
	NSet operator- (NSet& other)
	{
		int newCard = getCard(); // мощность нового множества
		int* temp = new int[getCard()]; // временное множество (мощность не может превышать наибольшую из двух)

		for (int i = 0, j = 0; i < other.getCard(); i++)
		{
			if (isExist(other[i])) // если элемент существует в обоих множествах ...
			{
				newCard--;
				temp[j++] = other[i]; // ... добавляем его во временное множество
			}
		}

		int* result = new int[newCard]; // новое множество нужного размера
		for (int i = 0, j = 0; i < getCard(); i++)      // (ns1.cardinality - newCard) - это заполненная часть temp, пробегаем по temp ...
		{
			if (!isExist(temp, getCard() - newCard, getSet()[i])) result[j++] = getSet()[i]; // getCard() - newCard это заполненная часть temp
			// ... если элемента из ns1 нет в массиве temp, то добавляем его в result. Количество добавленных элементов на данном этапе всегда будет = newCard
		}
		delete[] temp;
		return NSet { newCard, result };
	}
	// Методы
	// (задание) открытые методы доступа к полям
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
		else { cout << "Слишком большое множество, показывать не будем!" << endl; }
	}
	// Заполнение массива случайными значениями
	void randomSetFilling()
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
};
// MAIN ======================================================================================= MAIN
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << abs(int('L') - int('A')) % 4 << endl << endl;


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