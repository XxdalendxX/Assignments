using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Greetings
{
    class Person
    {
        public Person()
        {
            name = "Blindsight Barry"; Mobile = 5550143; Email = "n / a";
        }
        public Person(string pname, int pMobile, string pEmail)
        {
            name = pname; Mobile = pMobile; Email = pEmail; 
        }
        public string name;
        public int Mobile;
        public string Email;
        
        public virtual void SayGreeting()
        {
            Console.WriteLine("Hello, I'm " + name + ",");
            Console.WriteLine("My Mobile is " + Mobile + "," );
            Console.WriteLine("and my Email is " + Email + ".");
        }

    }

    class Doctor: Person
    {
       public Doctor()
        {
            salary = "420k anually";
        }
        public Doctor(string dname, int dMobile, string dEmail,string dsalary) : base(dname, dMobile, dEmail)
        {
            salary = dsalary;
        }
        public string salary;

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
            
            Person person = new Person("hindsight harold", 5550187, "see!tC0m!nG@hotmail.com.edu.au.vic.gov.com");
            Doctor doctor = new Doctor("hindsight harold", 5550187, "see!tC0m!nG@hotmail.com.edu.au.vic.gov.com", "200k anually");
            Doctor doc = new Doctor();


            doc.SayGreeting();
            Console.WriteLine();
            person.SayGreeting();
            Console.WriteLine();
            doctor.SayGreeting();
            








            return;
            StreamReader reading = new
            StreamReader("Personel.txt");
            reading.ReadLine();
            while (reading.EndOfStream == false)
            {
                reading.ReadLine();
                person.name = reading.ReadLine();
                int.TryParse(reading.ReadLine(), out person.Mobile);
                person.Email = reading.ReadLine();

                if (person.name.Contains("Dr.") == true)
                {
                    doctor.salary = reading.ReadLine();
                }
                

                if (person.name.Contains("Dr.") == true)
                {
                    doctor.SayGreeting();
                }
                else
                {
                    person.SayGreeting();
                }


                Console.WriteLine(person.name);
                Console.WriteLine(person.Mobile);
                Console.WriteLine(person.Email);
                if (person.name.Contains("Dr.") == true)
                {
                    Console.WriteLine(doctor.salary);
                }
            }
        }
    }
}
