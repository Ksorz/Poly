using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        static void Main(string[] args)
        {
            /* Вариант 1. 
            Разработайте подпрограмму, которая по заданному значению аргумента x(double) вычисляет значение функции
            y = F(x), где периодическая функция F(x) задана графиком ниже.
            Пример работы: вход = 1.7, результат = 0.3; вход = -2.2, результат = 0.2; вход = 0, результат = 0 */

            double x = -2.2;
            // Остаток от деления на 2 модуля переменной x окргуляем до 2 знаков
            double y = Math.Round(Math.Abs(x) % 2, 2);
            // Если полученное число (y) больше 1, то вычитаем его из 2
            y = y > 1 ? 2 - y : y;
            // Получается одна из точек на заданном графике функций
            Console.WriteLine(y);
        }
    }
}
