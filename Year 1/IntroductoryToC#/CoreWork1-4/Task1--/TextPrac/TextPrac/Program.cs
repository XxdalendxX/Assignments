using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace TextPrac
{
    internal class Program
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

        static int AddNumbers(float a, float b)
        {
            //function containing the formula that will add and floor the float variables provided and return the result
            int c = Convert.ToInt32(Math.Floor(a + b));
            return c;
        }
        
        static void Main(string[] args)
        {
            //choice system that branches into any one of the 3 tasks
            Console.WriteLine("Hello User, what is your name?");
            string UserName = Console.ReadLine();
            Console.WriteLine("Hello " + UserName + "! Please select an exercise.");
            Console.WriteLine("1 --> Addition of Two Numbers");
            Console.WriteLine("2 --> Fibonacci Sequence");
            Console.WriteLine("3 --> FizzBuzz");
            int choice = Convert.ToInt32(Console.ReadLine());


            if (choice == 1)
            {
               //apply 2 numbers assigned by the user and send to related function
                Console.WriteLine("Please input your first number.");
                float a = Convert.ToSingle(Console.ReadLine());
                Console.WriteLine("Input your second number.");
                float b = Convert.ToSingle(Console.ReadLine());
                
                
                int c = AddNumbers(a, b);
                
                //conditional statement that provides "c" in 3 different outcome related to the number 10
                if (c > 10)
                {
                    Console.WriteLine("Sum of values is greater than 10 and equals " + c);
                }
                else if (c < 10)
                {
                    Console.WriteLine("Sum of values is less than 10 and equals " + c);
                }
                else
                {
                    Console.WriteLine("Values sum to 10!");
                }
                Console.Write("Press ENTER to exit");
                Console.ReadLine();

            }
                

            if (choice == 2)
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

            if (choice == 3)
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
}
