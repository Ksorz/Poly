using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /*
         * Задание: Поиск в двухмерном массиве
         *
         * На вход функции подается двухмерный массив типа integer. Ячейки массива гарантировано отсортированы по возрастанию,
         * при этом используется порядок расположения элементов сначала по строкам, потом по столбцам. Пример такого массива:
         *
         * 2, 6, 7, 11, 14
         * 18, 20, 21, 22, 28
         * 29, 37, 44...
         *
         * Разработайте функцию, которая ищет заданное значение в этом массиве.
         */
        public struct Search
        {
            public int d1, d2;
            public Search(int[,] newArr, int newX)
            {
                d1 = 0;
                d2 = 0;
                for(int i = 0; i < newArr.GetLength(0); i++)
                    for(int j = 0; j < newArr.GetLength(1); j++)
                    {
                        if (newArr[i, j] == newX)
                        {
                            d1 = i;
                            d2 = j;
                            break;
                        }
                    }
            }
        }

        static void Main(string[] args)
        {
            int[,] arrX = new int[,]
              { { 1, 3, 7, 12, 17 },
                { 21, 22, 27, 30, 34 },
                { 35, 38, 44, 49, 56 },
                { 57, 58, 66, 74, 99 } };
            Search s;
            s = new Search(arrX, 3);
            Console.WriteLine("Индексы искомого элемента: [{0}, {1}]", s.d1, s.d2);

        }
    }
}
