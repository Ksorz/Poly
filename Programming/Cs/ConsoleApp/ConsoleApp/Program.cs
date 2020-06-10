using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime;
using System.Runtime.InteropServices;
using System.IO;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string strѕ = "  Пусть бегут неуклюже";
            string strRes;


            strRes = strѕ.Trim().Substring(6, 3);
            Console.WriteLine(strRes);
        }
    }
}
