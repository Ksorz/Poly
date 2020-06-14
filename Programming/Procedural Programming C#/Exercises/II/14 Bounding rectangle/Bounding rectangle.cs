using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Охватывающий прямоугольник
         
         * Задайте структуру, которая бы описывала прямоугольник на плоскости. Предположить, что стороны прямоугольника параллельны осям. Координаты вершин - тип double.

         * Разработайте функцию на вход которой подается массив прямоугольников (размер массива не более 1000). 
         * Функция должна возвращать прямоугольник, который бы охватывал все входящие в массив прямоугольники.
         */

        public static Random rnd = new Random();
        public struct Rectangle
        {
            public double X1;
            public double X2;
            public double Y1;
            public double Y2;
            public Rectangle (double newX1, double newX2, double newY1, double newY2)
            {
                X1 = newX1;
                X2 = newX2;
                Y1 = newY1;
                Y2 = newY2;
            }
            public void coords()
            {
                Console.WriteLine(X1 + " . " + X2 + " --- " + Y1 + " . " + Y2);
            }
        }

        static void Main(string[] args)
        {
            Rectangle[] rectangles = new Rectangle[10];
            double X1, X2, Y1, Y2;

            for (int i = 0; i < rectangles.Length; i++) // Создаём массив прямоульников со случайными координатами
            {
                Coordinate(10, out X1, out X2);
                Coordinate(10, out Y1, out Y2);
                rectangles[i] = new Rectangle(X1, X2, Y1, Y2);
            }

            Rectangle bigOne = BigOne(rectangles); // Создаём охватывающий прямоугольник

            foreach (Rectangle h in rectangles) h.coords();
            Console.WriteLine();
            bigOne.coords();
        }        

        static void Coordinate(int max, out double one, out double two) // Две случайные координаты, не равные друг другу.
        {
            one = Math.Round(rnd.NextDouble() * (max * 2) - max, 1);
            two = Math.Round(rnd.NextDouble() * (max * 2) - max, 1);
            while(one == two)
            {
                two = Math.Round(rnd.NextDouble() * (max * 2) - max, 1);
            }
        }

        static Rectangle BigOne(Rectangle[] rectangles) // Строим прямогульник, охватывающий все из массива
        {
            Rectangle bigOne = new Rectangle();
            foreach(Rectangle obj in rectangles) // На этом шаге нужно сравнить все координаты
            {
                bigOne.X1 = Comparsion(bigOne.X1, obj.X1, obj.X2, '>');
                bigOne.X2 = Comparsion(bigOne.X2, obj.X1, obj.X2, '<');
                bigOne.Y1 = Comparsion(bigOne.Y1, obj.Y1, obj.Y2, '>');
                bigOne.Y2 = Comparsion(bigOne.Y2, obj.Y1, obj.Y2, '<');
            }
            return bigOne;
        }

        // Сравниваем и присваиваем (в зависимости от результата сравнения) значение искомой координаты с данными по оси X или Y
        static double Comparsion(double A, double b, double c, char ch) 
        {
            double result;

            if (ch == '<') // Знак сравнения выбираем при вводе данных
            {
                result = A < b ? A : b;
                result = result < c ? result : c;
            }
            else
            {
                result = A > b ? A : b;
                result = result > c ? result : c;
            }
            return result;
        }
    }
}
