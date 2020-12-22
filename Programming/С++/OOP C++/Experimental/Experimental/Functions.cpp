

// Передача функций в качестве аргументов
// double(*f)(double) -- указатель на функцию, которая возвращает double и принимает 1 аргумент типа double
double transform(double val, double(*f)(double)) { return f(val); }