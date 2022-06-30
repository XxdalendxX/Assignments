using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AddNumbers
{
    class Program
    {

        static int AddNumbers(float a, float b)
        {
            //function containing the formula that will add and floor the float variables provided and return the result
            int c = Convert.ToInt32(Math.Floor(a + b));
            return c;
        }
        static void Main(string[] args)
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
    }
}
