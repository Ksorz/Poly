using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int rows = 12;
            int nums = 9;
            int heig = 8;

            Trees(rows, nums, heig);
        }
        static void Trees(int rows, int number, int height, char treeBlock = '$', char space = '.')
        {
            for (int r = 0; r < rows; r++)
            {
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine(new string(space, (height * 2) * number + 1));

                for (int h = 0; h < height; h++)
                {
                    int width = (height * 2 - 1) / 2 + 1;
                    Console.Write(space);
                    for (int n = 0; n < number; n++)
                    {
                        
                        Console.Write(new string(space, width - h - 1));
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write(new string(treeBlock, 1 + h * 2));
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write(new string(space, width - h));
                    }
                    Console.WriteLine();
                }
                Console.Write(space);
                for (int n = 0; n < number; n++)
                {
                    Console.Write(new string(space, (height * 2 - 1) / 2));
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write(treeBlock);
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write(new string(space, (height * 2 - 1) / 2 + 1));
                }
                Console.WriteLine();
            }
            Console.WriteLine(new string(space, (height * 2) * number + 1));
        }
    }
}
