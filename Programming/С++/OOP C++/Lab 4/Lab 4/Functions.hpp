#pragma once

int rnd(int min, int max);
bool yesNo(char yes);

class NSet
{
public:
	NSet();
	void show(); //	
	void randomSetFilling(int* arr, const int size); // Заполнение массива случайными значениями

private:
	int size;
	int* set;
};