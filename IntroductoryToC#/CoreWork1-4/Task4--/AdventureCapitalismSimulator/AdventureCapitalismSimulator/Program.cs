using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntityGen;
using WorldGen;
using ItemGen;

namespace AdventureCapitalismSimulator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //establishes the map array and assigns them
            Room[,] map = new Room[3, 3];

            for (int row = 0; row < 3; row++)
            {

                for (int col = 0; col < 3; col++)
                {

                    map[row, col] = new Room();

                }

            }



            //game parameters for the unique rooms/spaces
            player p = new player();

            enemy e = new enemy(10, 27, 6);

            PowerUp pu = new PowerUp();


            //creates and removes unique spaces/rooms
            map[1, 1].AddGameObject(p);

            map[1, 1].AddGameObject(e);

            map[1, 1].RemoveGameObject(p);

            map[2, 0].AddGameObject(e);

            map[0, 1].AddGameObject(pu);



            for (int row = 0; row < 3; row++)
            {

                for (int col = 0; col < 3; col++)
                {

                    map[row, col].Draw();

                }

                Console.WriteLine();

            }
            

            Console.WriteLine();

            Console.ReadLine();
        }
    }
}
