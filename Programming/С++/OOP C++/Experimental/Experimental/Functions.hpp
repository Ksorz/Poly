#pragma once

double transform(double val, double(*f)(double));
void swap1(int* px, int* py);
void swap2(int& px, int& py);
int** optimizedArray(int sizeX, int sizeY);

