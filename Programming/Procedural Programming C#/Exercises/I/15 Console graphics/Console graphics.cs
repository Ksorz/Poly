using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        public static void Tree(int K, int N)
        {
            for (int i = 1, j = 1; i <= K; i++, j += 2)
            {
                for (int k = 1; k <= N; k++)
                {
                    Console.Write(new string(' ', K - i));
                    Console.Write(new string('#', j));
                    Console.Write(new string(' ', K - i + 1));
                }
                Console.WriteLine();
            }
            for (; N > 0; N--)
            {
                Console.Write(new string(' ', K - 1));
                Console.Write('#');
                Console.Write(new string(' ', K));
            }
            Console.WriteLine('\n');
        }
        static void Main(string[] args)
        {
            int M = 5, N = 7, K = 5;

            for (; M > 0; M--)
            {
                Tree(K, N);
            }
            
        }
    }
}
