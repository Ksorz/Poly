#pragma once
// ���� � ������������ (�-�, matrix.hpp)

struct Matrix // ��������� ��� �������
{
	int sizeX; // ���-�� �����
	int sizeY; // ���-�� ��������
	int maxNumLen; // ���������� �������� ������ �������� ����� � ������� (�������� �����). ��� ���������� ������ �� �����
	int** mx;
};

void printMx(Matrix mx); // ����� ������� �� �����
Matrix matrix(); // �������� �������
void traceMx(Matrix mx); // ���������� ����� ���������� �������
void deleteMx(Matrix mx); // �������� �������


