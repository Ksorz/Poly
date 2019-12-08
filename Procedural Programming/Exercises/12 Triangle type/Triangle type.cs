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
            Console.WriteLine("Введите три стороны треугольника:");
            double x = Convert.ToDouble(Console.ReadLine());
            double y = Convert.ToDouble(Console.ReadLine());
            double z = Convert.ToDouble(Console.ReadLine());

            if (x == y && y == z)
            {
                Console.WriteLine("Равносторонний");
            }
            else if (x + y <= z || x + z <= y || y + z <= x)
            { 
                Console.WriteLine("Невозможный");
            }
            else if (x == y || x == z || y == z)
            {
                Console.WriteLine("Равнобедренный");
            }
            else
            {
                Console.WriteLine("Разносторонний");
            }
        }
    }
}
