using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AlphabetizedFile
{
    internal class Program
    {
        static void Alphabet(string[] text)
        {
            //formula function that works with any string array
            //formula tests sets of 2 variables and swaps in regards to alphabetical order
            //upon reaching the arrays end, formula will check if any changes were made and repeat if it did
            bool swap = true;
            int count = 0;

            while (swap == true)
            {
                for (int word = 0; word < text.Length - 1; word++)
                {
                    if (string.Compare(text[word], text[word+1]) > 0)
                    {
                        string Placeholder;
                        count++;
                        Placeholder = text[word];
                        text[word] = text[word + 1];
                        text[word + 1] = Placeholder;
                    }

                }

                if (count == 0)
                {
                    swap = false;
                }
                count = 0;
            }

            //will write the arranged array into a new .txt document
            StreamWriter writer;
            writer = new StreamWriter("Output.txt");
            foreach (string word in text)
            {
                writer.WriteLine(word);
            }
            writer.Close();
        }

        static void Main(string[] args)
        {
            int element;


            //reads .txt document and assigns first line as an int variable for the array
            StreamReader reading = new
            StreamReader("Words.txt");
            int.TryParse(reading.ReadLine(), out element);
            string[] wording = new string[element];

            //establishes array that is to be sent to the formula function for arranging/sorting
            for (int i = 0; i < element; i++ )
            {
                wording[i] = reading.ReadLine();
            }

            reading.Close();

            Alphabet(wording);

            //reads and writes arranged array into the console to show that the array has changed
            StreamReader reader;
            reader = new StreamReader("Output.txt");
            while (reader.EndOfStream == false)
            {
                string line = reader.ReadLine();
                Console.WriteLine(line);
            }
        }
    }
}
