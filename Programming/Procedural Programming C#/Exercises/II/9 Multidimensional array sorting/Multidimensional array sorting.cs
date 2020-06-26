using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Сортировка ступенчатого массива
         * 
         * На вход функции подается ступенчатый массив int[][] arrTaxi в котором находятся сведения о выручке по отдельным поездкам за сутки
         * разных таксистов одной компании. Количество ячеек в каждом отдельном массиве внутри ступенчатого равно количеству поездок 
         * (предполагаем, что оно всегда больше 0). Содержимое ячейки - выручка в рублях.
         * 
         * Нужно отсортировать данный массив в соответствии со следующим принципом - вначале идут массивы с бОльшим количеством поездок 
         * (т.е. ячеек). Если у двух массивов количество поездок совпадает, то вначале идет тот. в котором суммарная выручка больше.
         *
         * В качестве дополнительной информации укажите какое количество итераций было выполнено алгоритмом для следующих двух примеров. */

        public static int iteration;

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

            int[][] arrTaxi2 = new int[10][];

            arrTaxi2[0] = new int[] { 80 };
            arrTaxi2[1] = new int[] { 60, 100, 40 };
            arrTaxi2[2] = new int[] { 70, 120, 290 };
            arrTaxi2[3] = new int[] { 100, 209, 175, 100 };
            arrTaxi2[4] = new int[] { 230, 200, 250, 100 };
            arrTaxi2[5] = new int[] { 90, 80, 105, 140, 120 };
            arrTaxi2[6] = new int[] { 290, 300, 303, 120, 150 };
            arrTaxi2[7] = new int[] { 300, 60, 120, 400, 410 };
            arrTaxi2[8] = new int[] { 100, 289, 200, 101, 90, 230 };
            arrTaxi2[9] = new int[] { 60, 160, 165, 120, 110, 230, 200, 30 };

            iteration = 0;
            TaxiSorting(arrTaxi);

            iteration = 0;
            TaxiSorting(arrTaxi);

        }

        static void TaxiSorting(int[][] source)
        {
            for (int i = 1; i < source.Length; i++)
            {
                InstantSort(source, i);
                iteration++;
            }

            for (int i = 0; i < source.GetLength(0); i++)
            {
                foreach (int j in source[i]) Console.Write(j + " ");
                Console.WriteLine("  Num == {0};  Sum == {1}", source[i].Length, source[i].Sum());
            }
            Console.WriteLine("\nIterations = {0}", iteration);
            Console.WriteLine("END\n\n");
        }

        static void InstantSort(int[][] source, int index)
        {
            // Если предшествующий массив больше либо равен следующему (убедимся, что index > 0)
            if (index > 0 && source[index - 1].Length >= source[index].Length)
            {
                // Вызываем Swap для сортировки текущего массива, рекурсивно вызываем текущий метод с новыми вводными
                Swap(source, index - 1, index);
                InstantSort(source, index - 1);
                iteration++;
            }
        }

        static void Swap(int[][] source, int indexOne, int indexTwo)
        {
            int[] temp;
            
            // Если размер массивов не равен
            if (source[indexOne].Length != source[indexTwo].Length)
            {
                // Меняем местами массивы
                temp = source[indexOne];
                source[indexOne] = source[indexTwo];
                source[indexTwo] = temp;
                iteration++;
                return;
            }

            // Если размер массивов равен (indexTwo всегда меньше, убедимся что indexTwo не указывает на отрицательный диапозон)
            while (indexTwo != -1 && source[indexOne].Length == source[indexTwo].Length)
            {
                // Для сортировки двух массивов равного размера (> по возрастанию, < по убыванию)
                if (source[indexOne].Sum() > source[indexTwo].Sum())
                {
                    temp = source[indexOne];
                    source[indexOne] = source[indexTwo];
                    source[indexTwo] = temp;
                    indexOne--;
                }
                indexTwo--;
                iteration++;
            }
        }
    }
}
