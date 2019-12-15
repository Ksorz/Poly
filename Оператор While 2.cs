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
            /* Напишите программу, которая осуществляет ввод целых чисел от пользователя в цикле.
             * 0 является признаком выхода. Программа вычисляет и отображает на экране результат P/C,
             * где P - произведение всех введенных чисел, а C - количество этих чисел.
             * Проверку вводимых значений на корректность делать не обязательно.
             * Ноль является признаком выхода и не учитывается при вычислении. */

            int i;
            int j = 0;
            int P = 0;

            Console.WriteLine("Для отображения результата введите 0");
            while (true)
            {
                Console.WriteLine("Введите целое число:");
                try
                {
                    i = Convert.ToInt32(Console.ReadLine());
                }
                catch
                {
                    Console.WriteLine("Вы ошиблись");
                    continue;
                }
                if (i == 0) break;
                j++;
                if (j > 1) P *= i;
                else P = i;

            }
            Console.WriteLine(Convert.ToDouble(7 *7*7/3));
            double result = Convert.ToDouble(P) / j;
            Console.WriteLine("Результат " + P + " / " + j + " = " + Math.Round(result, 2));
        }
    }
}
