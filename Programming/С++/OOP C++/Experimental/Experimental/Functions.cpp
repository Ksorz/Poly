// ����������� �������-������ ��������� � ����� ���� (person.cpp)
// .cpp ���� ����� ���� ������ ������������� � ���������������� � ���� �������� ����������,
// � ��������� ������������ (.hpp) ���� ����� �������� ������ � ��� �����������
// :::::::::::::::::::
// ::::: ������� :::::
// :::::::::::::::::::
// �������� ������� � �������� ����������
// double(*f)(double) -- ��������� �� �������, ������� ���������� double � ��������� 1 �������� ���� double
extern int fGlobalVar;                     // ���������� ���������� ���������� �� ������ Source.cpp � ������ ������ 

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

// inline-�������: ���������� ������ ������ ������� (������� �� ������������� ������ �������) ����������� ���� ������� � ����� ������
inline int maxValue(int a, int b) { return a > b ? a : b; }

// ����� ������
int strLen(char* str)
{
	int result = 0;
	for (; *str++; result++); // ��������� ������ � ������ char ������ 0, �������� ��� �������� false
	return result;
}

// ����������� ������
void strCopy(char* out, char* in)
{
	while (*out++ = *in++);
}

// �������� ������
char* strReverse(char* str)
{
	int n = strLen(str);
	char ch, * p, * q;
	for (p = str, q = str + (n - 1); p < q; p++, q--)
		ch = *p; *p = *q; *q = ch;
	return str;
}

