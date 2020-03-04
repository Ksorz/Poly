using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /*
         * Задание: Обработка элементов массива
         * 
         * Напишите функцию, которая в одномерном числовом (Int) массиве выполняет циклический сдвиг влево на указанное (count)
         * количество элементов. При сдвиге на одну позицию, самый первый элемент в массиве становится самым последним.
         */
        static void Main(string[] args)
        {
            int[] arrInt = { 1, 2, 3, 4, 5 };

            foreach(int n in MoveLeft(arrInt, 1)) { Console.WriteLine(n); }
        }
        static int[] MoveLeft(int[] arr, int pos)
        {
            int[] newArr = new int[arr.Length];

            for(int i = 0; i < arr.Length; i++)
            {
                newArr[i] = arr[(pos + i) % arr.Length];
            }

            return newArr;
        }
    }
}
