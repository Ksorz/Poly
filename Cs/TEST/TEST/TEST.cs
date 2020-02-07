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
            byte value;
            string flag;
            ConsoleKeyInfo cki = new ConsoleKeyInfo();

            Message("Добро пожаловать в \" Калейдоскоп \" !\n", ConsoleColor.Yellow);
            System.Threading.Thread.Sleep(1500);
            Message("Выход: ", newLine: false);
            Message("\" Q \"", ConsoleColor.Red);
            Message("Выбрать цвет: ", newLine: false);
            Message("\" S \"", ConsoleColor.Red);
            System.Threading.Thread.Sleep(2000);

        ColorSelection:

            ConsoleColor[] colors = ColorSwitcher();

            while (true)
            {
                Message("\nВведите половину стороны квадрата (от 3 до 20)\n", ConsoleColor.Cyan);
                flag = Console.ReadLine();

                if (flag == "Q" || flag == "q")
                {
                    break;
                }
                else if (flag == "S" || flag == "s")
                {
                    goto ColorSelection;
                }

                try
                {
                    value = Convert.ToByte(flag);

                    if (value < 3 || value > 20)
                    {
                        Message("\nОшибочка!\n", ConsoleColor.Red);
                    }
                    else
                    {
                        Console.WriteLine();
                        var kale = Kaleidoscope(colors, value);
                        Mirror(kale);
                    }
                }
                catch
                {
                    Message("\nОшибочка!\n", ConsoleColor.Red);
                }

                //cki = Console.ReadKey(true);
                //if (cki.Key == ConsoleKey.S) goto ColorSelection;
            }











            /*
            do
            {
                try
                {
                    Message("\nВведите половину стороны квадрата (от 3 до 20)\n", ConsoleColor.Cyan);
                    value = Convert.ToByte(Console.ReadLine());

                    if (value < 3 || value > 20)
                    {
                        Message("\nОшибочка!\n", ConsoleColor.Red);
                        goto Main;
                    }
                    else
                    {
                        Console.WriteLine();
                        var kale = Kaleidoscope(colors, value);
                        Mirror(kale);
                    }
                }
                catch
                {
                    Message("\nОшибочка!\n", ConsoleColor.Red);
                    goto Main;
                }

                Message("\nЧтобы выйти нажмите ", newLine:false);
                Message("\" Escape \"", ConsoleColor.Red);
                Message("Чтобы выбрать другие цвета нажмите ", newLine: false);
                Message("\" S \"\n", ConsoleColor.Blue);
                
                cki = Console.ReadKey();
                if (cki.Key == ConsoleKey.S) goto ColorSelection;
            }
            while (cki.Key != ConsoleKey.Escape);
            */

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

                if (index % bigLen != 0) continue;

                Console.ResetColor();
                Console.WriteLine();
            }
        }

        static ConsoleColor[,] Kaleidoscope(ConsoleColor[] colors, byte value)
        {
            var arr = new ConsoleColor[value, value];
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

        static void Message(string message, ConsoleColor color = ConsoleColor.White, bool newLine = true)
        {
            Console.ResetColor();
            Console.ForegroundColor = color;
            Console.Write(message);
            if (newLine) Console.WriteLine();
            Console.ResetColor();
        }

        static ConsoleColor[] ColorSwitcher()
        {
            Message("\nВыберите цвет:\n" +
                "\"1\": Весна\n" +
                "\"2\": Лето\n" +
                "\"3\": Осень\n" +
                "\"4\": Зима\n" +
                "\"5\": Хаос\n" +
                "\"6\": Мне повезёт!\n", ConsoleColor.Cyan);

            try
            {
                switch (Convert.ToByte(Console.ReadLine()))
                {
                    case 1:
                        return new ConsoleColor[] { ConsoleColor.Magenta, ConsoleColor.Green, ConsoleColor.Yellow };

                    case 2:
                        return new ConsoleColor[] { ConsoleColor.Red, ConsoleColor.Blue, ConsoleColor.Green, ConsoleColor.Yellow, };

                    case 3:
                        return new ConsoleColor[] { ConsoleColor.DarkRed, ConsoleColor.DarkYellow, ConsoleColor.Yellow };

                    case 4:
                        return new ConsoleColor[] { ConsoleColor.DarkBlue, ConsoleColor.Cyan, ConsoleColor.White };

                    case 5:
                        return (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));

                    case 6:
                        Random rnd = new Random();
                        var allColors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));
                        int num = rnd.Next(2, allColors.Length);
                        var colors = new ConsoleColor[num];

                        for (int i = 0; i < colors.Length; i++)
                        {
                            colors[i] = allColors[rnd.Next(0, allColors.Length)];
                        }
                        return colors;

                    default:
                        Message("\nОшибочка!\n", ConsoleColor.Red);
                        return ColorSwitcher();
                }
            }
            catch
            {
                Message("\nОшибочка!\n", ConsoleColor.Red);
                return ColorSwitcher();
            }
        }
    }
}
