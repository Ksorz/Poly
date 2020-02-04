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
            ConsoleColor[] colors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));


            Console.ResetColor();
            Console.WriteLine(colors.GetType().GetElementType());
            var kale = Kaleidoscope(colors, 5);
            int i = 0;

            foreach (var color in kale)
            {
                Console.BackgroundColor = color;
                Console.Write(" ", color);
                i++;
                if (i % 5 == 0) Console.WriteLine();
            }

            Console.ResetColor();
            Console.WriteLine(kale.Length);
        }
        static ConsoleColor[,] Kaleidoscope(ConsoleColor[] colors, int value)
        {
            ConsoleColor[,] arr = new ConsoleColor[value,value];
            Random rnd = new Random();

            //int range = (value / 2) * (value + 1);

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
