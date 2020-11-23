using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {

        public static Tuple<string, string> StringValues(string one, string two, string three)
        {
            string strOne, strTwo;

            int fir = String.Compare(three, one);
            int thr = String.Compare(one, two);

            
            if (fir > 0) strOne = three;
            else strOne = one;

            if (strOne == three & thr > 0) strTwo = one;
            else strTwo = two;


            return Tuple.Create(strOne, strTwo);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Заполните три строки для сравнения");
            string strOne = Console.ReadLine();
            string strTwo = Console.ReadLine();
            string strThr = Console.ReadLine();
            Console.WriteLine("\nНаибольшие значения строк:");
            Console.WriteLine(StringValues(strOne, strTwo, strThr));
        }
    }
}
