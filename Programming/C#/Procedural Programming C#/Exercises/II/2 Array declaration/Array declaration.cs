using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
        /*Вариант 1
     
    Предложите объявления массивов для хранения следующих данных:

    1. Информация о прохождении профилактических осмотров автомобилей за месяц.Каждый автомобиль должен 
    раз в неделю пройти два вида осмотра (например, осмотр двигателя и осмотр кузова), по результатам которых 
    ставятся отметки: прошел или не прошел.Предположить количество автомобилей равным 30.

    2. Информация за один месяц о вырученных от продаж и потраченных на закупки финансах 
    (одновременно в одном массиве). Данные в массиве должны храниться за каждый день месяца.

    3. Информация о температуре воздуха, которая измеряется в области размером 100 на 100 километров с шагом 5
    километров.Кроме этого замеры производятся на разной высоте от уровня земли: от 0 до 5 км, с шагом 0,5 км.
    Необходимо хранить ежедневные данные за месяц.*/

    class Program
    {
        public static Random rnd = new Random(); // Random для всех функций
        static void Main(string[] args)
        {
            // ================================================================

            int cars = 30; // Количество автомобилей
            int weeks = 4; // Количество завершённых недель в данном месяце

            //CarInspections(cars, weeks); //  Вариант с трёхмерным массивом (задание 1)
            //CarInspectionsTwo(cars, weeks); // Вариант со ступенчатым массивом (задание 1)

            // ================================================================

            int days = 31; // Количество дней в месяце

            //Money(days); // (задание 2)

            // ================================================================

            ushort x = 20; ushort y = 20; ushort z = 5; // Размер исследуемой площади
            ushort stepXY = 5; float stepZ = 0.5f; // Шаги исследуемой площади

            //Weather(x, y, z, stepXY, stepZ); // (задание 3)

            // ================================================================
        }

        // Создание массива данных осмотра автомобилей за месяц
        static void CarInspections(int cars, int weeks)
        {
            Console.WriteLine("\n=== Информация о прохождении профилактических осмотров автомобилей ===");
            Random rnd = new Random();

            // Трёхмерный массив, на каждую неделю приходится по 30 машин, на каждую из которых - по 2 осмотра
            bool[,,] monthlyInspections = new bool[weeks, cars, 2];

            // Заполняем массив подполагаемыми данными
            for (int i = 0; i < weeks; i++)
            {
                for (int j = 0; j < cars; j++)
                {
                    // Предположим, что автомобили проходят осмотр в 19 из 20 случаев
                    monthlyInspections[i, j, 0] = rnd.Next(20) == 0 ? false : true;
                    monthlyInspections[i, j, 1] = rnd.Next(20) == 0 ? false : true;
                }
            }

            // Вывод данных на экран
            for (int i = 0; i < monthlyInspections.GetLength(0); i++)
            {
                Console.WriteLine("\nWeek " + (i + 1) + "\n");
                for (int j = 0; j < monthlyInspections.GetLength(1); j++)
                {
                    Console.Write("Car " + (j + 1) + " ");
                    if (j < 9) Console.Write(" ");
                    Console.Write(monthlyInspections[i, j, 0] + " ");
                    Console.WriteLine(monthlyInspections[i, j, 1]);
                }
            }
        }

        // Создание массива расходов за каждый день месяца
        static void Money(int days)
        {
            Console.WriteLine("\n=== Информация о вырученных от продаж и потраченных на закупки финансах ===\n");
            // Двумерный массив доходов/расходов за каждый день месяца
            long[,] moneyCounting = new long[days, 2];

            for (int i = 0; i < moneyCounting.GetLength(0); i++)
            {
                // Гипотетический доход/расход
                moneyCounting[i, 0] = rnd.Next(35000, 90000);
                moneyCounting[i, 1] = rnd.Next(-70000, -29000);
            }

            // Вывод данных на экран
            for (int i = 0; i < moneyCounting.GetLength(0); i++)
            {
                Console.Write("Day " + (i + 1) + " ");
                if (i < 9) Console.Write(" ");
                Console.Write(moneyCounting[i, 0] + " ");
                Console.WriteLine(moneyCounting[i, 1]);
            }
        }

        // Массив данных о погоде на заданном участке
        static void Weather(ushort sideOne, ushort sideTwo, ushort height, ushort stepXY, float stepZ)
        {
            // Трёхмерный массив данных о температуре
            float[,,] data = new float[sideOne + 1, sideTwo + 1, (int)(height / stepZ) + 1];

            for (int i = 0; i < data.GetLength(0); i++)
            {
                Console.WriteLine("\n Данные о погоде на длине {0} км., по всей высоте от 0 до {1} км." +
                    " с шагом {2}\n", i * stepXY, height, stepZ);

                for (int j = 0; j < data.GetLength(1); j++)
                {
                    // Текущие координаты
                    int x = i * stepXY;
                    int y = j * stepXY;
                    for (int n = 0; n < data.GetLength(2); n++)
                    {
                        // Гипотетическая температура, зафиксированная в каждой точке
                        data[i, j, n] = rnd.Next(164, 189) / 10f;
                    }
                    
                    // Чтоб было красиво
                    Console.Write("{0}:{1} ", x, y);
                    if (x < 10) { Console.Write("  "); }
                    else if (x < 100) { Console.Write(" "); }
                    if (y < 10) { Console.Write("  "); }
                    else if (y < 100) { Console.Write(" "); }
                    Console.Write("----- ");

                    // Вывод данных на экран
                    for (int n = 0; n < data.GetLength(2); n++)
                    {
                        Console.Write(" " + data[i, j, n]);
                        if (data[i, j, n] == (int)data[i, j, n]) Console.Write("  ");
                    }
                    Console.WriteLine();
                }
            }
            Console.WriteLine("\nВсего данных о погоде сформировано {0}\n", data.Length);
        }

        // Вариант со ступенчатым массивом данных для автомобилей
        static void CarInspectionsTwo(int cars, int weeks)
        {
            Random rnd = new Random();
            int index = 0; // Итератор для foreach

            bool[,] weeklyInspections = new bool[cars, 2]; // Двумерный массив проверок всех машин за неделю
            bool[][,] monthlyInspections = new bool[weeks][,]; // Ступенчатый массив всех данных за месяц

            for (int i = 0; i < weeks; i++)
            {
                // Формирование ступенчатого массива
                monthlyInspections[i] = new bool[cars, 2];
            }
            for (int i = 0; i < cars; i++)
            {
                // Предположим, что автомобили проходят осмотр в 19 из 20 случаев
                weeklyInspections[i, 0] = rnd.Next(20) == 0 ? false : true;
                weeklyInspections[i, 1] = rnd.Next(20) == 0 ? false : true;
            }
            for (int i = 0; i < weeks; i++)
            {
                for (int j = 0; j < cars; j++)
                {
                    // Заполнение ступенчатого массива
                    monthlyInspections[i][j, 0] = weeklyInspections[j, 0];
                    monthlyInspections[i][j, 1] = weeklyInspections[j, 1];
                }
            }
            // Вывод данных на экран
            foreach (bool[,] num in monthlyInspections)
            {
                index++;
                Console.WriteLine("\nWeek " + index + "\n");
                for (int i = 0; i < num.GetLength(0); i++)
                {
                    Console.Write("Car " + (i + 1));
                    if (i < 9) Console.Write(" ");
                    Console.Write(" " + num[i, 0] + " ");
                    Console.WriteLine(num[i, 1]);
                }
            }
        }
    }
}
