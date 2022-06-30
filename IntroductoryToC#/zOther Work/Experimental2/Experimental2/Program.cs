using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experimental2
{
    internal class Program
    {
        static int MapToRange(int n, int min, int max)
        {
            
            return (min + (n % ((max + 1) - min)));
        }
        
        static void Main(string[] args)
        {
            int numberSelection = 0;
            while (int.TryParse(Console.ReadLine(), out numberSelection) == false
                    || numberSelection < 0
                    || numberSelection >= 100)
            {
                Console.WriteLine("Conversion failed! Try again ) __ )");
            }
            int startNumber = 1;
            int endNumber = 100;
            Console.WriteLine(MapToRange(numberSelection, startNumber, endNumber));
            Console.WriteLine(MapToRange(44, 8, 23));

            for (int i = 0; i < 100; i++)
            {
                Console.WriteLine(MapToRange(i, 7, 33));
            }
        }
    }
}
