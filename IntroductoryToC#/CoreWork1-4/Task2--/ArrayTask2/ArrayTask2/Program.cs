using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayTask2
{
    internal class Program
    {
        static void SortDescending(int[] numbers)
        {
            //formula function that works interchangably with one dimentional arrays inputted into the function
            bool swap = true;
            int count = 0;

            //will continue to work so long as bool is true
            while(swap == true)
            {
                for (int i = 0; i < numbers.Length - 1; i++)
                {
                    //for every value being looked at, every change adds 1 to the count and will run until it reaches the end of the array
                    if (numbers[i] < numbers[i+1])
                    {
                        int Placeholder;
                        count++;
                        Placeholder = numbers[i + 1];
                        numbers[i + 1] = numbers[i];
                        numbers[i] = Placeholder;
                    }
                   
                }

                //testing to see if any swaps has occured and if count > 0, then the while loop will repeat
                if (count == 0)
                {
                    swap = false;
                }
                count = 0;
            }
            
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
            int[] Descent = new int[element];

            //a for loop that checks and applies integers input by the player into the array
            for (int i = 0; i < element; i++)
            {
                bool applied = false;
                while (applied == false)
                {
                    int k;
                    Console.WriteLine("please input an integer value for array position " + i);
                    k = Convert.ToInt32(Console.ReadLine());
                    if (k <= 0 || k > 0)
                    {
                        applied = true;
                        Console.Clear();
                    }
                    else
                    {
                        Console.Clear();
                        Console.WriteLine("Invalid input...");
                    }
                    Descent[i] = k;
                }
            }

            SortDescending(Descent);

            //will write out each value in order on one line upon formula function completion
            foreach (int i in Descent)
            {
                Console.Write(" " + i + " ");
            }
            Console.WriteLine();
            Console.WriteLine("press any button to exit program");
            Console.ReadKey();
        }
    }
}
