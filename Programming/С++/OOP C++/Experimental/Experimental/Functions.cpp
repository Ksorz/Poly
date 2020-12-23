// �������� ������� � �������� ����������
// double(*f)(double) -- ��������� �� �������, ������� ���������� double � ��������� 1 �������� ���� double
double transform(double val, double(*f)(double)) { return f(val); }

// � ������ ������ ����� ���������� ������ �������� ��� ��������� -- swap1(&x, &y);
void swap1(int* px, int* py)
{
	int t = *px;
	*px = *py;
	*py = t;
}

// � ������ ������ ����� ���������� �������� (lvalue) -- swap2(x, y);
void swap2(int& px, int& py)
{
	int t = px;
	px = py;
	py = t;
}

// ���������������� �������� ����� ������������� ������� � ������
int** optimizedArray(int sizeX, int sizeY)
{
	int** arr = new int* [sizeX];
	arr[0] = new int[sizeX * sizeY];       // �������� � ����� ������ ������ ��� ��� �������� �������
	for (size_t i = 1; i != 5; i++)        // ����������� ��������� ��� ������������ ������
	{
		arr[i] = arr[i - 1] + sizeY;       // � ������ �������� ���������� ������������ sizeY * (������ int) ����
	}
	return arr;
	// �������� � 2 ���� (��� ������ �� ����� ��������� � ������ �������) --
	delete arr[0];                         // ������� ��� ������
	delete arr;                            // ������� �������� ������
}