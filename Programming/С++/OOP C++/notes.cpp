#include <iostream> // Includes the contents of the file into the program
#include <climits>
#include <Windows.h>
#include <string>
#include <iomanip> // Manipulators, flags
#include <map> // Dictionary

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    wcout.imbue(locale(".1251")); // SetConsoleOutputCP(1251);
    wcin.imbue(locale(".866")); // SetConsoleCP(1251);


    // ====================================================================================
    auto variable = 3.14; // Automatic type initialization
    map<string, int> dictionary {
		{"Elephant", 800}, {"Cat", 5}, {"Bird", 1}
	};
	for (auto item : dictionary)
		cout << item.first << " ^^ " << item.second << endl;
    // ------------------------------------------------------------------------------------
    extern int unind; // Variable declaration without definition
    // ------------------------------------------------------------------pointer, указатель
    int maxval = INT_MAX; // Maximum type`s value
    int* ptr = &maxval; // Initialize "ptr" with the memory adress of variable "maxval"
	std::cout << ptr << endl; // Print "ptr" (memory adress of "maxval")
	std::cout << *ptr << endl; // Print value of "maxval" (based on "ptr" adress)
    int* p = 455; // X
    int* p = (int*) 455; // V
    int* p = nullptr;
    void* v = &maxval; // Empty pointer type
    int arr[] = { 1, 2, 3, 4, 5 };
	int* m = &arr[0]; // int* m = arr; // ==

	for (; m < arr + 5; m++) {
		cout << "Element № " << m - arr << " value : " << *m << endl;
	}
	m = m - 5;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << "Value: " << arr[i] << endl;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { // ==
		cout << "Adress m[i]: " << m[i] << " : " << &m[i] << endl;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++, m++) { // ==
		cout << "Adress m++: " << *m << " : " << m << endl;
	}

    int size = 10;
	int** arr; // , ** a, ** b;
	arr = new int* [size];
	int val = 0;
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = getRand(1, 77);
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << "=====================================" << endl;
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " | ";
		}
		cout << endl;
	}
    // ------------------------------------------------------------------------------------
    int x = 100; // Static memory
    int* y = new int;
    *y = 200; // Dynamic memory
    delete y;
    int* arr = new int[x];
    arr[2] = 400;
    delete[] arr;


    // ====================================================================================

    int age;
	cin >> age;
	if (cin.fail()) {
		cout << "Bad input" << endl;
	}
}

void example1(char ch) {
    using std::cout;
    using std::endl;
    cout << ch << endl;
}
