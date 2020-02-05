using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        static void Main(string[] args)
        {
            var colors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));
            byte value = 0;


            do
            {
                try
                {
                    Console.WriteLine("Введите половину стороны квадрата (от 3 до 20)");
                    value = Convert.ToByte(Console.ReadLine());
                    if (value < 3 || value > 20)
                    {
                        Console.WriteLine("Ошибочка!");
                        continue;
                    }
                }
                catch
                {
                    Console.WriteLine("Ошибочка!");
                    continue;
                }

                var kale = Kaleidoscope(colors, value);
                Mirror(kale);
                Console.ResetColor();
                Console.WriteLine("Выход: Escape");

            }
            while (Console.ReadKey(true).Key != ConsoleKey.Escape);
            

            
            

            
            //var kale = Kaleidoscope(colors, value);

            //Mirror(kale);
            //Console.ResetColor();
        }

        static void Mirror(ConsoleColor[,] picture)
        {
            int len = picture.GetLength(0);
            var mirrSquare = new ConsoleColor[len * 2, len * 2];
            int bigLen = mirrSquare.GetLength(0);
            int index = 0;

            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    mirrSquare[i, j] = picture[i, j];
                    mirrSquare[i, bigLen - (j + 1)] = picture[i, j];
                    mirrSquare[bigLen - (i + 1), j] = picture[i, j];
                    mirrSquare[bigLen - (i + 1), bigLen - (j + 1)] = picture[i, j];
                }
            }
            foreach (var color in mirrSquare)
            {
                Console.BackgroundColor = color;
                Console.Write(" ");
                index++;
                if (index % bigLen == 0) Console.WriteLine();
            }
        }

        static ConsoleColor[,] Kaleidoscope(ConsoleColor[] colors, byte value)
        {
            var arr = new ConsoleColor[value,value];
            Random rnd = new Random();

            for (int i = 0; i < value; i++)
            {
                for (int j = 0 + i; j < value; j++)
                {
                    ConsoleColor color = colors[rnd.Next(0, colors.Length)];
                    arr[i, j] = color;
                    arr[j, i] = color;
                }
            }
            return arr;
        }
    }
}
