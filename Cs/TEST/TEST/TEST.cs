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
            bool blnA = false;
            bool blnB = true;
            bool blnC = false;
            blnC = blnC ^ !(blnA == blnB);
            Console.WriteLine(blnC);

        }
        
    }
}
