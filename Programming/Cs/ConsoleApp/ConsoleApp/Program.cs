using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Сортировка блинов
         * 
         * При выпечке небольших блинов на большой сковороде блины получаются разными по размеру (диаметру). Блины лежат стопочкой в том порядке, в каком выпекались. 
         * Необходимо отсортировать их по диаметру – чтобы самый большой был внизу. Делать это можно с помощью лопатки: воткнуть лопатку в любое место стопки
         * блинов или под всю стопку и перевернуть всё, что на лопатке, на остаток стопки на тарелке или на пустую ту же тарелку. Требуется отсортировать блины,
         * диаметры которых вводятся с клавиатуры (конец – по вводу 0), отображая при этом выполняемые перевороты.
         * 
         * Подумайте о выборе оптимального способа представления данных с помощью стандартных классов .Net: список, очередь, стек, массив... 
         */

        static void Main(string[] args)
        {
            int blin = 1;
            List<int> stopkaBlinov = new List<int>();

            while(blin != 0)
            {
                blin = Convert.ToInt32(Console.ReadLine());
                if(blin != 0) stopkaBlinov.Add(blin);
            }
            foreach (int i in stopkaBlinov) Console.WriteLine(i);
        }
    }
}
