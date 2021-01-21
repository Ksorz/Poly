#include <algorithm>
#include <list>

#include <iostream> 
#include <iomanip>

#include <vector>
#include <string>
#include <Windows.h>
#include <ctime> // ��� ������� time()
#include <cstdlib> // ��� ������� rand() � srand()

#include "Header.hpp"



class Person
{
public:

	Person(const char* s) { name = s; } //���������� � �������
	Person() { name = defaultName; } //����������� ��� ������
	~Person() {}
	static const char* defaultName;


private:
	string name;
};
class Student : public Person
{
public:
	Student(const char* s, int a) { } //���������� �� ����� �������
	Student(int a) { age = a; } //���������� � ������ ������
	Student() { age = 0; } //����������� ��� ������
	~Student() {};

private:
	int age;
};

class House
{
public:
	House();
	~House();

private:

};

House::House()
{
}

House::~House()
{
}







void f()
{
	throw "very bad";
	throw exception{ 0 };
	// throw exception; // ������
	throw exception{ "bad" };
}

void ff()
{
	throw "very bad";
	throw 0;
	// throw exception; // ������
	//exception().throw();
}

void d()
{
	
}


struct Parent { string name;  };
struct ParentX : virtual Parent {};
struct ParentY : virtual Parent {};
struct Child : ParentX, ParentY {};


template<class T>
int ff(T a)
{
	static int n = 0;
	n++;
	return n;
}




int main()
{
	try
	{
		d();
	}
	catch (out_of_range)
	{
		cout << 1;
	}
	catch (exception)
	{
		cout << 2;
	}

	catch (bad_cast)
	{
		cout << 3;
	}
	cout << 4; // ����� 14

	char* a = new char{ 'g' };
	int n = 1;






	try
	{
		d();
	}
	catch (const char* a)	{	}
	catch (int n)	        {	}
	// catch (int)             {} ������
	// catch ("dlksdksl")  	{	} ������







	

	string w[]{ "one", "two", "three" };

	list<int> lengths(4);

	transform(begin(w), end(w), begin(lengths), [](string word)
		{
			return word.length();
		}); // ������ ���









	Child child;
	child.name = "111111";                 // ������
	child.ParentX::name = "22222222";
	child.ParentY::name = "333333333";
	cout << child.name << endl;


	cout << "\n\n";

	

	ff(2);
	ff(3.0);
	int res = ff(-1);
	cout << res << endl; // 2









	Person* p = new Student;
	//House* m = dynamic_cast<House*>(p);


	return 0;
}