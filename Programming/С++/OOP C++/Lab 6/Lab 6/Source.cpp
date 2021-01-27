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
������������ ������ �6. ������ � ������������ � ����������� STL
�������� ���������������� ��� �������� �������� �� �������, ���� ����������� ���� ����������� ���, ������������� � �������.
������� ��� ������� ��������� �� �������: V = (int(c1) + int(c2)) % 7, ��� �1 � c2 � ������ ����� � ������� � ����� �� ���������� ����� � ������� ��������.

������� 1: Book

� ������ ������� �� ������� ���� ��� ���� ������� ���� (�-�, int, string, float).
���������� ���������� ���� ��� ����������� ������ � ���������� �������� (����������, �������� � �����). 
� �������� ��������� ����� ������������ ��������� �� STL (vector, list, stack, map � �.�.).
����� ���������� ���� ���������� ����������� ���������� ��������� ��������: ���������� ���������, ����� ������������� ��� ������������ ��������
(�-�, ����� ������ � ���������� ������������), ���������� ��������������� �������� (�-�, ��������� ���������� ������� �� ���� ������), 
����� �������� �� ��������� ���� (�-�, ����� ������ �� �������), ����� ��������, ���������������� ������� (�-�, ����� ������� � ��������, ������� ��� 20 000 ��2). 
��� ���������� �������� ����������� ��������� STL (������������ ����� algorithm, functional): sort, min_element, transform, accumulate, for_each, find_if.
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
		cout << "���:      " << name << "\n���:      " << year << "\n�������:  " << pages << "\n����:     " << price << "$\n"; 
		cout << "�����(�): ";
		for (Author& author : authors)
		{
			cout << author.getName() << "; ";
		}
		cout << endl;
	}
	void addAuthor(Author author) { authors.push_back(author); }

	struct Search
	{
		int operator ()(const Book& a, string value) // ������� �������
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
		int operator ()(const Book& a, const Book& b) // ������� �������
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

�������������:

����� ��������� ������, ���������������� �� ��������. ������ �� �������... ��� ���� ���� ����� �� ��� 6 ����.
����� ���-�� ����������)

*/ //......................................................................................................................................................

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "�������: " << (int('L') + int('A')) % 7 << "\n\n";



	vector<Book> books;
	vector<Author> authors;

	authors.push_back(Author{ "���� ����", 0 });
	authors.push_back(Author{ "����� �������", 69 });
	authors.push_back(Author{ "������ �����", 49 });
	authors.push_back(Author{ "������ �����", 69 });
	authors.push_back(Author{ "���� ���������", 0 });
	authors.push_back(Author{ "��������� ������", 79 });
	authors.push_back(Author{ "�������� ������", 67 });
	authors.push_back(Author{ "����� �������", 85 }); // 7

	books.push_back(Book{ "������: ���������������� ������� ���������� � ����������", 1104, 2020, 22.5 });
	books.push_back(Book{ "������� ������", 603, 2016, 9.1f });
	books.push_back(Book{ "��� ������� ����", 346, 2019, 7.45f });
	books.push_back(Book{ "�����������", 223, 2016, 6 });
	books.push_back(Book{ "���������� ������ ���������", 197, 1988, 9.2f }); // / �. �. ������, �. �. ���������, �. �. �����. 
	books.push_back(Book{ "�������������� �����������", 654, 1967, 4.6f }); // / ��������� �. �., ������� �. �.
	books.push_back(Book{ "����������. ��� XXI", 608, 2016, 11.4f });
	books.push_back(Book{ "�������� ���������", 189, 1983, 3.2f }); // ������� �.�.
	
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
		cout << "\n����� � ����������� ���������� �������:                    '1'" << endl;
		cout << "�������� �������� ���� ����:                               '2'" << endl;
		cout << "����� ������ �� ���� ������                                '3'" << endl;
		cout << "���������� �� �������� ���-�� �������                      '4'" << endl;
		cout << "�������� ��� ����������:                                   '5'" << endl;
		cout << "����� �� ����:                                             '6'\n" << endl;
		cout << "�����:                                                     'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			system("cls"); // ��� ��������������� operator()
			{
				auto it = min_element(books.begin(), books.end(), Book::PgMin());

				it->showInfo();
			}
			continue;
		case '2':
			system("cls"); // ������ ���
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
			system("cls"); // ��� ������
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
			system("cls"); // ����� �������

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
			{ // �� �������... �������... �������� :D 
				Book b;
				float val;
				cout << "������� ����: " << endl;
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