

// �������� ������� � �������� ����������
// double(*f)(double) -- ��������� �� �������, ������� ���������� double � ��������� 1 �������� ���� double
double transform(double val, double(*f)(double)) { return f(val); }