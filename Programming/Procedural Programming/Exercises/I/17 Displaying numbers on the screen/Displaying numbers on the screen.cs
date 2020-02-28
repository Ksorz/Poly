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
            int N;
            while (true)
                {
                Console.WriteLine("Введите целое положительное число:");
                try
                {
                    N = Convert.ToInt32(Console.ReadLine());
                    break;
                }
                catch
                {
                    Console.WriteLine("Ошибочка!");
                    continue;
                }
                }
            

            for (int i = 1; i <= N; i++)
            {
                Console.Write(i);
                Console.Write(' ');
                if (i % 10 == 0) Console.WriteLine();
            }
        }
    }
}
