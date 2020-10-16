using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    class Program
    {
        public static int randomizer = 0; // Переменная, показывающая выбрана ли палитра "Мне повезёт!"
        static void Main(string[] args)
        {
            byte value; // Сторона квадрата
            string flag; // Проверка Goto
            ConsoleColor[,] kale; // Массив цветов калейдоскопа

            Message("Добро пожаловать в \" Калейдоскоп \" !\n", ConsoleColor.Yellow);
            System.Threading.Thread.Sleep(1000);
            Message("Выход: ", newLine: false);
            Message("\" Q \"", ConsoleColor.Red);
            Message("Выбрать цвет: ", newLine: false);
            Message("\" S \"", ConsoleColor.Red);
            System.Threading.Thread.Sleep(1300);

        ColorSelection: // Метка Goto

            Message("\nВыберите цвет:\n" +
                "\"1\": Весна\n" +
                "\"2\": Лето\n" +
                "\"3\": Осень\n" +
                "\"4\": Зима\n" +
                "\"5\": Хаос\n" +
                "\"6\": Мне повезёт!\n", ConsoleColor.Cyan);

            randomizer = 0;
            ConsoleColor[] colors = ColorSwitcher(); // Выбор цветов

            while (true)
            {
                Message("\nВведите половину стороны квадрата (от 3 до 20)\n", ConsoleColor.Cyan);
                flag = Console.ReadLine(); // Выбор действия или стороны квадрата

                // Проверка: выйти, изменить настройки цвета
                if (flag == "q" || flag == "Q")
                {
                    break;
                }
                else if (flag == "s" || flag == "S")
                {
                    goto ColorSelection; // Выбор цвета
                }

                try
                {
                    // Проверка на корректность условий ввода
                    value = Convert.ToByte(flag);

                    if (value < 3 || value > 20)
                    {
                        Message("\nОшибочка!\n", ConsoleColor.Red);
                    }
                    else
                    {
                        Console.WriteLine();
                        // Если выбрана палитра "Мне повезёт!", то цвета в ней меняются каждый цикл
                        if (randomizer == 1) colors = RandomColors();
                        // Создание квадрата цветов, отражение и печать
                        kale = Kaleidoscope(colors, value);
                        Mirror(kale);
                    }
                }
                catch
                {
                    Message("\nОшибочка!\n", ConsoleColor.Red);
                }
            }
            Console.WriteLine("\nВыход\n");
        }

        // Создание двумерного массива готового основного квадрата
        static ConsoleColor[,] Kaleidoscope(ConsoleColor[] colors, byte value) 
        {
            var arr = new ConsoleColor[value, value]; // Массив цветов заданного размера
            ConsoleColor color; // Текущий цвет элемента
            Random rnd = new Random();

            for (int i = 0; i < value; i++)
            {
                for (int j = 0 + i; j < value; j++)
                {
                    // Присвоение случайного цвета каждому элементу массива
                    color = colors[rnd.Next(0, colors.Length)];
                    arr[i, j] = color;
                    //color = colors[rnd.Next(0, colors.Length)]; // Опционально: ассиметрия основного квадрата
                    arr[j, i] = color;
                }
            }
            return arr;
        }

        // Создание и печать двумерного массива калейдоскопа цветов
        static void Mirror(ConsoleColor[,] picture)
        {
            int len = picture.GetLength(0); // Сторона основного квадрата
            var mirrSquare = new ConsoleColor[len * 2, len * 2]; // Массив нужного размера для калейдоскопа цветов
            int bigLen = mirrSquare.GetLength(0); // Сторона массива калейдоскопа
            int index = 0; // Итератор для foreach

            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    // Отражение основного квадрата во все стороны, заполнение массива калейдоскопа
                    mirrSquare[i, j] = picture[i, j];
                    mirrSquare[i, bigLen - (j + 1)] = picture[i, j];
                    mirrSquare[bigLen - (i + 1), j] = picture[i, j];
                    mirrSquare[bigLen - (i + 1), bigLen - (j + 1)] = picture[i, j];
                }
            }
            foreach (var color in mirrSquare)
            {
                // Поэлементная печать содержимого калеёдоскопа
                Console.BackgroundColor = color;
                Console.Write(" ");
                index++;

                // Условный переход на новую строку
                if (index % bigLen != 0) continue;

                Console.ResetColor();
                Console.WriteLine();
            }
        }

        // Печать сообщения с опциональным указанием цвета и перехода на новую строку
        static void Message(string message, ConsoleColor color = ConsoleColor.White, bool newLine = true)
        {
            Console.ResetColor();
            Console.ForegroundColor = color;
            Console.Write(message);
            if (newLine) Console.WriteLine();
            Console.ResetColor();
        }

        // Выбор цветовой гаммы
        static ConsoleColor[] ColorSwitcher()
        {
            byte n = new byte(); // Переменная выбора палитры

            try
            {
                if (randomizer == 0) n = Convert.ToByte(Console.ReadLine());
                // Если выбрана палитра "Мне повезёт!", то записываем это в глобальную переменную
                randomizer = (n == 6) ? 1 : 0;

                switch (n)
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
                        return (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor)); // Все цвета

                    case 6:
                        return RandomColors();

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

        // Случайные цвета, случайное количество цветов
        static ConsoleColor[] RandomColors()
        {
            Random rnd = new Random();
            var allColors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor)); // Все цвета
            int num = rnd.Next(2, allColors.Length); // Случайное число (не более количества цветов)
            var colors = new ConsoleColor[num]; // Массив цветов случайного размера

            // Заполнение массива цветов случайными цветами
            for (int i = 0; i < colors.Length; i++)
            {
                colors[i] = allColors[rnd.Next(0, allColors.Length)];
            }
            return colors;
        }
    }
}
