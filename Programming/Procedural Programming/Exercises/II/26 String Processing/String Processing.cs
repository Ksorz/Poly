using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime;
using System.Runtime.InteropServices;
using System.Globalization;
using System.Text.RegularExpressions;

namespace ConsoleApp
{
    class Program
    {
        /* Задача: Обработка строк
         * 
         * Найти в переданной в качестве параметра строке самую "большую" подстроку заданной длины.
         * Например, для строки "ABCDBDDA" и входного числа 2, ответ будет 5 (подстрока "DD"). 
         * 
         * Строки сравниваются в лексикографическом порядке.*/

        static void Main(string[] args)
        {
            string sample = "ABCDBDDA";
            string sample2 = "Найти в переданной в качестве параметра строке самую \"большую\" подстроку заданной длины.";
            string sample3 = "Доступ к информационному ресурсу ограничен на основании ФЗ от 27.07.2006 г." +
                " №149-ФЗ \"Об информации, информационных технологиях и о защите информации\"";


            Console.WriteLine(HighestString(sample, 2));
            Console.WriteLine(HighestString(sample2, 5));
            Console.WriteLine(HighestString(sample3, 37));


        }
        static string HighestString(string source, int len) 
        {
            string result = "";

            for(int i = 0; i < source.Length - len + 1; i++) // Цикл перебирает подстроки заданной длины и сохраняет "наибольшую",
                                                             // которая в конце цикла и является результатом
            {
                if (source.Substring(i, len).CompareTo(result) > 0) result = source.Substring(i, len);
            }
            return result;
        }
    }
}
