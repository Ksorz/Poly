#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <numeric>
#include <string>
#include <Windows.h>
#include <fstream>

#include "Book.hpp" 


/*
Лабораторная работа №6. Работа с контейнерами и алгоритмами STL
Выберите пользовательский тип согласно варианту из таблицы, либо используйте свой собственный тип, отсутствующий в таблице.
Вариант для таблицы вычисляем по формуле: V = (int(c1) + int(c2)) % 7, где с1 и c2 – первая буква в фамилии и имени на английском языке в верхнем регистре.

Вариант 1: Book

В классе введите по крайней мере три поля разного типа (н-р, int, string, float).
Реализуйте консольное меню для возможности работы с коллекцией объектов (добавление, удаление и вывод). 
В качестве коллекции можно использовать контейнер из STL (vector, list, stack, map и т.п.).
Через консольное меню реализуйте возможность выполнения следующих операций: сортировка элементов, поиск максимального или минимального элемента
(н-р, поиск города с наибольшей численностью), вычисление агрегированного значения (н-р, суммарное количество страниц по всем книгам), 
поиск элемента по заданному полу (н-р, поиск автора по фамилии), поиск элемента, удовлетворяющего условию (н-р, поиск острова с площадью, большей чем 20 000 км2). 
Для реализации операций используйте алгоритмы STL (заголовочные файлы algorithm, functional): sort, min_element, transform, accumulate, for_each, find_if.
*/

class Author
{
	string name;
	int age;

	bool isAlive = age;

public:

	Author(string n, int a) : name(n), age(a) {}

	string getName() const { return name; }

};
class Book
{

	string name;
	int year;
	int pages;
	float price;

	vector<Author> authors;

public:

	Book() {}
	Book(string n, int pg, int y, float pr) : name(n), year(y), pages(pg), price(pr) {}

	bool operator==(const Book& other) const
	{ 
		return this->price == other.getPrice(); 
	}


	string getName() const { return name; }
	int getYear() const { return year; }
	int getPages() const { return pages; }
	float getPrice() const { return price; }

	void setPrice(float p) { price = p; }

	void showInfo() 
	{ 
		cout << "Имя:      " << name << "\nГод:      " << year << "\nСтраниц:  " << pages << "\nЦена:     " << price << "$\n"; 
		cout << "Автор(ы): ";
		for (Author& author : authors)
		{
			cout << author.getName() << "; ";
		}
		cout << endl;
	}
	void addAuthor(Author author) { authors.push_back(author); }

	struct Search
	{
		int operator ()(const Book& a, string value) // Минимум страниц
		{
			for (auto& author : a.authors)
			{
				if (author.getName() == value) return true;
			}
			return false;
		}
	};
	struct PgMin
	{
		int operator ()(const Book& a, const Book& b) // Минимум страниц
		{
			return a.pages < b.pages;
		}
	};
};

bool compare(const Book& s1, const Book& s2)
{
	return s1.getPages() < s2.getPages();
}


/* ........................................................................................................................................................

Преподавателю:

Очень сумбурная работа, концентрировался на основном. Сильно не успевал... Был лишь один вечер на всю 6 лабу.
Вроде что-то получилось)

*/ //......................................................................................................................................................

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Вариант: " << (int('L') + int('A')) % 7 << "\n\n";



	vector<Book> books;
	vector<Author> authors;

	authors.push_back(Author{ "Джон Норт", 0 });
	authors.push_back(Author{ "Фрэнк Вильчек", 69 });
	authors.push_back(Author{ "Сергей Попов", 49 });
	authors.push_back(Author{ "Михаил Сажин", 69 });
	authors.push_back(Author{ "Яков Зельдович", 0 });
	authors.push_back(Author{ "Александр Долгов", 79 });
	authors.push_back(Author{ "Владимир Сурдин", 67 });
	authors.push_back(Author{ "Игорь Новиков", 85 }); // 7

	books.push_back(Book{ "Космос: Иллюстрированная история астрономии и космологии", 1104, 2020, 22.5 });
	books.push_back(Book{ "Красота физики", 603, 2016, 9.1f });
	books.push_back(Book{ "Все формулы мира", 346, 2019, 7.45f });
	books.push_back(Book{ "Супербъекты", 223, 2016, 6 });
	books.push_back(Book{ "Космология ранней Вселенной", 197, 1988, 9.2f }); // / А. Д. Долгов, Я. Б. Зельдович, М. В. Сажин. 
	books.push_back(Book{ "Релятивистская астрофизика", 654, 1967, 4.6f }); // / Зельдович Я. Б., Новиков И. Д.
	books.push_back(Book{ "Астрономия. Век XXI", 608, 2016, 11.4f });
	books.push_back(Book{ "Эволюция вселенной", 189, 1983, 3.2f }); // Новиков И.Д.
	
	books[0].addAuthor(authors[0]);
	books[1].addAuthor(authors[1]);
	books[2].addAuthor(authors[2]);
	books[3].addAuthor(authors[2]);
	books[4].addAuthor(authors[3]);
	books[4].addAuthor(authors[4]);
	books[4].addAuthor(authors[5]);
	books[5].addAuthor(authors[4]);
	books[5].addAuthor(authors[7]);
	books[6].addAuthor(authors[6]);
	books[7].addAuthor(authors[7]);




	char choice = '0';
	while (choice != 'q')
	{
		cout << "\nКнига с минимальным количество страниц:                    '1'" << endl;
		cout << "Показать названия всех книг:                               '2'" << endl;
		cout << "Сумма листов во всех книгах                                '3'" << endl;
		cout << "Сортировка по убыванию кол-ва страниц                      '4'" << endl;
		cout << "Показать всю информацию:                                   '5'" << endl;
		cout << "Найти по цене:                                             '6'\n" << endl;
		cout << "Выход:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			system("cls"); // Тут переопределение operator()
			{
				auto it = min_element(books.begin(), books.end(), Book::PgMin());

				it->showInfo();
			}
			continue;
		case '2':
			system("cls"); // Лямбда тут
			{
				int counter = 0;
				for_each(books.begin(), books.end(),
					[&counter](const Book x)
					{
						cout << ++counter << ") " << x.getName() << endl;
					});
			}
			continue;
		case '3':
			system("cls"); // Ещё лямбда
			{
				// its alive!!!!!!!!!
				int sum = 0;
				for_each(books.begin(), books.end(),
					[&sum](const Book x)
					{
						sum += x.getPages();
					});
				cout << sum << endl;

				cout << "Compare to ";
				int comareToIt = 0;
				for (auto& book : books) comareToIt += book.getPages();
				cout << comareToIt << endl;
			}
			continue;
		case '4':
			system("cls"); // Через функцию

			{
				stable_sort(books.begin(), books.end(), compare);
			}
	
			continue;
		case '5':
			system("cls");
			for (auto& item : books) {
				item.showInfo(); cout << endl;
			}

			continue;
		case '6':
			system("cls");
			{ // не успеваю... костыли... РАБОТАЕТ :D 
				Book b;
				float val;
				cout << "Введите цену: " << endl;
				cin >> val;
				b.setPrice(val);
				Book d;
				d = *find(books.begin(), books.end(), b);
				d.showInfo();
			}
			continue;
		default:
			continue;
		}
	}



	




	return 0;
}