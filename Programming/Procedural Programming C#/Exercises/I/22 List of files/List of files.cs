using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace WorkWithStrings
{
    class Program
    {
        /* Задание: Список файлов
         * Данное задание направлено на изучение тем:
         *
         * - рекурсия,
         * - хорошее оформление кода (константы, процедурный подход, необязательные аргументы),
         * - самостоятельное изучение библиотек MS VS.
         *
         * Разработайте функцию, которая по адресу папки выводит на экран список всех файлов в этой папке и из всех ее подпапках.
         * Для решения задачи примените рекурсивный подход.
         *
         * Используйте пространство имен System.IO (классы Directory и Path) для получения информации о папках и подпапках.
         *
         * Оцениваться будет в том числе удобство восприятия иерархической структуры пользователем.
         * При необходимости используйте псевдографику и цвет текста. */

        public static string CharFolder = "+";
        public static string CharFile = "-";
        public static int Gap = 3;

        static void Main(string[] args)
        {
            ShowFiles("C:\\Users\\Ksorz\\OneDrive\\Документы\\Poly");
            Console.ReadLine();
        }

        static void ShowFiles(string sourcePath, string spaces = " ")
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine(spaces + CharFolder + Path.GetFileName(sourcePath));
            Console.ForegroundColor = ConsoleColor.White;
            spaces = spaces + new string(' ' , Gap);


            foreach (string file in Directory.GetFiles(sourcePath))
                Console.WriteLine(spaces + CharFile + Path.GetFileName(file));


            foreach (string folder in Directory.GetDirectories(sourcePath))
                ShowFiles(folder, spaces);
        }
    }
}
