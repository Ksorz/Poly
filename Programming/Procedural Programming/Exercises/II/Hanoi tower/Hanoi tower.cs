using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Ханойская башня
         * 
         * Реализуйте проект, который в автоматическом режиме решает известную головоломку Ханойские башни.
         * (http://ru.wikipedia.org/wiki/%D0%A5%D0%B0%D0%BD%D0%BE%D0%B9%D1%81%D0%BA%D0%B0%D1%8F_%D0%B1%D0%B0%D1%88%D0%BD%D1%8F)
         * 
         * При реализации разработать рекурсивную подпрограмму, у которой предлагаются такие аргументы:
         * public static void Move(Башня_Откуда, Башня_Куда, Башня_Временная, Количество_Перекладываемых_Дисков)
         * Подумайте, каким образом эффективно и удобно запрограммировать три башни (спицы) с кольцами разного диаметра на них.
         * 
         * С примером работающей программы можно познакомится скачав архив по https://dl.spbstu.ru/pluginfile.php/70757/mod_assign/intro/Hanoi.zip */

        public static int count = 0;  // Подсчет шагов
        public static int[] r1;       // 
        public static int[] r2;       // 1, 2, 3 башни 
        public static int[] r3;       //
        static void Main(string[] args)
        {
            Console.WriteLine("Введите количество колец");
            int rings = Convert.ToInt32(Console.ReadLine());

            Create(rings, out r1, out r2, out r3);
            Move(r1, r2, r3, rings);    
        }

        // Рекурсивный алгоритм, решающий задачу
        public static void Move(int[] TowerFrom, int[] TowerTo, int[] TowerTemp, int amount)
        {
            if (amount > 0)
            {
                Move(TowerFrom, TowerTemp, TowerTo, amount - 1);
                
                SwapRing(ref TowerFrom, ref TowerTo);

                Move(TowerTemp, TowerTo, TowerFrom, amount - 1);
            }
        }
        // Функция, "перекладывающая" верхнее кольцо с одной башни на другую
        static void SwapRing(ref int[] from, ref int[] to)
        {
            for(int i = 0; i < from.Length; i++)
            {
                if (from[i] != 0)
                {
                    for (int j = 0; j < to.Length; j++)
                    {
                        if (to[j] != 0) { to[j - 1] = from[i]; break; }
                        if (j + 1 == to.Length) { to[j] = from[i]; break; }
                    }
                    from[i] = 0;
                    break;
                }
            }
            count++;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("\n\nШаг {0}\n", count);
            Console.ResetColor();
            Print(r1, r2, r3);
        }
        // Создание трех массивов (башен) определённого размера
        static void Create(int rings, out int[] r1, out int[] r2, out int[] r3)
        {
            r1 = new int[rings]; r2 = new int[rings]; r3 = new int[rings];
            for (int i = 0; i < r1.Length; i++) r1[i] = i + 1;
        }
        // Вывод на экран трех массивов (башен)
        static void Print(int[] r1, int[] r2, int[] r3)
        {
            for (int i = 0; i < r1.Length; i++) Console.WriteLine("{0}     {1}     {2}", r1[i], r2[i], r3[i]); 
        }
    }
}
