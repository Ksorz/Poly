using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        class Program
        {
            private static string DigToStr(int n)
            {
                switch (n)
                {
                    case 0: return "";
                    case 1: return "один";
                    case 2: return "два";
                    case 3: return "три";
                    case 4: return "четыре";
                    case 5: return "пять";
                    case 6: return "шесть";
                    case 7: return "семь";
                    case 8: return "восемь";
                    case 9: return "девять";
                    default:
                        throw new IndexOutOfRangeException(String.Format("ошибка"));
                }
            }
            private static string TeenToStr(int n)
            {
                switch (n)
                {
                    case 10: return "десять";
                    case 11: return "одиннадцать";
                    case 12: return "двенадцать";
                    case 13: return "тринадцать";
                    case 14: return "четырнадцать";
                    case 15: return "пятнадцать";
                    case 16: return "шестнадцать";
                    case 17: return "семнадцать";
                    case 18: return "восемнадцать";
                    case 19: return "девятнадцать";
                    default:
                        throw new IndexOutOfRangeException(String.Format("ошибка"));
                }
            }
            private static string HiTeenToStr(int n)
            {
                int tensDigit = (int)(Math.Floor((double)n / 10.0));

                string tensStr;
                switch (tensDigit)
                {
                    case 2: tensStr = "двадцать"; break;
                    case 3: tensStr = "тридцать"; break;
                    case 4: tensStr = "сорок"; break;
                    case 5: tensStr = "пятьдесят"; break;
                    case 6: tensStr = "шестьдесят"; break;
                    case 7: tensStr = "семьдесят"; break;
                    case 8: tensStr = "восемьдесят"; break;
                    case 9: tensStr = "девяносто"; break;
                    default:
                        throw new IndexOutOfRangeException(String.Format("ошибка"));
                } 
                if (n % 10 == 0) return tensStr;
                string onesStr = DigToStr(n - tensDigit * 10);
                return tensStr + " " + onesStr;
            }

            static void Main(string[] args)
            {
                int inputInteger = 0;
                string outputString;
                while (inputInteger < 1 || inputInteger > 99)
                {
                    Console.WriteLine("Введите число от 1 до 99:");
                    
                    try
                    {
                        inputInteger = Convert.ToInt32(Console.ReadLine());
                    }
                    catch
                    {
                        Console.WriteLine("Вы ошиблись");
                        continue;
                    }
                    if (inputInteger > 99 || inputInteger < 1) Console.WriteLine("Вы ошиблись");
                }

                if (inputInteger < 10) outputString = DigToStr(inputInteger);
                else if (inputInteger < 20) outputString = TeenToStr(inputInteger);
                else outputString = HiTeenToStr(inputInteger);

                outputString = outputString.Substring(0, 1).ToUpper() + outputString.Remove(0, 1);

                Console.WriteLine(outputString);
            }
        }
    }
}
