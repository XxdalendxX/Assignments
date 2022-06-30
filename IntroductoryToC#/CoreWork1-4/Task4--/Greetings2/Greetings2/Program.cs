using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Greetings2
{
    class Person
    {
        //establishing the primary class type creating variables common across it and the secondary class type
        //default constructor in the event that no information is given
        public Person()
        {
            name = "Blindsight Barry"; Mobile = 5550143; Email = "n / a";
        }
        //custom constructor where new information can be given and applied
        public Person(string pname, int pMobile, string pEmail)
        {
            name = pname; Mobile = pMobile; Email = pEmail;
        }
        public string name;
        public int Mobile;
        public string Email;

        //primary SayGreeting functionthat Person follows by
        public virtual void SayGreeting()
        {
            Console.WriteLine("Hello, I'm " + name + ",");
            Console.WriteLine("My Mobile is " + Mobile + ",");
            Console.WriteLine("and my Email is " + Email + ".");
        }

    }

    class Doctor : Person
    {
        //a relative carbon copy of the primary class type following the same as the Person class while being supplied by it
        //added a salary string for Doctor that makes it stand out.
        public Doctor()
        {
            salary = "420k anually";
        }
        public Doctor(string dname, int dMobile, string dEmail, string dsalary) : base(dname, dMobile, dEmail)
        {
            salary = dsalary;
        }
        public string salary;

        //secondary SayGreeting function used by Doctor that includes salary and additional discourse to the name component
        public override void SayGreeting()
        {
            Console.WriteLine("Hello, I'm Dr. " + name + ",");
            Console.WriteLine("My Mobile is " + Mobile + ",");
            Console.WriteLine("my Email is " + Email + ",");
            Console.WriteLine("and my salary is " + salary + ".");
        }

    }

    internal class Program
    {
        static void Main(string[] args)
        {
            //establishing an integer for an array that will be created from the "personel" text document
            int element;

            
            StreamReader reading = new
            StreamReader("Personel.txt");
            int.TryParse(reading.ReadLine(), out element);
            Person[] people = new Person[element];
            for (int i = 0; i < element; i++)
            {
                //establish parameter components that is used in the creation of the array components
                string a = "";
                int b = 0;
                string c = "";
                string d = "";

                a = reading.ReadLine();
                int.TryParse(reading.ReadLine(), out b);
                c = reading.ReadLine();
                d = reading.ReadLine();
                Person person;
                //a for loop to produce array components differing in class type then reading the complete array
                if (i % 2 == 0)
                {
                    person = new Doctor(a, b, c, d);  
                }
                else
                {
                    person = new Person(a, b, c);
                }
                person.SayGreeting();
                Console.WriteLine();
                reading.ReadLine();

                people[i] = person;
            }

        }
    }
}
