using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace ConsoleApp1
{
    class Program
    {
        /*
         * Напишите функцию, которая получает на вход два отсортированных по возрастанию одномерных массива элементов типа Integer 
         * (их длина может быть различна), и возвращает массив из N наибольших элементов входных массивов, где N – бОльшая длина из двух указанных.
         */

        static void Main(string[] args)
        {
            int[] arr1 = { 1, 14, 7, 12, 44, 72};
            int[] arr2 = { 4, 46, 78, 122, 514, 678, 1999 };

            int[] highestNums = HighestNumbers(arr1, arr2);

            foreach (var i in highestNums) Console.WriteLine(i);
        }
        // Функция "слияния" массивов по условию задачи
        static int[] HighestNumbers(int[] arr1, int[] arr2)
        {

            int len = arr1.Length > arr2.Length ? arr1.Length : arr2.Length; // Вычисляем длину наибольшего из массивов

            int[] result = new int[len]; // Создаем новый массив, равный по длине наибольшему

            // Копируем значения из наибольшего массива в новый и заполняем его наибольшими значениями из второго (наименьшего) массива
            if (arr1.Length > arr2.Length)
            {
                arr1.CopyTo(result, 0);
                GetHighest(arr2, result);
            }
                
            else 
            {
                arr2.CopyTo(result, 0);
                GetHighest(arr1, result);
            }

            return result;
        }

        // Функция замены значений в массиве to
        static void GetHighest(int[] from, int[] to)
        {
            int switcher = 1;
            // Обходим значения массива (to), сравнивая с каждым значением из массива (from) и заменяем их в случае, если значение оказалось меньше
            for (int i = 0; i < to.Length; i++)
            {
                for (int j = from.Length - switcher; j >= 0; j--)
                {
                    if (to[i] < from[j])
                    {
                        to[i] = from[j];
                        break;
                    }
                }
                switcher++;
            }
        }
    }
}
