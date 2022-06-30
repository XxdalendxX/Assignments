using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayTask1
{
    internal class Program
    {
        static int AddNumbers(int[] numbers)
        {
            //formula function that can work interchangably with values provided in main function array and return the sum
            int sum = 0;
            foreach(int i in numbers)
            {
                sum = i + sum;
            }
            return sum;
        }

        static void Main(string[] args)
        {
            
            //checks to see if an interger value has been input into the console and applied to integer "element"
            int element = 0;
            while (element <= 0)
            {
                Console.WriteLine("please input a positive integer value");
                element = Convert.ToInt32(Console.ReadLine());
                if (element > 0)
                {

                }
                else
                {
                    Console.Clear();
                    Console.WriteLine("Invalid input...");
                }
            }
            int[] array1 = new int[element];
            //a for loop that checks and applies integers input by the player into the array
            for(int i = 0; i < element; i++)
            {
                bool applied = false;
                while (applied == false)
                {
                    int k;
                    Console.WriteLine("please input an integer value for array position " + i);
                    k = Convert.ToInt32(Console.ReadLine());
                    if (k <= 0 || k >
                        0)
                    {
                        applied = true;
                        Console.Clear();
                    }
                    else
                    {
                        Console.Clear();
                        Console.WriteLine("Invalid input...");
                    }
                    array1[i] = k;
                }
            }
            int sum = AddNumbers(array1);
            //prints the sum out in the console
            Console.WriteLine(sum);
            Console.WriteLine("press any button to exit program");
            Console.ReadKey();
        }
    }
}
