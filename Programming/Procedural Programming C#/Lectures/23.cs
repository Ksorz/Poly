using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime;
using System.Runtime.InteropServices;
using System.IO;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // Конструктор файлов. Если указать только имя, то файл будет создан в директории с exe
            FileInfo file = new FileInfo("C:/Users/Ksorz/OneDrive/Документы/Poly/Programming/Procedural Programming/Lectures/23 text.txt");
            // Создает (пустой) новый/перезаписывает существующий файл
            StreamWriter sw = file.CreateText();

            sw.WriteLine("2020 is the best year ever kekw");
            sw.WriteLine("Кто наелся и спит...");
            sw.WriteLine("Donald Duck");
            sw.WriteLine("This is fine");

            sw.Close();
            Console.WriteLine("Done!");
            
            StreamReader sr;
            sr = file.OpenText();

            while(sr.EndOfStream == false)
            {
                Console.WriteLine(sr.ReadLine());
            }
            sr.Close();
            Console.ReadLine();
        }
    }
}
