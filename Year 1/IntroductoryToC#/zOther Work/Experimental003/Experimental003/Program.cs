using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experimental003
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string a = "Apple", b = "banana", c = "apple";

            Console.WriteLine(string.Compare(c, b));
            Console.WriteLine(string.Compare(b, a));
            Console.WriteLine(string.Compare(a, c));

        }
    }
}
