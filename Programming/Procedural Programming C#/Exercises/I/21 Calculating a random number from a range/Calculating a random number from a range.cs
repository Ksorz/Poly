using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {

        public static int Divisibility(int min, int max, int D)
        {
            int maxDiv = 0; // Максимальнок делимое
            int minDiv = 0; // Минимальное делимое
            for (int i = min; i <= max; i++)
            {
                if (i % D == 0) // Поиск минимального делимого из диапозона
                {
                    minDiv = i;
                    break;
                }
            }

            if (minDiv == 0) return 0; // Если не существует минимального делимого, значит делимых на D вообще нет в диапозоне

            for (int i = minDiv; i <= max; i += D) // В диапозоне от минимального делимого до максимума ищем максимальное делимое
            {
                maxDiv = i; // На каждой итерации обновляем значение максимального делимого
            }

            Random rnd = new Random();
            // Находим случайное делимое, в зависимости от количества всех делимых из диапозона minDiv-maxDiv
            // Умножаем случайное значение из единичного диапозона на наш делитель
            // +1 т.к. максимальное значение не включено в Random.Next
            int rndDiv = rnd.Next(minDiv / D, (maxDiv / D) + 1) * D; 

            return rndDiv;
        }

        static void Main(string[] args)
        {
            int intMin = 299, intMax = 400, intD; // Определяем минимум и максимум диапозона, объявляем переменную            

            while (true)
            {
                Console.WriteLine("Введите целое число в диапозоне от 1 до " + intMax + "\n");

                try
                {
                    intD = Convert.ToInt32(Console.ReadLine());
                    if (intD < 1 || intD > intMax) // Код для работы только с положительными числами
                    {
                        Console.WriteLine("Вы ошиблись");
                        continue;
                    }
                }
                catch
                {
                    Console.WriteLine("Вы ошиблись");
                    continue;
                }

                int result = Divisibility(intMin, intMax, intD);

                if (result == 0) // Нулевой результат означает, что делимых чисел из диапозона нет
                {
                    Console.Write("Делимого на " + intD + " из диапозона от " + intMin + " до " + intMax + " : ");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("не существует");
                    Console.ResetColor();
                }
                else
                {
                    Console.Write("Случайное делимое на " + intD + " из диапозона от " + intMin + " до " + intMax + " : ");
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine(result);
                    Console.ResetColor();
                }
                
            }
        }
    }
}
