using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        /* Вычисление тригонометрических функций
        Как известно , тригонометрические функции можно записать как сумму ряда, воспользовавшись рядами Маклорена.

        Данное задание содержит два варианта. 

        Вариант 1
        Напишите фрагмент программы для вычисления:

        SIN(X) = X - X^3 / 3! + X^5 / 5! - X^7 / 7! ...

        Переменная X типа double.

        Необходимо решить задачу с помощью цикла while. Итерации организовать до достижения значения очереднего
        члена ряда меньше 0.001, но при этом, чтобы количество итераций цикла было не менее трех. Результат вывести на экран. */

        static void Main(string[] args)
        {
            double x = 2;
            double n = 0;
            double nindex = n;

            int index = 1;
            int j = 3;

            double imprecision = 0.001; // Область приблежённого равенства


            while (true)
            {
                // Вычисления
                if (index % 2 != 0) n -= Math.Pow(x, j) / Factorial(j);
                else n += Math.Pow(x, j) / Factorial(j);

                if (n + imprecision > nindex & n - imprecision < nindex && index > 3) break; // Условие приближённого равенства

                nindex = n;
                index++;
                j += 2;

                Console.WriteLine("n is " + Math.Round(n, 3) + " nindex is " + Math.Round(nindex, 3));
                System.Threading.Thread.Sleep(100);
            }
            Console.WriteLine("\nSin result is " + Math.Sin(x));
            Console.WriteLine("My  result is " + (x += n) + "\n");
            
        }
        // Функция, вычисляющая факториал
        public static int Factorial(int x)
        {
            if (x == 0) return 1;
            else return x * Factorial(x - 1);
        }
    }
}
