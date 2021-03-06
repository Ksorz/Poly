// -- ������������ �����
// iostream: ������, ������� � ���������� ��� ����������� �����-������
#include <iostream> 
/* climits: ���������� ��������� � ������������� �������������� ���� ������ ��� ���������� ������� � �����������
CHAR_BIT	���������� ��� � ������� ���� char.	 8
SCHAR_MIN	����������� �������� ������� ���� signed char. - 128
SCHAR_MAX	������������ �������� ������� ���� signed char.	127
UCHAR_MAX	������������ �������� ������� ���� unsigned char.	255
CHAR_MIN	����������� �������� ������� ���� char. - 128
CHAR_MAX	������������ �������� ������� ���� char.	127
MB_LEN_MAX	������������ ���������� ������ �������������� �������, ������ �����.	16
SHRT_MIN	����������� �������� ������� ���� short int. - 32768
SHRT_MAX	������������ �������� ������� ���� short int.	32767
USHRT_MAX	������������ �������� ������� ���� unsigned short int.	65535
INT_MIN	    ����������� �������� ������� ���� int. - 32767
INT_MAX	    ������������ �������� ������� ���� int.	2147483647
UINT_MAX	������������ �������� ������� ���� unsigned int.	4294967295
LONG_MIN	����������� �������� ������� ���� long int. - 9223372036854775808
LONG_MAX	������������ �������� ������� ���� long int.	9223372036854775807
ULONG_MAX	������������ �������� ������� ���� unsigned long int.	18446744073709551615 */
#include <climits>
/* Windows.h �������� ����������� ��� Windows ������������ ������ ��� ������ ���������������� C � C ++, 
������� �������� ���������� ��� ���� ������� � API Windows, ���� ���������������� ��������, ������������
�������������� Windows, � ���� ����� ������, ������������ ���������� ��������� � ���������� */
#include <Windows.h>
// string: ����� � �������� � ����������� ��� ����������� ������ �� �������� � ����� ����������������
#include <string>
#include "Functions.hpp"

using namespace std;

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ::::::::::::::::::::::::::::::::::::::::::::::::::  ���������� ����������  ::::::::::::::::::::::::::::::::::::::::::::::::::::
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// �	����������, ������� ����������� �� ������� ������������ ����� �������, �������� �����������(��������)
// �	���������� ���������� �������� �� ���� ���������, �.�.�� ���� �������
//      (������ � �����* .cpp), � ������� ������� �� �����(���������)
// �	���������� �� ������ ������� �������� ����� ����� ���������� �����(�������������)
// �	��� ��������� � ���������� ���������� (� ������ ���������������) ����� ������������ ������ ::
// �	��� ������ � ���������� ���������� � ������ ������� ���������� ������ ���������� � ������ ������ � �������������� extern (������ � Functions.cpp)
int globalVar = 10;                        // ���������� ����������
int fGlobalVar()
{
	static int inFuncStaticCounter = 0;    // �		���� ���������� ����������� ������ ������� � �������� ������ static, 
										   //       �� � ���� ������ ��� �������� ���������� � ����� ������� �������������, �� �������� ������ ������ �������.
										   // � 	����� ����� ����� ���������� � �� ������� ������ �������, ����� ���������� �������������, �� ����� ������ ����������.
	globalVar += 10;
	return ++inFuncStaticCounter;
}
static int sGlobalVar = 100;               // ����������� ���������� ���������� � �������� ������ � �������� ������ (���������� ����������)
										   // ������ ���������� ( = ������� ����������) � ���� � ����������� ����� (*.cpp) � ������ ������������ ������(*.h)
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::  ����-�������  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void test()
{
	int ival = 10;                         
	int ival2 = 10;
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ::::::::::::::::::::::::::::::::::::::::::::::::::  ������ � ���������  :::::::::::::::::::::::::::::::::::::::::::::::::::
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ��������� �������������� ������� ���������� number
	int* p1 = &ival;
	// ����� ������ �������� numForEx ����� ���������, �������� �������������
	*p1 = 20;
	// ��������� ���������� r1 (��������� ��� ������� ������, ������������� �����������)
	int& r1 = ival;
	// ����� ������ �������� ival ����� ��������� ����������
	r1 = 30;
	// ������ ival, p1, &r1 �����
	cout << ival << " " << p1 << " " << r1 << " " << *p1 << endl; // 30 '�����' 30 30
	system("cls");
	void just_read(int& value);            // ������ ������ ���� Lvalue
	void just_read(const int& value);
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::  ���������  :::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ��������� ������ ��������, �� �� ����� ��������� --
	int const* p2 = &ival;                 // -- ��������� �� ��������� (const int* p2 = &ival; -- �� �� �����)
	// *p2 = 40;                           // ������ (�������� �������� ������)
	p2 = &ival2;                           // ��     (�� ����� ��������� �������� �����)
	// ��������� ������ ����� ���������, �� �� �������� --
	int* const p3 = &ival;                 // -- ����������� ���������
	*p3 = 40;                              // ��     (�������� �������� �����)
	// p3 = &ival2;                        // ������ (�� ����� ��������� �������� ������)
	// ��������� ������ ����� ��������� � �������� --
	int const* const p4 = &ival;           // -- ����������� ��������� �� ���������
	// *p4 = 40;                           // ������ (�������� �������� ������)
	// p4 = &ival2;                        // ������ (����� ��������� �������� ������)
	//int& const r2 = ival;                // -- ������. �� �� �����, ��� � (int& r2 = ival;) ������ ������ ���������)
	int const& r3 = ival;                  // -- ������ �� ���������
										   // "���������" �������� ������ � ������� -- void justReadBigValue(long long const& x);
}

	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ::::::::::::::::::::::::::::::::::::::::::::::::  ������ {������������}  ::::::::::::::::::::::::::::::::::::::::::::::::::
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ��� ���� ���:
	// �	������������ : ��� ��������, ��������� � ��������� �����������, 
	//      ������������ ������ ������ ���� � ������; ��������� �������� ������ ������ �� �������� �������������
	//		������������ �������������:
	// 		�	��������� ������ � ������� ������ � ����� ������� � ����� �������� � ������� (capsula);
	//      �	�������� ������ � ����� ���������������� �������
	//          ������������ ��� �������� ������������:
	//          �	��� ���������� �� ������� ��������� ���������� ����������������, �� �������������� ������� ��� �������� ������������
	//          �	��� �������������� ������������� ����������� �������
	//          �	��� ����������� ��������� � ��������� ����� ��� ������������� ��������� ����,
	//              ������� �������� � �������� ����� ������������ �����
	// �	������������ : ������ ����� ������������ �� ������ ������������ ������� �������
	// �	�����������  : ����������� ������ ��������������� �������� � ������� ������ ��������, ������������ ������ ���������
	// ��� ��������(���������) ��������� ������������� ����, ����������� � ����������
	// ������������	����������������, ����������� �������������
	// ���������� ������������� ������� ����������� ������� (�� ���������):
	// �	����������� ��� ����������;
	// �	����������;
	// �	�������� �����������(x = y);
class Person						       // ������ ����� ���������� ������ ������� (�� �����?) (�������� ������ � �������)
{
private:                                   // ������ ���� (������) ���������� � private

    // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ����  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	int age;
	string name;
public:

	// ::::::::::::::::::::::::::::::::::::::::::::::  ������������ � �����������  :::::::::::::::::::::::::::::::::::::::::::::::

	//Person() { name, age; }              // �� ��������� (Person somebody;) (������������� ��������)
	// ��������� �������������:
	Person() : name("Bot"), age(0) {}      // �� ��������� (Person somebody;) (�������� �� ���������)
	// �������� ���������� ������ � ������������ ����������� (���������������� ������ ��� ������������� �����)
	Person(string name, int age) : name(name), age(age) {}
	// �������� ������ �����������
	Person(int age) : Person("Bot", age) {}
	// explicit ���������: Person somebody = string("Superbot");, ��������� ������: Person somebody("Superbot");
	explicit Person(string name) : name(name) {}
	// ::::: ����������� :::::
	// �	����������� � ����������� ������, ������������� ��� ������������ ��������(������)
	// �	���������� �� ��������� �������� ������������, ���� �� ��������� ����� ����������
	// �	��� �������, ����������� �� ���������� ��������. ����� ����������� ������������
	// �	��� ��������� ��������, ����������� � �������� ������, ����������� ������������� ���������� ��� ������ 
	//		�� ������� ��������� �������(������, �������, ������������ �����, ������������� ��������� ����������)
	// �	���� ��� �������� ������� ���������� ������������ ������(� - �, � ������� new), 
	//		����� � ����������� ���������� ����������� ������ � ������� delete
	~Person()                              // ���������� (�������� ������� � ������������ ������)
	{
		//cout << "[ Destructor ] " << name << ", " << age << " <" << this << ">" << endl; // this: ��������� �� ������� ������
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ������  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	                                       // ������� ������ ������ �������� "������"
									       // +++ ������, �� ���������� ������, ������������� �������� const
	void getData() const
	{
		cout << "���: " << this->name << "\n�������: " << age << endl; // � ������ ������ this �� ����� ������, ������������ ��� ������
	}
	const Person& getOlder(const Person& other) const
	{
		return age > other.age ? *this : other;
	}
	// � ��� ������������� ��� ������ - ����� ������ ��������� ��� ��������, ��� ����� �������� �������� ���������� � ������ �������.
	// ������� ������������ �������� �������������� ������ � ��������� ������� ����� �������� ������ (������������ �����).
	// ������ ������� � ���������� ��������� ����� �������� getter, setter
};

class Line
{
private:
	char* data;
	int size;

	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::  �������  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//void operator= (Line& other) {}      // ������ ��������� ����������� (�� ������� ���������� (Line& operator+ (Line& other)))
	//Line(const Line& other) {}           // ������ �����������
public:
	Line(const char* s) : Line()
	{
		size = strlen(s);                  // �������� ������ (����� ������)
		data = new char[size];             // ������������ ������
		for (int i = 0; i < size; i++) data[i] = s[i]; // ������������ �����������
	}
	Line() : data(nullptr), size(0) {}     // ����������� �� ��������� (nullptr: ������� ���������)

	// :::::::::::::::::::::::::::::::::::::::::::::::::: ����������� ����������� :::::::::::::::::::::::::::::::::::::::::::::::::

	// �	����������� ����������� ��������� ��� ��������� ������ �� ������ ������������� �������
	// �	����������� ����������� ��������� ���� �������� � ���� ������ �� ������ ������� ����; ����� ��� ��������� �������� ������������� const
	Line(const Line& other)                // � ������ ������ ������� ��� ��� � �� ��� ������
	{
		size = strlen(other.data);
		data = new char[size];
		for (int i = 0; i < size; i++) data[i] = other.data[i];
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::: ��������������� ::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Line& operator= (Line& other)          // � ������ ������ ������ ��� ���������� � �� ��� ��������������
	{                                     
		// ����� ������� ����� �������������� ������ ��������� (Line& operator+ (Line& other))
	    // �    �� �������������� ���������� ��������:
		//      �	������ (������� ��������� ������ ��� ���������)
		//      �	���������� �������� (a ? b : c)
		//      �	�::� (�������� ������� ���������)
		// �	������������� �������� : ->, [], (), (int)
		// �	��� ��������������� �������� ������������ �operator�
		// �	�������� ����� ���� ��������� ������, ������������� �������� ��� ������� ��������
		//      (��� ��������� �������� ��������� ��������������� ������ ������ ����������������� ����)


		if (&other == this) return *this;  // ��������� �� ���������������� (line3 = line3;)
		delete[] data;                     // ������� ������� ������ (��������� ����������� ������ ������)
		size = other.size;
		data = new char[size];
		for (int i = 0; i < size; i++) data[i] = other.data[i];
		return *this;                      // ����������� ������������ ������� (line1 = line2 = line3;) (*this: ������� ������, �� ���������)
	}

	char operator[] (int i) const { return (i < size) ? data[i] : 0; } // ��������������� [] (int i: ����� � [])

	~Line() { delete[] data; }             // ���������� �� ��������� ����� ������������ ������ �.�. ���� �������� ������������ ������
										   // �.�. new char[] �� � delete[] (���������� ������)
	int getSize() const { return size; }
	const char* c_str() { return data; }
};

class Point
{
public:
	double x, y;
	Point() { x = 0, y = 0; }              // ����������� � ����������� �� ���������
	Point(double x, double y) : x(x), y(y) {} // ����������� � �����������

	double operator[] (bool b) const { return b ? x : y; } // ��������������� [] � ���������� ���� bool (const ��� ����� ����� ������)
	double& operator[] (bool b) { return b ? x : y; } // ���������� ��������������� (& ��� ����������� ��������� �����)

	Point& operator++()                    // Prefix increment. ��� ���������� (++x)
	{
		++x; ++y;                          // ��� �����������
		return *this;
	}
	Point operator++(int i)                // Postfix increment. � ���������� (x++) (i: �� ������������)
	{
		Point temp(*this);                 // ��������� ������, �����������
		++(*this);                         // ��������� � ����������� ��������������� (prefix increment)
		return temp;
	}
	                                       // friend: ������� ������� ��� �����, ������� �������� ���������� �������� ������
	friend std::ostream& operator<< (std::ostream& os, const Point& p) // 1� �������� (cout) - �� ������ ������, ������� ������� ������ ���� �������
		                                   // ������� �� ����������� ������ ���� friend, ������ ���� ����� ������ � �������� �����
		                                   // � ������ ������ ��� ������� ������������� ������� ������ ������, �� ��� �� �������� ��������� ������
	{                                      // ������ ����������� ����� ������� ����� ��������� �� �����
		os << p.x << ", " << p.y; 
		return os;
	}
};

class Segment
{
private:
	Point a, b;
public:
	Segment() : a(3.14, 2.78), b(2.78, 3.14) {}
};

	// :::::::::::::::::::::::::::::::::::::::::::::::::::: ����������� ���� ::::::::::::::::::::::::::::::::::::::::::::::::::::::

	// �	����������� �������� �� ������� � ���������� ����������� ������
	// �	� ��������� ����� ����������� �������� ����������� ������� ��� ��������, � �� ���������� ��������.
	// �	����������� ���� � ���������� ����������, ������� ��������� ���������� ������� ������
	// �	����� ����� ����������� ����� ��������� � �������� ����� ���������
	// �	������ ����� � ������������ ���� �������� � �������������� ����� ������ � ������ ������������� �������

class RFraction
{
	int num, den;
	static int counter;                    // ������� ���������� ����������� ������
public:
	RFraction(int n, int d) : num(n), den(d) { counter++; }
	~RFraction() { counter--; }
	static int getCounter() { return counter; } // ����������� ������ �������� ��� �������� ���������� ������
	static RFraction Unity;
	static RFraction Zero;
};
int RFraction::counter = 0;
RFraction RFraction::Unity = RFraction(1, 1);
RFraction RFraction::Zero = RFraction(0, 1);

    // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    // ::::::::::::::::::::::::::::::::::::::::::  ������ {������������, �����������}  :::::::::::::::::::::::::::::::::::::::::::
    // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    // �	������������ � ���� ��������� ��������� (������������) ���
    // �	������������ ��������� ������� ������� ������� ����� ���� �� ���� ������������, �������� �� �������� � ����������������
    // �	������������ � ��� ������� �� ������ � ��������, ��������� �������� �������
    // �	������������ ���������� ������� � ������������� � ������������ ��������������� ������ �� ���� ��������� ��������
    // �	� ����� ������ ������������ ������ � ������ ������������ ��� ���������� ����� ����� ������ � ����� ��������� ��������� (������)
    // 
    // �	����� Animal � ������� (������������)
class Animal
{
	int weigth;
	int legs;
	bool fur;
public:
	Animal(int w, int l, bool f) : weigth(w), legs(l), fur(f) {}
	virtual ~Animal() {}                   // � ������ ������� � ������������ ��������� ������������� ������� ����������� ����������
	virtual void SayHello() const { cout << "Some Roar"; } // virtuel: ����������� ������������ ������������
	                                       // ������� roar (����� ����������� ������) ��������� � SayHello �� ������������ ������
};
    // �	����� Dog, Cat � ����������� (�������)
class Dog : public Animal
{
	bool goodBoy;
	string roar;
public:
	Dog(bool gb = true, string r = "Rrrr") : Animal(10, 4, true), goodBoy(gb), roar(r) {}
	void SayHello() const { cout << roar; }
};

class Cat : public Animal
{
	bool fatCat;
	string roar;
public:
	Cat(bool fc = true, string r = "Meow") : Animal(10, 4, true), fatCat(fc), roar(r) {}
	void SayHello() const { cout << roar; }
};
void roar(Animal* a) { a->SayHello(); }

    // �	� �++ ����������� ���� ������������ : �������� ������������(public) � �������� ������������(private)
    // �	������ ������ ����������� � ��������� ������ ����� � ������� ������� :
class A {};
class B : public A {};                     // ���� ����� ���
class C : private A {};
    // �	�������� ������������ : ��� �������� ��������, ����������� � ������ A, ����� �������� � ��� �������� ������ B
    // �	�������� ������������ : ��� �������� �������� ������ A � ������ � ���������� ���������, �.�.�������� ������ ������ ������ �;
    //      ���������� � ������������ ������ C �� ������ A �� ��������(������� �������������� �� � � A �� �����������)
    // �	�� ��������� : ��� �������� ����������� �������� ������������, ��� ������� - ��������

class Base
{
private:
	int x, y;
	void setX(int xx) { x = xx; }          // private: ��������� x ���������� (� �.�. ��� �����������)
protected:                                 // ����������� ������� protected ��������� ������ ��������, ������� �������� � ������ ������ � ����������� �����
	void setY(int yy) { y = yy; }          // protected: ��������� y ���������� (�� �� ��� �����������)
public:
	Base(int xx, int yy) : x(xx), y(yy) {}
	int getX() { return x; } int getY() { return y; }
};
class Derived : public Base
{
	int z;
public:
	Derived();
	void Update(int xx, int yy)
	{
		//setX(xx);                        // ������, ����������� ����� �� ����� ������� � �������� ��������� �������� ������ (�� �������� �������������)
 		setY(yy);
	}
	void Get(int& xx, int& yy)
	{
		xx = getX();
		yy = getY();
	}
};
    // ��������������� � ���������� �����������:
    // �	������ ������������ ���� �������� � ���� �������� �������� ����(��������� �� ��� ����� ���� ��������������� ���������� �����������)
    // �	��� �������� ������� ������������ ���� ������ ���������� � ����������� �������� ����(������)
    // �	��� ����������� ������� ������������ ���� ������ ���������� � ���������� �������� ����(�����)
    // �	� ������ ����������� : ���������� ������������� ��������� � ��� ����������� ������������ ������(� ����� ��� �����) ����� ����������� �������� ������
    // �	� ������ �������� : ���������� ����� ������������� ������� ����������� ��� ����������(�� ���������) �������� ������ ����� ����� ������������ ������������ ������
	// �	� ������ �������� ����� ���������� ������������� � ������ ������������� ������������;
	//      ����� ���� ���������� � ������������ �������� ������ ����� ����� ������������ ������������ ������
Derived::Derived() : Base(2, 4), z(5) {}   // ����������� Derived
    // ������� ����������� �������:
    // �	��� ��������� ������� (�������������) ������� ���������� ���������� ����� ������� � ����������� ��� � ����� ������ (�� ������ ����������)
    // �	���� � ������ ������������ ���� �� ���� ����������� �������, �� ���������� ������ ������� - ���� vmtp(��������� �� ������� ����������� �������).
    //      � ������� �������� ������ ��������� � ������ ����������� �������.
    // ����������� �������:
    // �	� �++ ����� �������� ����������� ����� �����, ����� ������������� � ����������� �������
    // �	������������� �� ������������ (= �� ��������) ����������� ������� � ������������ � �����������
    // ����������� ������ � �������:  
    // �	����������� ����� ������������ ������������� ��� ������������ (� ������������); 
    // �	���� ����������� ����� �� ������������� ���������� ��� ���� ����� ����������� �������, �� �� ���� �������� �����������
class Figure                               // ����������� ����� (���� ���� ���� �� 1 ����������� �������, ��������� ���������� ������������ ������ ������)
{
	Point* points;                         // ����� ��������� ����
	int nPoints;
public:
	virtual double Volume() = 0;           // ������ ����������� ������� ( = 0 ) 
	virtual double Length() = 0;           // ������ ���������� ����������� ���� ����������� ����������
	virtual void setPoints(Point* points, int size);
	virtual Point* getPoints();
};
    // �������� �����������:
	// �	������������ � ����������� ����� ��������� ��� �������� � ����������.
	// �	�������� ����������� ��������� ����� �������� �����������; ���������� ����������� ���������(��������) �������� ����� ����� �������� ����� ������(��� �������, �����������)
	// �	�������� ���������� ��������� ����������� �������� ������������������, ����������� � �����(��������� ����������) ��� � ����������� ������(���������� ����������).
	// �	������� ������ ������ ����� ��������� ������������� � ������������ ������, ��� ��� ��� ��������� ���������� ��� ��������� � �����������
	// �	������������ ������ � ���� ������ ����� ��������� � ��������� ������, ������� ���� ����������
	// �	�������� ���������� ��������� ����������� ������������
	// �	���������� ���������� ��������� ������������, �� ��� � �������� ����������, ��������� �������� �������� ������ � ������������ ������.
    // �������� � ���������:
    // �	�	�����������	������	�����	�������	�����������	��������	�� ��������� � ��������� �������� ������;
    // �	����� ����������� � ��� ��������, � ������� ������� � ��������

class Parent
{
private: int x;
public:
	void Do() { int d = 1; };
	void f(int x) {};
};
class Child : public Parent
{
	void Do() { int d = 1; };
public:
	double x;
	int f(int x, int y) {};
};













    // ===========================================================================================================================
	// =========================================================  MAIN  ==========================================================
	// ===========================================================================================================================
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	test();
	{									   // -- ��������� ������� ���������, ��� �������� {} a, b ����� ����������
		Point a;                           // ������������� (empty object)
		a = Point { 3.14, 2.78 };          // ���������� (������� � ����������� ��������� ������)
		Point b { 2.78, 3.14 };            // +++ ������������� ��� ����������� (��� ���������� �������) (�������� ��������������)
		// ----------------------- ��������� ������� (��� 4 1:30) -------------------------
	}									   // -- ��������� ������� ���������, ��� �������� {} a, b ����� ����������
	// ===========================================================================================================================
	// =================================================  ���������� ����������  =================================================
	// ===========================================================================================================================
	float globalVar = 0.0f;                // ��� ��������� ����������, ���������� ����������
	fGlobalVar();
	int res = ::globalVar + 1;             // ��� ������� � ���������� ���������� ���������� ::
	// ===========================================================================================================================
	// =======================================================  ���������  =======================================================
	// ===========================================================================================================================
	Point point{ 3.14, 2.71 };             // Point point = { 3.14, 2.71 }; (�� �� �����)
	Point* ptrPoint = &point;              // ��������� �� ��������� (Point ptrPoint = new Point;)
	Point& refPoint = point;               // ������ �� ���������
	ptrPoint->x = 3.1415;                  // �������� ������ ('->' ��� ������ � �����������)
	refPoint.y = 2.7182;
	// cout << point.x << " " << point.y << endl; // 3.1415 2.7182
	// ===========================================================================================================================
	// ================================================  ������ {������������}  ==================================================
	// ===========================================================================================================================
	Person other = Person("Bob", 23);      // ����� ����� ������ ������������
	Person man("John", 17);                // ������� ����� ������ ������������
	Person* lady = new Person("Ann", 17);  // ����� ������������ ��� ������������ �������� �������
	Person somebody;                       // ����������� �� ���������
	// "��������� �������������"
	Person person1{ "Peter", 11 };
	const Person person2 = { "Nick", 12 }; // ��� ������ � const �������� ����� ���������� ������ � const �������
	Person person3{};                      // ���������� ����������� �� ���������

	// �	����������� ������ �������������� ��� �������������, ������������, �������� ���������� � �������� �� �������
	// �	��� ���������������� �����(�������\��������) ��� ����������� ���������� ����������� ���������� ��������� 
	//      �������� ���������� �������������� ����������� ����������� � �������� ������������
	// �	���������� ������������� ������ ����������� ����������� � �������� ������������, �������� ���������� ����������� ���������� ���������

	Line line1("Hello world");
	Line line3("Hasta la vista");
	                                       // ������ ���� ����������� ������������ �� ���������!
	Line line2 = line1;                    // ����������� ����������� (�� ���������: ��������� �����������)
	                                       // �������� � ������� ((Show(line1);): ���� ����������� �����������
	line3 = line2 = line1;                 // �������� ������������ (�� ���������: ��������� �����������)
	                                       // ��������� ����������� ��������� �������� ������ � ��������� � �������� ������
	cout << Line("all that glitters is gold").c_str() << endl; // ��������� (���������) ������               -- ��� �����-�� ������

	cout << "Static counter == " << RFraction::getCounter() << endl; // ��������� � ������������ ����

	// ===========================================================================================================================
	// =========================================  ������ {������������, �����������}  ============================================
	// ===========================================================================================================================
	{
		Dog bobik;
		Animal a = bobik;                  // ���������� ����������� ����������� ��� Animal (���������� ���������� � Dog)
		Animal* ptr = &bobik;              // ��������� ������� �������������� ������ ���������� ������������ ���� � ����� ������� ������������� ����
		Animal& ptr_ref = bobik;           // ����������� �������� �������������� ����� ������������ ��� ������ �������. ����� �������������� �������� ������������� �������
		Cat* tom = new Cat("Tom");
		roar(tom);
		delete tom;
		Child ch;
		ch.x = 3.14f;
		//ch.Do();                         // ��������. ������. � ���� ������ ���������� �������� ��������� �������� ������
		                                   // � �++ �������������� ����������� ���������� � �������� �������� ����� ������� ���������	(��� �������� ������)
		ch.Parent::Do();                   // ��������� (Do() - private � Child, public � Parent)
		//ch.f(13);                        // ��������
		ch.Parent::f(13);                  // ���������
	}
	system("cls");
	_ConvertingClasses_Cast___PTRREF();



	return 0;
}

// ������� ������ ����������� one - definition - rule(ODR):
// �	� �������� ����� ������� ���������� �������� (�������, ��� ������, ������) �� ����� ����� ����� ������ �����������
// �	� �������� ��������� ���������� ����������(�������) � ��������������� ������� (�� inline) �� ����� ����� ������ ������ �����������
// �	������ � ������������� ������� (�.�.��������, � ������� ����������� ��������� ��� �������� ����������� � �����������) 
//      ����� ������������ � ����� ��� ����� ������� ����������, �� ����������� ������� ���������
// �	����������� ���������, �� ���������� ��������, � ������ �������� ���������� ���������� ��������� ��������,
//      ���� ���� �� ����� � ���� ���������. ��� ����������� ���������������� ����� �����������.
