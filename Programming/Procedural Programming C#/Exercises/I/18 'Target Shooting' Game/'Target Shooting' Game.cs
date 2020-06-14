using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        public static Random rand = new Random();
        public static int sleep = 100; // Задержка перед обновлением координат
        public static int maxScore = 10; // Размер мишени
        

        static void Main(string[] args)
        {
            double x, y;
            int shots = 5; // Количество выстрелов в игре
            int totalScore = 0; // Общий счёт
            int index = 1;

            Console.WriteLine("У ВАС ЕСТЬ " + shots + " ВЫСТРЕЛОВ, ПОПРОБУЙТЕ НАБРАТЬ МАКСИМУМ ОЧКОВ!");
            while (index <= shots)
            {
                Console.WriteLine("\nГотовьтесь целиться по оси Х");
                Console.WriteLine("Нажмите любую клавишу чтобы начать\nЗатем любую клавишу, чтобы остановиться\n");
                Console.ReadKey(true);
                if (index != 1) Console.ReadKey(true); // Для задержки перед выстрелом в консоли

                x = Aim();

                Console.WriteLine("\nГотовьтесь целиться по оси Y");
                Console.WriteLine("Нажмите любую клавишу чтобы начать\nЗатем любую клавишу, чтобы остановиться\n");
                Console.ReadKey(true);
                Console.ReadKey(true); // Для задержки перед выстрелом в консоли

                y = Aim();

                double shot = Math.Sqrt((x * x) + (y * y)); // вычисление нашего радиуса (относительно прицеливания)
                int points = Convert.ToInt32(Math.Ceiling(maxScore - shot)); //вычисление очков

                if (points > 0) totalScore += points;
                else points = 0;

                Console.WriteLine("\nX = " + x + " Y = " + y + "\nВы попали в точку " + shot + "\nВы набрали " + points + " очков");
                Console.WriteLine("У вас " + totalScore + " очков!");

                index++;
            }

            if (totalScore == maxScore * shots) Console.WriteLine("\nВы настоящий снайпер!");
            else if (totalScore > maxScore * shots * 0.7) Console.WriteLine("Хороший результат!\n");
            else if (totalScore > maxScore * shots * 0.4) Console.WriteLine("Есть куда стремиться!\n");
            else Console.WriteLine("Может, в следующий раз...\n");

        }
        public static double Aim(double n = 0, int i = 1)
        {
            n += rand.Next(0, maxScore); // Запуск прицеливания со случайной позиции на мишени

            while (!Console.KeyAvailable)
            {
                if (i % 2 == 0) n += rand.NextDouble();
                else n -= rand.NextDouble();
                
                if (n >= maxScore)
                {
                    n = maxScore - rand.NextDouble();
                    i++;
                }
                else if (n <= 0)
                {
                    n = 0 + rand.NextDouble();
                    i++;
                }

                Console.WriteLine(n);
                System.Threading.Thread.Sleep(sleep);
            }
            return n;
        }
    }
}
