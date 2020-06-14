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
        /* Задание: Сортировка блинов
         * 
         * При выпечке небольших блинов на большой сковороде блины получаются разными по размеру (диаметру). Блины лежат стопочкой в том порядке, 
         * в каком выпекались. Необходимо отсортировать их по диаметру – чтобы самый большой был внизу. Делать это можно с помощью лопатки: воткнуть
         * лопатку в любое место стопки блинов или под всю стопку и перевернуть всё, что на лопатке, на остаток стопки на тарелке или на пустую ту же тарелку.
         * Требуется отсортировать блины, диаметры которых вводятся с клавиатуры (конец – по вводу 0), отображая при этом выполняемые перевороты.
         * 
         * Подумайте о выборе оптимального способа представления данных с помощью стандартных классов .Net: список, очередь, стек, массив... */


        static void Main(string[] args)
        {
            List<int> blins = new List<int> { 7, 3, 9, 12, 77, 19, 4, 21, 33, 50, 47 };

            SortBlinov(blins);
            Console.WriteLine();
            foreach (var i in blins) Console.WriteLine(i);
        }
        // Не успеваю написать комментарии.. Извиняюсь(
        static List<int> SortBlinov(List<int> blins)
        {
            int count = blins.Count;
            int index;
            int tempVal = 0;

            for (int i = 0; i < count; i++)
            {
                List<int> blinsTemp = new List<int>(blins);
                blinsTemp.Sort();

                if (blins.SequenceEqual(blinsTemp)) break;

                index = FindLowest(blins, tempVal);
                tempVal = blins[index];


                blins.Reverse(index, count - index);
                blins.Reverse(i, count - i);

            }
            return blins;
        }
        static int FindLowest(List<int> blins, int value)
        {
            return blins.IndexOf(blins.Where(x => x > value).Min());            
        }
    }
}
