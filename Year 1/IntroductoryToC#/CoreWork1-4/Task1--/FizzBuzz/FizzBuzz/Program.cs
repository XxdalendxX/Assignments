using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzz
{
    class Program
    {
        static void FizzBuzz(int nMAX)
        {
            //A positive integer formula of the fizzbuzz function.
            int n = 0;
            if (nMAX > 0 && n <= nMAX)
            {
                n++;
                Console.WriteLine();
            }
            while (nMAX > 0 && n <= nMAX)
            {
                if (n % 3 == 0 && n % 5 != 0)
                {
                    Console.WriteLine("Fizz");
                    n++;
                }
                else if (n % 5 == 0 && n % 3 != 0)
                {
                    Console.WriteLine("Buzz");
                    n++;
                }
                else if (n % 3 == 0 && n % 5 == 0)
                {
                    Console.WriteLine("FizzBuzz");
                    n++;
                }
                else if (n % 3 != 0 && n % 5 != 0)
                {
                    //writes each outcome as code continues
                    Console.WriteLine(n);
                    n++;
                }
            }
            //A negative integer formula of the fizzbuzz function 
            if (nMAX < 0 && nMAX <= n)
            {
                n--;

            }
            while (nMAX < 0 && nMAX <= n)
            {
                Console.WriteLine();
                if (nMAX % 3 == 0 && nMAX % 5 != 0)
                {
                    Console.WriteLine("Fizz");
                    nMAX++;
                }
                else if (nMAX % 5 == 0 && nMAX % 3 != 0)
                {
                    Console.WriteLine("Buzz");
                    nMAX++;
                }
                else if (nMAX % 3 == 0 && nMAX % 5 == 0)
                {
                    Console.WriteLine("FizzBuzz");
                    nMAX++;
                }
                else if (nMAX % 3 != 0 && nMAX % 5 != 0)
                {
                    //writes each outcome as code continues
                    Console.WriteLine(nMAX);
                    nMAX++;
                }
            }
        }

        static void Main(string[] args)
        {
            //allows user to input an integer value for use in the fizzbuzz function
            Console.WriteLine("Please input a value");
            int nMAX = Convert.ToInt32(Console.ReadLine());
            FizzBuzz(nMAX);
            Console.Write("Press ENTER to exit");
            Console.ReadLine();
        }
    }
}
