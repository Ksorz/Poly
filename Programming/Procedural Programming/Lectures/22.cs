using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime;
using System.Runtime.InteropServices;
using System.Globalization;
using System.Text.RegularExpressions; // регулярные выражения для проверок (строк)

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string sample = "    Доказано, что ругательства помогают легче переносить боль!";

            string temp;
            char z;

            temp = sample[7].ToString();
            z = sample[7];

            Console.WriteLine(z);
            Console.WriteLine(temp);

            temp = sample.Substring(2, 4);

            Console.WriteLine(temp);
            Console.WriteLine();

            temp = "";
            string temp1 = "";
            sample = sample.Trim();


            foreach (char c in sample) // Развернуть все слова задом наперёд не меняя их местами в троке (sample)
            {
                if (c != ' ' & c != ',' & c != '.' & c != '!' & c != '?' & c != '-') { temp = c.ToString() + temp; }
                else { temp1 = temp1 + temp + c; temp = ""; }
            }
            temp1 = temp1 + temp;

            Console.WriteLine(temp1);
            Console.WriteLine();

            sample = "   кошашеков   Кошек     потанэк   ";
            sample = sample.Trim();
            char marker = '0';
            
            for(int i = 0; i < sample.Length; i++) // Убрать лишние пробелы между словами в строке (sample)
            {
                if (marker == ' ' & sample[i] == ' ') { sample = sample.Remove(i, 1); i--;  continue; }
                if (sample[i] == ' ') { marker = ' '; continue; }
                marker = '0';
            }
            Console.WriteLine(sample);

            var textInfo = new CultureInfo("ru-RU").TextInfo;
            sample = textInfo.ToTitleCase(textInfo.ToLower(sample)); // Сделать все первые буевы слов в строке (sample) заглавными

            Console.WriteLine(sample);
            Console.WriteLine();

            foreach (string s in sample.Split()) Console.Write(s[0].ToString().ToLower() + '.'); // Вывод первых букв в каждом слове из строки (sample)

            Console.WriteLine();
            Console.WriteLine(sample);

            Console.WriteLine(Compare(sample, "Кошек"));

        }
        static bool Compare (string source, string marker) // Поиск строки (marker) в строке (source)
        {

            for(int i = 0; i < 1 + source.Length - marker.Length ; i++)
            {
                if(source[i] == marker[0]) { if(source.Substring(i, marker.Length) == marker) return true; }
            }    
                
            return false;
        }
    }
}
