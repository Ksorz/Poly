#pragma once

int rnd(int min, int max);
bool yesNo(char yes);

class NSet
{
public:
	NSet();
	void show(); //	
	void randomSetFilling(int* arr, const int size); // ���������� ������� ���������� ����������

private:
	int size;
	int* set;
};