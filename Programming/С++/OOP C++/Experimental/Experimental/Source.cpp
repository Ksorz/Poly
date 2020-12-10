#include <iostream>
#include <climits>
#include <Windows.h>
#include <string>

using namespace std;


int main()
{
	float L1 = 100, L2 = 100, L3 = 100, L4 = 100, L5 = 100, L6 = 100;
	float labResult = ((L1 + L2 + L3 + L4 + L5 + L6) / 6) / 10;
	cout << "LabResult = " << labResult << endl;

	float KT1 = 10, KT2 = 10, KT3 = 10;
	float ktResult = (KT1 + KT2 + KT3) / 3;
	cout << "KtResult = " << ktResult << endl;

	float Result = (labResult + ktResult)/2;
	cout << "Result = " << Result << endl;

	return 0;
}