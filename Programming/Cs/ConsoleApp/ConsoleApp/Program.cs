using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        public struct SType
        {
            public string Value; public int Next;
        }
        private static SType[] artSpace = new SType[10];

        static void Main(string[] args)
        {
            List<int> z = new List<int>(); z.Add(10); z.Add(20); z.Add(30); z.Add(40);

            
            //1
            for (int k = 0; k < z.Count; k++) z.RemoveAt(k); 
            //2
            //z.Clear();

            //3

            //for (int k = z.Count - 1; k >= 0; k--) z.RemoveAt(k); 
            //4

            //for (int k = z.Count - 1; z.Count > 0; k--) z.RemoveAt(k); 
            //5
            //foreach (int intNum in z)            z.RemoveAt(intNum);

            foreach (int intNum in z) Console.WriteLine(intNum);



        }

    }
}
