// Определение функций-членов размещают в файле кода (person.cpp)
// .cpp файл может быть отдель скомпилирован и распространяться в виде машинных инструкций,
// а используя заголовочный (.hpp) файл можно получить доступ к его функционалу
// :::::::::::::::::::
// ::::: ФУНКЦИИ :::::
// :::::::::::::::::::
// Передача функций в качестве аргументов
// double(*f)(double) -- указатель на функцию, которая возвращает double и принимает 1 аргумент типа double
extern int fGlobalVar;                     // Объявление глобальной переменной из модуля Source.cpp в данном модуле 

double transform(double val, double(*f)(double)) { return f(val); }

// В данном случае нужно передавать адреса значений или указатели -- swap1(&x, &y);
void swap1(int* px, int* py)
{
	int t = *px;
	*px = *py;
	*py = t;
}

// В данном случае нужно передавать значения (lvalue) -- swap2(x, y);
void swap2(int& px, int& py)
{
	int t = px;
	px = py;
	py = t;
}

// Последовательное хранение строк динамического массива в памяти
int** optimizedArray(int sizeX, int sizeY)
{
	int** arr = new int* [sizeX];
	arr[0] = new int[sizeX * sizeY];       // Выделяем в одной строке память под все элементы массива
	for (size_t i = 1; i != 5; i++)        // Настраиваем указатели для получившейся строки
	{
		arr[i] = arr[i - 1] + sizeY;       // С учетом адресной арифметики прибавляется sizeY * (размер int) байт
	}
	return arr;
	// Удаление в 2 шага (эти строки не будут выполнены в данной функции) --
	delete arr[0];                         // Удаляем всю строку
	delete arr;                            // Удаляем разбивку строки
}

// inline-функции: компилятор вместо вызова функции (переход по определенному адресу функции) подставляет тело функции в точку вызова
inline int maxValue(int a, int b) { return a > b ? a : b; }

// Длина строки
int strLen(char* str)
{
	int result = 0;
	for (; *str++; result++); // Последний символ в строке char всегда 0, достигая его получаем false
	return result;
}

// Копирование строки
void strCopy(char* out, char* in)
{
	while (*out++ = *in++);
}

// Инверсия строки
char* strReverse(char* str)
{
	int n = strLen(str);
	char ch, * p, * q;
	for (p = str, q = str + (n - 1); p < q; p++, q--)
		ch = *p; *p = *q; *q = ch;
	return str;
}

