using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 0;
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Чтобы выйти, введите '0'");
            Console.ResetColor();
            while (true)
            {
                try
                {
                    Console.WriteLine("Введите целое двузначное число:");
                    number = Convert.ToInt32(Console.ReadLine());
                }
                catch
                {
                    Console.WriteLine("Вы ошиблись");
                }
                if (number < 10 & number > -10)
                {
                    if (number == 0)
                    {
                        Console.WriteLine("Выход");
                        break;
                    }
                    Console.WriteLine("Вы ошиблись");
                    continue;
                }
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("\n" + SwichTwoNumsMath(number));
                Console.WriteLine(SwichTwoNumsString(number));
                Console.ResetColor();
            }
        }

        static string SwichTwoNumsString(int number)
        {
            int sw1, sw2;
            int count = CountDigits(number);
            TwoRandInNum(count, out sw1, out sw2);

            string numberStr = Convert.ToString(number), result;
            result = ReplaceCharInString(numberStr, sw1 - 1, numberStr[sw2 - 1]);
            result = ReplaceCharInString(result, sw2 - 1, numberStr[sw1 - 1]);

            return result;
        }

        static string ReplaceCharInString(string source, int index, char newSymb)
        {
            return source.Remove(index, 1).Insert(index, newSymb.ToString());
        }

        static int SwichTwoNumsMath(int number)
        {
            int sw1, sw2, result;
            int count = CountDigits(number);
            TwoRandInNum(count, out sw1, out sw2);
            int fir = number / (int)Math.Pow(10, count - sw1) % 10;
            int sec = number / (int)Math.Pow(10, count - sw2) % 10;
            int x = (int)Math.Pow(10, count - sw1) * fir + (int)Math.Pow(10, count - sw2) * sec;
            int y = (int)Math.Pow(10, count - sw1) * sec + (int)Math.Pow(10, count - sw2) * fir;

            result = number - x + y;

            return result;
        }

        static int CountDigits(int number)
        {
            int result = (int) Math.Ceiling(Math.Log10(Math.Abs(number)));
            return result;
        }

        static void TwoRandInNum(int range, out int rFir, out int rSec)
        {
            Random rnd = new Random();
            int y, x = rnd.Next(1, range + 1);

            do
            {
                y = rnd.Next(1, range + 1);
            }
            while (x == y);

            rFir = x;
            rSec = y;
        }
    }
}
