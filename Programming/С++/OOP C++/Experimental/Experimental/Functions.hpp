// ���������� ������ ������ ��������� ���������� ������� - ������ � ������� ������. ��������� � header - �����(� - �, person.hpp)

// �	������������ ����� ������������ ����� �������� ��������� ��� ������� �������������.
// �	��� �������� � �������� �������� ����� (��� ��������������� ��� �����: .h � .cpp), ����������� ��������� ��������� ������������� 
//      ������ ������������ ����� ������ � �������������� ���������������� ������ ����������. �� ��� ���� ��������� ������:
// �	�� ����� �������� ������� ����� ���������� �������������� ���������������� ����������, ��� ��������� �������������� ������ ���,
//      ����� ��� �����
// �	������ ���������������� �������������(��������� �� �����, ����� ������ ������ ��������� �� ���)
#pragma once


double transform(double val, double(*f)(double));
void swap1(int* px, int* py);
void swap2(int& px, int& py);
int** optimizedArray(int sizeX, int sizeY);
int strLen(char* str);
void strCopy(char* out, char* in);
char* strReverse(char* str);



void _ConvertingClasses_Cast___PTRREF();