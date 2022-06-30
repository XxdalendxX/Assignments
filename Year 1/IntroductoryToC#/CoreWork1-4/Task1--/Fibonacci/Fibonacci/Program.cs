using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fibonacci
{
    class Program
    {
        
        
        static void Main(string[] args)
        {
            //assign value for fMax that works as the limit to the fibonacci sequence.
            Console.WriteLine("Input a positive value");
            int fMax = Convert.ToInt32(Console.ReadLine());
            int f = 2;
            int a = 0;
            int b = 1;
            int c;
            //provides outcomes for the various integer inputs the user can provide
            if (fMax <= 0)
            {
                Console.WriteLine();
                Console.WriteLine("Unable to Calculate");
            }
            if (fMax == 1)
            {
                Console.WriteLine();
                Console.Write("(0)");
            }
            if (fMax == 2)
            {
                Console.WriteLine();
                Console.Write("(0 , ");
                Console.Write("1");
            }
            if (fMax >= 3)
            {
                Console.WriteLine();
                Console.Write("(0 , ");
                Console.Write("1");
                while (f < fMax)
                {
                    //formula that allows the fibonacci sequence to continue through a addition and substitution method
                    Console.Write(" , ");
                    c = a + b;
                    Console.Write(c);
                    a = b;
                    b = c;
                    f++;
                }
            }
            Console.WriteLine(")");
            Console.Write("Press ENTER to exit");
            Console.ReadLine();
        }
    }
}
