using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Многоугольники
         * Объявите структуру, которая бы описывала многоугольник на плоскости. Предусмотрите поля для записи данных о вершинах многоугольника, о толщине линии, цвете линии, наличии заливки фигуры.

         * Напишите функцию, которой передается массив с ячейками типа структура с информацией о многоугольниках. Функция должна возвращать количество ячеек, которые удовлетворяют условиям:

         * Вариант 1
         * Многоугольник является равносторонним треугольником и имеет толщину линии больше Width (входной аргумент).
         */

        public static Random rnd = new Random(); // Рандом всегда пригодится

        public struct Polygon
        {
            public List<double> X; // Координаты по оси X
            public List<double> Y; // Координаты по оси Y
            public int width;      // Толщина линий
            public string color;   // Цвет линий
            public bool filling;   // Заливка да/нет
            public Polygon(int w, string c, bool f)
            {
                X = new List<double>();
                Y = new List<double>();
                width = w;
                color = c;
                filling = f;
            }
            public void AddPoint(double argX, double argY) // Добавление вершины для текущего многоугольника
            {
                X.Add(argX);
                Y.Add(argY);
            }

            public void Info() // Для вывода информации о текущем многольнике
            {
                Console.WriteLine("\n" + X.Count + " side polygon");
                Console.WriteLine("Line width: {0}\nColor: " + color + "\nFilling: " + filling + "\n", width);
                for (int i = 0; i < X.Count; i++) Console.WriteLine("X: '{0}'\nY: '{1}'\n", X[i], Y[i]);
            }
        }



        static void Main(string[] args)
        {
            // =======================================================

            // Вводные параметры
            Polygon[] polys = new Polygon[1000000]; // Из миллиона 3-5 сторонних многоугольников, в среднем, получается 30 равносторонних треугольников
            int sides = 5; // Максимальное кол-во сторон многоульника

            // =======================================================
            
            for (int i = 0; i < polys.Length; i++) polys[i] = Constructor(side); // Цикл генерации массива структур

            int count = Count(polys);
            Console.WriteLine(count);
        }
        


        static int Count(Polygon[] polygons)
        {
            int count = 0;
            foreach (Polygon obj in polygons) count = IsPolyEqConditions(obj) ? count + 1 : count;

            return count;
        }

        static bool IsPolyEqConditions(Polygon p)
        {
            if(p.X.Count > 3) return false;

            double aX = p.X[0];
            double aY = p.Y[0];
            double bX = p.X[1];
            double bY = p.Y[1];
            double cX = p.X[2];
            double cY = p.Y[2];

            double ab = Math.Round(Math.Sqrt(Math.Pow(aX - bX, 2) + Math.Pow(aY - bY, 2)), 1);
            double ac = Math.Round(Math.Sqrt(Math.Pow(aX - cX, 2) + Math.Pow(aY - cY, 2)), 1);
            double bc = Math.Round(Math.Sqrt(Math.Pow(bX - cX, 2) + Math.Pow(bY - cY, 2)), 1);

            if (ab == ac & ab == bc & ac == bc) return true;

            return false;
        }

        static Polygon Constructor(int maxSides) // Функция для создания одного многоугольника
        {
            string[] colors = { "Red", "White", "Black", "Yellow", "Blue", "Green", "Purple" };
            int sides = rnd.Next(3, 7);
            int w = rnd.Next(6);
            string c = colors[rnd.Next(colors.Length)];
            bool f = 1 > rnd.Next(2) ? false : true;

            Polygon obj = new Polygon(w, c, f);

            for (int i = 0; i < sides; i++)
            {
                double one = Math.Round(rnd.NextDouble() * (maxSides * 2) - maxSides, 2);
                double two = Math.Round(rnd.NextDouble() * (maxSides * 2) - maxSides, 2);
                while (one == two)
                {
                    two = Math.Round(rnd.NextDouble() * (maxSides * 2) - maxSides, 2);
                }

                obj.AddPoint(one, two);
            }
            return obj;
        }
    }
}
