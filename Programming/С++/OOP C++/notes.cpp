#include <iostream> // Includes the contents of the file into the program
#include <climits>
#include <Windows.h>
#include <string>
#include <iomanip> // Manipulators, flags

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    wcout.imbue(locale(".1251")); // SetConsoleOutputCP(1251);
    wcin.imbue(locale(".866")); // SetConsoleCP(1251);


    // ====================================================================================

    auto variable = 3.14; // Automatic type initialization
    extern int unind; // Variable declaration without definition
    int maxval = INT_MAX; // Maximum type`s value

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
