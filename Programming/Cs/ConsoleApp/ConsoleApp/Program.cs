﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /*
         * Задание: Сортировка ступенчатого массива
         * 
         * На вход функции подается ступенчатый массив int[][] arrTaxi в котором находятся сведения о выручке по отдельным поездкам 
         * за сутки разных таксистов одной компании. Количество ячеек в каждом отдельном массиве внутри ступенчатого равно количеству
         * поездок (предполагаем, что оно всегда больше 0). Содержимое ячейки - выручка в рублях.
         * 
         * Нужно отсортировать данный массив в соответствии со следующим принципом - вначале идут массивы с бОльшим количеством
         * поездок (т.е. ячеек). Если у двух массивов количество поездок совпадает, то вначале идет тот. в котором суммарная выручка
         * больше.
         * 
         * В качестве дополнительной информации укажите какое количество итераций было выполнено алгоритмом для следующих двух примеров.
         * 
         * Пример 1 для тестирования.
         
int[][] arrTaxi = new int[10][];
 
            arrTaxi[0] = new int[] {100, 289, 200, 101, 90, 230};
            arrTaxi[1] = new int[] {290, 300, 303, 120, 150 };
            arrTaxi[2] = new int[] { 80 };
            arrTaxi[3] = new int[] { 300, 60, 120, 400, 410 };
            arrTaxi[4] = new int[] { 60, 100, 40 };
            arrTaxi[5] = new int[] { 60, 160, 165, 120, 110, 230, 200, 30 };
            arrTaxi[6] = new int[] { 230, 200, 250, 100 };
            arrTaxi[7] = new int[] { 100, 209, 175, 100 };
            arrTaxi[8] = new int[] { 70, 120, 290 };
            arrTaxi[9] = new int[] { 90, 80, 105, 140, 120 };

         * Пример 2 для тестирования.

int[][] arrTaxi = new int[10][];
 
            arrTaxi[0] = new int[] { 80 };
            arrTaxi[1] = new int[] { 60, 100, 40 };
            arrTaxi[2] = new int[] { 70, 120, 290 };
            arrTaxi[3] = new int[] { 100, 209, 175, 100 };
            arrTaxi[4] = new int[] { 230, 200, 250, 100 };
            arrTaxi[5] = new int[] { 90, 80, 105, 140, 120 };
            arrTaxi[6] = new int[] { 290, 300, 303, 120, 150 };
            arrTaxi[7] = new int[] { 300, 60, 120, 400, 410 };
            arrTaxi[8] = new int[] { 100, 289, 200, 101, 90, 230 };
            arrTaxi[9] = new int[] { 60, 160, 165, 120, 110, 230, 200, 30 };
         */
        public struct Sorting
        {
            public int[][] result;
            public Sorting(int[][] data)
            {
                result = new int[data.Length][];


            }
        }

        static void Main(string[] args)
        {
            int[][] arrTaxi = new int[10][];

            arrTaxi[0] = new int[] { 100, 289, 200, 101, 90, 230 };
            arrTaxi[1] = new int[] { 290, 300, 303, 120, 150 };
            arrTaxi[2] = new int[] { 80 };
            arrTaxi[3] = new int[] { 300, 60, 120, 400, 410 };
            arrTaxi[4] = new int[] { 60, 100, 40 };
            arrTaxi[5] = new int[] { 60, 160, 165, 120, 110, 230, 200, 30 };
            arrTaxi[6] = new int[] { 230, 200, 250, 100 };
            arrTaxi[7] = new int[] { 100, 209, 175, 100 };
            arrTaxi[8] = new int[] { 70, 120, 290 };
            arrTaxi[9] = new int[] { 90, 80, 105, 140, 120 };



            Console.WriteLine("Индексы искомого элемента: [{0}, {1}]", s.d1, s.d2);

        }
    }
}
