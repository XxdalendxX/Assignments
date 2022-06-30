using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experimental001
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("String And User Input...");            
            StringAndUserInput();            
        }

         static void StringAndUserInput()
        {
            string name = "Simon";

            string complementingDialogue = "\"Nice!\" exclaimed Simon";

            string tautology = "The Person is either " + name + " or not " + name;

            Console.WriteLine("input sentence");

            int characterAsHex = Console.Read();

            string fullSentence = Console.ReadLine();

            Console.WriteLine("input keycode");

            char singleCharacter = Console.ReadKey().KeyChar;

            Console.WriteLine(name);
            Console.WriteLine(complementingDialogue);
            Console.WriteLine(tautology);
            Console.WriteLine(characterAsHex);
            Console.WriteLine(fullSentence);
            Console.WriteLine(singleCharacter);

            Scope();
        }

        static void Scope()
        {
            Console.WriteLine("Scope And Functions...");
            ;
        }
    }
}
