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
        public static string cgarFolder = "+";
        public static string cgarFile = "-";
        public static int gap = 3;
        public static int count = 0;

        static void Main(string[] args)
        {
            char[] x = { 'a', 'A', '1' };
            Dictionary<string, int> openWith = new Dictionary<string, int>();


            Show("C:\\Program Files (x86)\\Steam", x);
            
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("===========================================================");
            Console.WriteLine(count);
            Console.ReadLine();


        }
        static void Show(string path, char[] charCount, string space = " ")
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(space + cgarFolder + Path.GetFileName(path));
            Console.ForegroundColor = ConsoleColor.White;
            space = space + new string(' ', gap);

            foreach (string file in Directory.GetFiles(path))
            {
                string name = Path.GetFileName(path);
                Console.WriteLine(space + cgarFile + name);
                if (charCount != null)
                {
                    foreach (int i in charCount)
                        if (name[0] == i) count++;
                }
            }
                
            foreach (string direct in Directory.GetDirectories(path))
                Show(direct, charCount, space);
        }
    }
}
